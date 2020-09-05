//
// Created by amir on 31.08.2020.
//

#include <atomic>
#include <thread>

#include "saHpiResourceIdGet.h"
#include "wrapSaHpi.h"

namespace ns_saHpiResourceIdGet {
    void worker(std::atomic_int& workers_finished) {
        SaHpiSessionIdT session_id;
        SaErrorT rv;
        rv = saHpiSessionOpen(SAHPI_UNSPECIFIED_DOMAIN_ID, &session_id, NULL);
        if (rv != SA_OK) {
            std::cerr << "Couldn't open session" << std::endl;
            exit(EXIT_FAILURE);
        }


        SaHpiResourceIdT resource_id;
        const int times_to_ask_query = 256 * 1024;
        for (int i = 1; i <= times_to_ask_query; ++i) {
            saHpiResourceIdGet(session_id, &resource_id);
        }

        workers_finished.fetch_add(1);
    }
}

std::string saHpiResourceIdGet::getTestName() {
    return "saHpiResourceIdGet";
}

void saHpiResourceIdGet::runTest() {
    runWorkers(ns_saHpiResourceIdGet::worker);
}
