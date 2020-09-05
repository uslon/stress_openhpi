//
// Created by amir on 31.08.2020.
//

#include <atomic>
#include <thread>
#include <vector>

#include "Diversity_0.h"

#include "OneFunctionTests/saHpiDiscover.h"
#include "OneFunctionTests/saHpiDomainInfoGet.h"

namespace ns_Diversity {
}

std::string Diversity_0::getTestName() {
    return "Diversity_0";
}

void Diversity_0::runTest() {
    const int workers_cnt = 20;
    const int workers_types = 2;

    std::atomic_int workers_finished(0);
    std::vector <std::thread> workers;
    workers.reserve(workers_cnt);
    for (int i = 0; i < workers_cnt / workers_types; ++i) {
        workers.emplace_back(ns_saHpiDiscover::worker, std::ref(workers_finished));
        workers.emplace_back(ns_saHpiDomainInfoGet::worker, std::ref(workers_finished));
    }

    do {
        updateMemory();
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    } while (workers_finished.load() < workers_cnt);

    for (auto&& worker: workers) {
        worker.join();
    }
}
