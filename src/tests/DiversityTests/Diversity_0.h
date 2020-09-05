//
// Created by amir on 31.08.2020.
//

#ifndef STRESS_OPENHPI_DIVERSITY_0_H
#define STRESS_OPENHPI_DIVERSITY_0_H

#include "BaseTestCase.h"

class Diversity_0 : public BaseTestCase {
private:
    std::string getTestName() final;

    void runTest() final;
};


#endif //STRESS_OPENHPI_DIVERSITY_0_H
