//
// Created by amir on 31.08.2020.
//

#ifndef STRESS_OPENHPI_SAHPIDISCOVER_H
#define STRESS_OPENHPI_SAHPIDISCOVER_H

#include "BaseTestCase.h"

namespace ns_saHpiDiscover {
    void worker(std::atomic_int& workers_finished);
}

class saHpiDiscover : public BaseTestCase {
private:
    std::string getTestName() final;

    void runTest() final;
};


#endif //STRESS_OPENHPI_SAHPIDISCOVER_H
