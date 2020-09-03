//
// Created by amir on 31.08.2020.
//

#ifndef STRESS_OPENHPI_SAHPIEVENTLOGINFOGET_H
#define STRESS_OPENHPI_SAHPIEVENTLOGINFOGET_H

#include "TestCase.h"

namespace ns_saHpiEventLogInfoGet {
    void worker(std::atomic_int &workers_finished);
}

class saHpiEventLogInfoGet : public TestCase {
private:
    std::string getTestName() final;

    void runTest() final;
};


#endif //STRESS_OPENHPI_SAHPIEVENTLOGINFOGET_H
