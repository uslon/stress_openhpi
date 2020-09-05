//
// Created by amir on 31.08.2020.
//

#include <atomic>
#include <thread>
#include <vector>

#include "wrapSaHpi.h"

#include "saHpiDiscover.h"

namespace ns_saHpiDiscover {
    void worker(std::atomic_int& workers_finished) {
        SaHpiSessionIdT session_id;
        SaErrorT rv;
        rv = saHpiSessionOpen(SAHPI_UNSPECIFIED_DOMAIN_ID, &session_id, NULL);
        if (rv != SA_OK) {
            std::cerr << "Couldn't open session" << std::endl;
            exit(EXIT_FAILURE);
        }

        const int times_to_ask_query = 256 * 1024;
        for (int i = 1; i <= times_to_ask_query; ++i) {
            saHpiDiscover(session_id);
        }

        workers_finished.fetch_add(1);
    }
}

std::string saHpiDiscover::getTestName() {
    return "saHpiDiscover";
}

void saHpiDiscover::runTest() {
    runWorkers(ns_saHpiDiscover::worker);
}
