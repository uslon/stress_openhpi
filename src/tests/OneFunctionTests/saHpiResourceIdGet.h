//
// Created by amir on 31.08.2020.
//

#ifndef STRESS_OPENHPI_SAHPIRESOURCEIDGET_H
#define STRESS_OPENHPI_SAHPIRESOURCEIDGET_H

#include "BaseTestCase.h"

class saHpiResourceIdGet : public BaseTestCase {
private:
    std::string getTestName() final;

    void runTest() final;
};


#endif //STRESS_OPENHPI_SAHPIRESOURCEIDGET_H
