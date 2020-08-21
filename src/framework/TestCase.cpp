//
// Created by amir on 21.08.2020.
//

#include <iomanip>

#include "TestCase.h"

extern "C" {
#include "getCPUTime.h"
#include "getMemoryUsage.h"
}

const int times_to_run = 2;

void TestCase::execute(std::ostream &out) {
    std::cout << "Executing " << getTestName() << " ..." << std::endl;
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
    saveReport(std::cout);
    if (out) {
        saveReport(out);
    }
}

void TestCase::saveReport(std::ostream &out) {
    out << "Test case: " << getTestName() << '\n'
        << "Test status: " << getTestState() << '\n'
        << "CPU time: " << std::fixed << std::setprecision(4)
        << cpu_time_ << " sec.\n"
        << "Memory used: " << memory_used_ << " kb.\n"
        << "------------------------------" << std::endl;
}

void TestCase::updateMemory() {
    int current_memory = getMemoryUsage(getpid());
    memory_used_ = std::max(memory_used_, current_memory);
}

std::string TestCase::getTestState() {
    if (test_state_ == pass) {
        return "PASS";
    } else if (test_state_ == fail) {
        return "FAIL";
    } else {
        return "UNKNOWN";
    }
}

TestCase::TestCase(): test_state_(unknown), cpu_time_(0), memory_used_(0) {
}
