//
// Created by amir on 05.09.2020.
//

#include "RootTestSuite.h"

#include "DiversityTests/TestSuite.h"
#include "MiddleLoadTests/TestSuite.h"
#include "OneFunctionTests/TestSuite.h"

RootTestSuite::RootTestSuite() {
    addTestSuite(std::make_unique <ns_DiversityTests::TestSuite>());
    addTestSuite(std::make_unique <ns_MiddleLoadTests::TestSuite>());
    addTestSuite(std::make_unique <ns_OneFunctionTests::TestSuite>());
}
