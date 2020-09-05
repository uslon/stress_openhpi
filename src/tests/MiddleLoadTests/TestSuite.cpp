//
// Created by amir on 05.09.2020.
//

#include "TestSuite.h"

#include "MiddleLoad.h"

namespace ns_MiddleLoadTests {

    TestSuite::TestSuite() {
        addTest(std::make_unique <MiddleLoad>());
    }

} // ns_MiddleLoadTests