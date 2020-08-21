//
// Created by amir on 21.08.2020.
//

#ifndef STRESS_OPENHPI_SAHPIDRTENTRYGET_H
#define STRESS_OPENHPI_SAHPIDRTENTRYGET_H

#include <TestCase.h>

class saHpiDrtEntryGet : public TestCase {
private:
    std::string getTestName() final;

    void runTest() final;
};


#endif //STRESS_OPENHPI_SAHPIDRTENTRYGET_H
