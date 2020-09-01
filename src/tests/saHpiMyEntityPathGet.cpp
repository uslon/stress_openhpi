//
// Created by amir on 21.08.2020.
//

#include <atomic>
#include <thread>
#include <vector>

#include "saHpiMyEntityPathGet.h"
#include "wrapSaHpi.h"

namespace ns_saHpiMyEntityPathGet {
    void worker(std::atomic_int& workers_finished) {
        SaHpiSessionIdT session_id;
        SaErrorT rv;
        rv = saHpiSessionOpen(SAHPI_UNSPECIFIED_DOMAIN_ID, &session_id, NULL);
        if (rv != SA_OK) {
            std::cerr << "Couldn't open session" << std::endl;
            exit(EXIT_FAILURE);
        }

        SaHpiEntityPathT entity_path;
        const int times_to_ask_query = 256 * 1024;
        for (int i = 1; i <= times_to_ask_query; ++i) {
            rv = saHpiMyEntityPathGet(session_id, &entity_path);
        }

        workers_finished.fetch_add(1);
    }
}

std::string saHpiMyEntityPathGet::getTestName() {
    return "saHpiMyEntityPathGet";
}


void saHpiMyEntityPathGet::runTest() {
    runWorkers(ns_saHpiMyEntityPathGet::worker);
}

