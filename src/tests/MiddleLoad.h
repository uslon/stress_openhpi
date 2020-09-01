//
// Created by amir on 01.09.2020.
//

#ifndef STRESS_OPENHPI_MIDDLELOAD_H
#define STRESS_OPENHPI_MIDDLELOAD_H

#include "TestCase.h"

class MiddleLoad : public TestCase {
private:
    std::string getTestName() final;

    void runTest() final;
};


#endif //STRESS_OPENHPI_MIDDLELOAD_H
