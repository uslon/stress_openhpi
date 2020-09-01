//
// Created by amir on 21.08.2020.
//

#ifndef STRESS_OPENHPI_TESTCASE_H
#define STRESS_OPENHPI_TESTCASE_H

#include <atomic>
#include <iostream>

class TestCase {
public:
    TestCase();

    void launch(std::ostream& out);

private:
    typedef enum {
        pass,
        fail,
        unknown
    } State;

private:
    State test_state_;
    double cpu_time_;

protected:
    int memory_used_;

private:
    void execute(double *cpu_time_shared, int *memory_used_shared);

    void saveReport(std::ostream& out);

    std::string getTestState();

    virtual std::string getTestName() = 0;

    virtual void runTest() = 0;

protected:
    void updateMemory();

    void runWorkers(void (* worker)(std::atomic_int&));

    void assertPass();

    void assertFail();
};

#endif //STRESS_OPENHPI_TESTCASE_H
