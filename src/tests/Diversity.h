//
// Created by amir on 31.08.2020.
//

#ifndef STRESS_OPENHPI_DIVERSITY_H
#define STRESS_OPENHPI_DIVERSITY_H

#include "TestCase.h"

class Diversity : public TestCase {
private:
    std::string getTestName() final;

    void runTest() final;
};


#endif //STRESS_OPENHPI_DIVERSITY_H
