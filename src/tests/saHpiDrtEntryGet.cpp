//
// Created by amir on 21.08.2020.
//

#include <atomic>
#include <thread>
#include <vector>

#include "saHpiDrtEntryGet.h"
#include "wrapSaHpi.h"

namespace ns_saHpiDrtEntryGet {
    void worker(std::atomic_int& workers_finished) {
        SaHpiSessionIdT session_id;
        SaErrorT rv;
        rv = saHpiSessionOpen(SAHPI_UNSPECIFIED_DOMAIN_ID, &session_id, NULL);
        if (rv != SA_OK) {
            std::cerr << "Couldn't open session" << std::endl;
            exit(EXIT_FAILURE);
        }

        SaHpiDrtEntryT drt_entry;
        SaHpiEntryIdT entry_id;
        const int times_to_ask_query = 256 * 1024;
        for (int i = 1; i <= times_to_ask_query; ++i) {
            rv = saHpiDrtEntryGet(session_id, SAHPI_FIRST_ENTRY, &entry_id, &drt_entry);
        }

        workers_finished.fetch_add(1);
    }
}

std::string saHpiDrtEntryGet::getTestName() {
    return "saHpiDrtEntryGet";
}


void saHpiDrtEntryGet::runTest() {
    runWorkers(ns_saHpiDrtEntryGet::worker);
}

