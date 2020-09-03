//
// Created by amir on 20.08.2020.
//

#include "TestSuite.h"

#include "Diversity_0.h"
#include "Diversity_1.h"
#include "Diversity_2.h"
#include "Diversity_3.h"

#include "MiddleLoad.h"

#include "saHpiDiscover.h"
#include "saHpiDomainInfoGet.h"
#include "saHpiDrtEntryGet.h"
#include "saHpiEventLogInfoGet.h"
#include "saHpiMyEntityPathGet.h"
#include "saHpiResourceIdGet.h"
#include "saHpiRptEntryGet.h"

TestSuite::TestSuite() {
    addTest(std::make_unique <saHpiDomainInfoGet>());
    addTest(std::make_unique <saHpiDrtEntryGet>());
    addTest(std::make_unique <saHpiMyEntityPathGet>());
    addTest(std::make_unique <saHpiResourceIdGet>());
    addTest(std::make_unique <saHpiRptEntryGet>());
    addTest(std::make_unique <saHpiEventLogInfoGet>());
    addTest(std::make_unique <saHpiDiscover>());

    addTest(std::make_unique <Diversity_0>());
    addTest(std::make_unique <Diversity_1>());
    addTest(std::make_unique <Diversity_2>());
    addTest(std::make_unique <Diversity_3>());

    addTest(std::make_unique <MiddleLoad>());
}

void TestSuite::addTest(std::unique_ptr<TestCase> test_case) {
    tests_.push_back(std::move(test_case));
}

void TestSuite::executeTests(std::ostream& out) {
    for (auto&& test: tests_) {
        test->launch(out);
    }
}
