//
// Created by amir on 04.09.2020.
//

#ifndef STRESS_OPENHPI_DIVERSITY_3_H
#define STRESS_OPENHPI_DIVERSITY_3_H

#include "TestCase.h"

class Diversity_3 : public TestCase {
private:
    std::string getTestName() final;

    void runTest() final;
};


#endif //STRESS_OPENHPI_DIVERSITY_2_H