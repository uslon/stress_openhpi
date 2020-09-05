//
// Created by amir on 21.08.2020.
//


#include <csignal>
#include <iomanip>
#include <list>
#include <thread>
#include <vector>

#include "BaseTestCase.h"

extern "C" {
#include "getCPUTime.h"
#include "getMemoryUsage.h"

#include <sys/mman.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
}

const int times_to_run = 2;

void BaseTestCase::launch(std::ostream &out) {
    int prot = PROT_READ | PROT_WRITE;
    int flags = MAP_ANONYMOUS | MAP_SHARED;
    double *cpu_time_shared = (double *)mmap(NULL, sizeof(double), prot, flags, -1, 0);
    int *memory_used_shared = (int *)mmap(NULL, sizeof(int), prot, flags, -1, 0);



    // launch process for clients
    int clients_pid = fork();
    if (clients_pid == 0) { /* child */
        execute(cpu_time_shared, memory_used_shared);
        exit(EXIT_SUCCESS);
    }

    waitpid(clients_pid, NULL, 0);

    cpu_time_ = *cpu_time_shared;
    memory_used_ = *memory_used_shared;

    saveReport(std::cout);
    if (out) {
        saveReport(out);
    }
}

void BaseTestCase::saveReport(std::ostream &out) {
    out << "Test case: " << getTestName() << '\n'
        // << "Test status: " << getTestState() << '\n'
        << "CPU time: " << std::fixed << std::setprecision(4)
        << cpu_time_ << " sec.\n"
        << "Memory used: " << memory_used_ << " kb.\n"
        << "------------------------------" << std::endl;
}

void BaseTestCase::updateMemory() {
    int current_memory = getMemoryUsage();
    memory_used_ = std::max(memory_used_, current_memory);
}

std::string BaseTestCase::getTestState() {
    if (test_state_ == pass) {
        return "PASS";
    } else if (test_state_ == fail) {
        return "FAIL";
    } else {
        return "UNKNOWN";
    }
}

BaseTestCase::BaseTestCase(): test_state_(unknown), cpu_time_(0), memory_used_(0) {
}

void BaseTestCase::execute(double *cpu_time_shared, int *memory_used_shared) {
    std::cout << "Executing " << getTestName() << "..." << std::endl;
    int times_run = 0;
    double total_cpu_time = 0;
    double start_time, end_time;

    do {
        start_time = getCPUTime();
        runTest();
        end_time = getCPUTime();

        ++times_run;
        total_cpu_time += end_time - start_time;
    } while (times_run < times_to_run);

    cpu_time_ = total_cpu_time / times_run;

    *cpu_time_shared = cpu_time_;
    *memory_used_shared = memory_used_;
}


void BaseTestCase::runWorkers(worker_t worker) {
    const int workers_cnt = 20;
    std::vector <std::thread> workers;
    workers.reserve(workers_cnt);
    std::atomic_int workers_finished(0);

    for (int i = 0; i < workers_cnt; ++i) {
        workers.emplace_back(worker, std::ref(workers_finished));
    }

    do {
        updateMemory();
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    } while (workers_finished.load() < workers_cnt);

    for (int i = 0; i < workers_cnt; ++i) {
        workers[i].join();
    }
}


void BaseTestCase::runWorkers(std::list <worker_t>& workers_types) {
    const int workers_cnt = 20;
    std::vector <std::thread> workers;
    workers.reserve(workers_cnt);
    std::atomic_int workers_finished(0);
    std::list <int> lst;

    for (int i = 0; i < workers_cnt / workers_types.size(); ++i) {
        for (auto worker: workers_types) {
            workers.emplace_back(worker, std::ref(workers_finished));
        }
    }

    do {
        updateMemory();
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    } while (workers_finished.load() < workers_cnt);

    for (int i = 0; i < workers_cnt; ++i) {
        workers[i].join();
    }
}

void BaseTestCase::assertPass() {
    if (test_state_ == unknown) {
        test_state_ = pass;
    }
}

void BaseTestCase::assertFail() {
    test_state_ = fail;
}
