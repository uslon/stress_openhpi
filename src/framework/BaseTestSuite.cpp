//
// Created by amir on 20.08.2020.
//

#include "BaseTestSuite.h"

void BaseTestSuite::addTest(std::unique_ptr<BaseTestCase> test_case) {
    tests_.push_back(std::move(test_case));
}

void BaseTestSuite::executeTests(std::ostream& out) {
    for (auto&& test: tests_) {
        test->launch(out);
    }
}

void BaseTestSuite::addTestSuite(std::unique_ptr<BaseTestSuite> test_suite) {
    std::move(test_suite->tests_.begin(), test_suite->tests_.end(), std::back_inserter(tests_));
}
