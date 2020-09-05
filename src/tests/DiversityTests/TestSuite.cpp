//
// Created by amir on 05.09.2020.
//

#include "TestSuite.h"

#include "Diversity_0.h"
#include "Diversity_1.h"
#include "Diversity_2.h"
#include "Diversity_3.h"
#include "Diversity_4.h"

namespace ns_DiversityTests {

    TestSuite::TestSuite() {
        addTest(std::make_unique <Diversity_0>());
        addTest(std::make_unique <Diversity_1>());
        addTest(std::make_unique <Diversity_2>());
        addTest(std::make_unique <Diversity_3>());
        addTest(std::make_unique <Diversity_4>());
    }

} // ns_DiversityTests
