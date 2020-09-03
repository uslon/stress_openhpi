//
// Created by amir on 04.09.2020.
//

#ifndef STRESS_OPENHPI_DIVERSITY_1_H
#define STRESS_OPENHPI_DIVERSITY_1_H

#include "TestCase.h"

class Diversity_1 : public TestCase {
private:
    std::string getTestName() final;

    void runTest() final;
};


#endif //STRESS_OPENHPI_DIVERSITY_1_H
