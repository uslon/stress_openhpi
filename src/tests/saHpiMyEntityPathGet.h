//
// Created by amir on 21.08.2020.
//

#ifndef STRESS_OPENHPI_SAHPIMYENTITYPATHGET_H
#define STRESS_OPENHPI_SAHPIMYENTITYPATHGET_H

#include "TestCase.h"

class saHpiMyEntityPathGet : public TestCase {
private:
    std::string getTestName() final;

    void runTest() final;
};


#endif //STRESS_OPENHPI_SAHPIMYENTITYPATHGET_H
