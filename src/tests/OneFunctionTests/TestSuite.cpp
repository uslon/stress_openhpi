//
// Created by amir on 05.09.2020.
//

#include "TestSuite.h"

#include "saHpiDiscover.h"
#include "saHpiDomainInfoGet.h"
#include "saHpiDrtEntryGet.h"
#include "saHpiEventLogInfoGet.h"
#include "saHpiMyEntityPathGet.h"
#include "saHpiResourceIdGet.h"
#include "saHpiRptEntryGet.h"

namespace ns_OneFunctionTests {

    TestSuite::TestSuite() {
        addTest(std::make_unique <saHpiDiscover>());
        addTest(std::make_unique <saHpiDomainInfoGet>());
        addTest(std::make_unique <saHpiDrtEntryGet>());
        addTest(std::make_unique <saHpiEventLogInfoGet>());
        addTest(std::make_unique <saHpiMyEntityPathGet>());
        addTest(std::make_unique <saHpiResourceIdGet>());
        addTest(std::make_unique <saHpiRptEntryGet>());
    }
} // ns_OneFunctionTests
