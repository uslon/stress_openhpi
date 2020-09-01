//
// Created by amir on 21.08.2020.
//

#include <atomic>
#include <thread>
#include <vector>

#include "saHpiDomainInfoGet.h"
#include "wrapSaHpi.h"

namespace ns_saHpiDomainInfoGet {
    void worker(std::atomic_int& workers_finished) {
        SaHpiSessionIdT session_id;
        SaErrorT rv;
        rv = saHpiSessionOpen(SAHPI_UNSPECIFIED_DOMAIN_ID, &session_id, NULL);
        if (rv != SA_OK) {
            std::cerr << "Couldn't open session" << std::endl;
            exit(EXIT_FAILURE);
        }

        SaHpiDomainInfoT domain_info;
        const int times_to_ask_query = 256 * 1024;
        for (int i = 1; i <= times_to_ask_query; ++i) {
            rv = saHpiDomainInfoGet(session_id, &domain_info);
        }

        workers_finished.fetch_add(1);
    }
}


std::string saHpiDomainInfoGet::getTestName() {
    return "saHpiDomainInfoGet";
}


void saHpiDomainInfoGet::runTest() {
    runWorkers(ns_saHpiDomainInfoGet::worker);
}