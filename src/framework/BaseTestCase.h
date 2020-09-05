//
// Created by amir on 21.08.2020.
//

#ifndef STRESS_OPENHPI_BASETESTCASE_H
#define STRESS_OPENHPI_BASETESTCASE_H

#include <atomic>
#include <iostream>
#include <list>

typedef void (*worker_t)(std::atomic_int&);

class BaseTestCase {
public:
    BaseTestCase();

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

    void assertPass();

    void assertFail();

    void runWorkers(worker_t worker);

    void runWorkers(std::list<worker_t>& workers_types);
};

#endif //STRESS_OPENHPI_BASETESTCASE_H
