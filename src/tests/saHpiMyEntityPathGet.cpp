//
// Created by amir on 21.08.2020.
//

#include <thread>
#include <vector>

#include "saHpiMyEntityPathGet.h"
#include "wrapSaHpi.h"

namespace ns_saHpiMyEntityPathGet {
    void worker() {
        SaHpiSessionIdT session_id;
        SaErrorT rv;
        rv = saHpiSessionOpen(SAHPI_UNSPECIFIED_DOMAIN_ID, &session_id, NULL);
        if (rv != SA_OK) {
            std::cerr << "Couldn't open session" << std::endl;
            exit(EXIT_FAILURE);
        }

        SaHpiEntityPathT entity_path;
        const int times_to_ask_query = 32 * 1024;
        for (int i = 1; i <= times_to_ask_query; ++i) {
            rv = saHpiMyEntityPathGet(session_id, &entity_path);
        }
    }
}

std::string saHpiMyEntityPathGet::getTestName() {
    return "saHpiMyEntityPathGet";
}


void saHpiMyEntityPathGet::runTest() {
    const int workers_cnt = 20;
    std::vector <std::thread> workers;
    workers.reserve(workers_cnt);

    for (int i = 0; i < workers_cnt; ++i) {
        workers.push_back(std::thread(ns_saHpiMyEntityPathGet::worker));
    }
    updateMemory();

    for (int i = 0; i < workers_cnt; ++i) {
        workers[i].join();
    }
}

