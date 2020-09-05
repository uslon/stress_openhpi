//
// Created by amir on 01.09.2020.
//

#include "MiddleLoad.h"

#include <atomic>
#include <thread>
#include <vector>

#include "wrapSaHpi.h"

namespace ns_MiddleLoad {
    void hpiDiscover(std::atomic_int& workers_finished) {
        SaHpiSessionIdT session_id;
        SaErrorT rv;
        rv = saHpiSessionOpen(SAHPI_UNSPECIFIED_DOMAIN_ID, &session_id, NULL);
        if (rv != SA_OK) {
            std::cerr << "Couldn't open session" << std::endl;
            exit(EXIT_FAILURE);
        }

        const int times_to_ask_query = 64 * 1024;
        for (int i = 0; i < times_to_ask_query; ++i) {
            rv = saHpiDiscover(session_id);
            std::this_thread::sleep_for(std::chrono::microseconds(100));
        }

        workers_finished.fetch_add(1);
    }

    void hpiDomainInfoGet(std::atomic_int& workers_finished) {
        SaHpiSessionIdT session_id;
        SaErrorT rv;
        rv = saHpiSessionOpen(SAHPI_UNSPECIFIED_DOMAIN_ID, &session_id, NULL);
        if (rv != SA_OK) {
            std::cerr << "Couldn't open session" << std::endl;
            exit(EXIT_FAILURE);
        }

        SaHpiDomainInfoT domain_info;
        const int times_to_ask_query = 64 * 1024;
        for (int i = 0; i < times_to_ask_query; ++i) {
            rv = saHpiDomainInfoGet(session_id, &domain_info);
            std::this_thread::sleep_for(std::chrono::microseconds(100));
        }

        workers_finished.fetch_add(1);
    }
}

std::string MiddleLoad::getTestName() {
    return "MiddleLoad";
}

void MiddleLoad::runTest() {
    const int workers_cnt = 20;
    const int workers_types = 2;

    std::atomic_int workers_finished(0);
    std::vector <std::thread> workers;
    workers.reserve(workers_cnt);
    for (int i = 0; i < workers_cnt / workers_types; ++i) {
        workers.emplace_back(ns_MiddleLoad::hpiDiscover, std::ref(workers_finished));
        workers.emplace_back(ns_MiddleLoad::hpiDomainInfoGet, std::ref(workers_finished));
    }

    do {
        updateMemory();
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    } while (workers_finished.load() < workers_cnt);

    for (auto&& worker: workers) {
        worker.join();
    }
}
