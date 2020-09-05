//
// Created by amir on 21.08.2020.
//

#ifndef STRESS_OPENHPI_SAHPIDRTENTRYGET_H
#define STRESS_OPENHPI_SAHPIDRTENTRYGET_H

#include <BaseTestCase.h>

namespace ns_saHpiDrtEntryGet {
    void worker(std::atomic_int &workers_finished);
}

class saHpiDrtEntryGet : public BaseTestCase {
private:
    std::string getTestName() final;

    void runTest() final;
};


#endif //STRESS_OPENHPI_SAHPIDRTENTRYGET_H
