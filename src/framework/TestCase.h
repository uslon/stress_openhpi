//
// Created by amir on 21.08.2020.
//

#ifndef STRESS_OPENHPI_TESTCASE_H
#define STRESS_OPENHPI_TESTCASE_H

#include <iostream>

class TestCase {
public:
    TestCase();

    void execute(std::ostream& out);

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
    void saveReport(std::ostream& out);

    std::string getTestState();

    virtual std::string getTestName() = 0;

    virtual void runTest() = 0;

protected:
    void updateMemory();
};

#endif //STRESS_OPENHPI_TESTCASE_H
