//
// Created by amir on 20.08.2020.
//

#ifndef STRESS_OPENHPI_BASETESTSUITE_H
#define STRESS_OPENHPI_BASETESTSUITE_H

#include <list>
#include <memory>

#include "BaseTestCase.h"

class BaseTestSuite {
public:
    BaseTestSuite() = default;

    void addTest(std::unique_ptr <BaseTestCase> test_case);

    void addTestSuite(std::unique_ptr <BaseTestSuite> test_suite);

    void executeTests(std::ostream& out);

private:
    std::list <std::unique_ptr <BaseTestCase> > tests_;

};
#endif //STRESS_OPENHPI_BASETESTSUITE_H
