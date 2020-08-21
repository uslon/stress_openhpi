//
// Created by amir on 21.08.2020.
//

#include "getMemoryUsage.h"

#include <fcntl.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int getMemoryUsage(int pid) {
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
