//
// Created by amir on 21.08.2020.
//

#include "getMemoryUsage.h"

#include <fcntl.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int parseLine(char* line){
    // This assumes that a digit will be found and the line ends in " Kb".
    int i = strlen(line);
    const char* p = line;
    while (*p <'0' || *p > '9') p++;
    line[i-3] = '\0';
    i = atoi(p);
    return i;
}

int getRAM() { //Note: this value is in KB!
    FILE* file = fopen("/proc/self/status", "r");
    int result = -1;
    char line[128];

    while (fgets(line, 128, file) != NULL){
        if (strncmp(line, "VmRSS:", 6) == 0){
            result = parseLine(line);
            break;
        }
    }
    fclose(file);
    return result;
}

int getVM(){ //Note: this value is in KB!
    FILE* file = fopen("/proc/self/status", "r");
    int result = -1;
    char line[128];

    while (fgets(line, 128, file) != NULL){
        if (strncmp(line, "VmSize:", 7) == 0){
            result = parseLine(line);
            break;
        }
    }
    fclose(file);
    return result;
}


int getMemoryUsage() {
    return getRAM() + getVM();
}

/* Old version of getMemoryUsage
int getMemoryUsage(int pid) {
    return getRAM() + getVM();
    int fd, data, stack;
    char buf[4096], status_child[NAME_MAX];
    char *vm;

    sprintf(status_child, "/proc/%d/status", pid);
    if ((fd = open(status_child, O_RDONLY)) < 0)
        return -1;

    read(fd, buf, 4095);
    buf[4095] = '\0';
    close(fd);

    data = stack = 0;

    vm = strstr(buf, "VmData:");
    if (vm) {
        sscanf(vm, "%*s %d", &data);
    }

    vm = strstr(buf, "VmStk:");
    if (vm) {
        sscanf(vm, "%*s %d", &stack);
    }

    return data + stack;
}
*/

