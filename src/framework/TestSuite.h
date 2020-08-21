//
// Created by amir on 20.08.2020.
//

#ifndef STRESS_OPENHPI_TESTSUITE_H
#define STRESS_OPENHPI_TESTSUITE_H

#include <list>
#include <memory>

#include "TestCase.h"

class TestSuite {
public:
    TestSuite();

    void addTest(std::unique_ptr <TestCase> test_case);

    void executeTests(std::ostream& out);

private:
    std::list <std::unique_ptr <TestCase> > tests_;

};
#endif //STRESS_OPENHPI_TESTSUITE_H
