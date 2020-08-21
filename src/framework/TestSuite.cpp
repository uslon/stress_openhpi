//
// Created by amir on 20.08.2020.
//

#include "TestSuite.h"

#include "saHpiDomainInfoGet.h"
#include "saHpiDrtEntryGet.h"
#include "saHpiMyEntityPathGet.h"

TestSuite::TestSuite() {
    addTest(std::make_unique <saHpiDomainInfoGet>());
    addTest(std::make_unique <saHpiDrtEntryGet>());
    addTest(std::make_unique <saHpiMyEntityPathGet>());
}

void TestSuite::addTest(std::unique_ptr<TestCase> test_case) {
    tests_.push_back(std::move(test_case));
}

void TestSuite::executeTests(std::ostream& out) {
    for (auto&& test: tests_) {
        test->execute(out);
    }
}
