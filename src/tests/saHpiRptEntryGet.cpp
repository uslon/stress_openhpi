//
// Created by amir on 31.08.2020.
//

#include <atomic>
#include <thread>
#include <vector>

#include "saHpiRptEntryGet.h"
#include "wrapSaHpi.h"

namespace ns_saHpiRptEntryGet {
    void worker(std::atomic_int& workers_finished) {
        SaHpiSessionIdT session_id;
        SaErrorT rv;
        rv = saHpiSessionOpen(SAHPI_UNSPECIFIED_DOMAIN_ID, &session_id, NULL);
        if (rv != SA_OK) {
            std::cerr << "Couldn't open session" << std::endl;
            exit(EXIT_FAILURE);
        }


        SaHpiEntryIdT entry;
        SaHpiRptEntryT rpt_entry;
        const int times_to_ask_query = 256 * 1024;
        for (int i = 1; i <= times_to_ask_query; ++i) {
            saHpiRptEntryGet(session_id, SAHPI_ENTRY_UNSPECIFIED, &entry, &rpt_entry);
        }

        workers_finished.fetch_add(1);
    }
}

std::string saHpiRptEntryGet::getTestName() {
    return "saHpiRptEntryGet";
}

void saHpiRptEntryGet::runTest() {
    runWorkers(ns_saHpiRptEntryGet::worker);
}
