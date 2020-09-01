//
// Created by amir on 20.08.2020.
//

#include "TestSuite.h"

#include "Diversity.h"
#include "MiddleLoad.h"

#include "saHpiDiscover.h"
#include "saHpiDomainInfoGet.h"
#include "saHpiDrtEntryGet.h"
#include "saHpiEventLogInfoGet.h"
#include "saHpiMyEntityPathGet.h"
#include "saHpiResourceIdGet.h"
#include "saHpiRptEntryGet.h"

TestSuite::TestSuite() {
    addTest(std::make_unique <Diversity>());
    addTest(std::make_unique <MiddleLoad>());
    addTest(std::make_unique <saHpiDomainInfoGet>());
    addTest(std::make_unique <saHpiDrtEntryGet>());
    addTest(std::make_unique <saHpiMyEntityPathGet>());
    addTest(std::make_unique <saHpiResourceIdGet>());
    addTest(std::make_unique <saHpiRptEntryGet>());
    addTest(std::make_unique <saHpiEventLogInfoGet>());
    addTest(std::make_unique <saHpiDiscover>());
}

void TestSuite::addTest(std::unique_ptr<TestCase> test_case) {
    tests_.push_back(std::move(test_case));
}

void TestSuite::executeTests(std::ostream& out) {
    for (auto&& test: tests_) {
        test->launch(out);
    }
}
