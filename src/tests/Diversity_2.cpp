//
// Created by amir on 04.09.2020.
//

#include "Diversity_2.h"

#include <list>

#include "WorkersHub.h"


std::string Diversity_2::getTestName() {
    return "Diversity-2";
}

void Diversity_2::runTest() {
    std::list <worker_t> workers_types;
    workers_types.push_back(ns_Workers::worker_0);
    workers_types.push_back(ns_Workers::worker_1);
    workers_types.push_back(ns_Workers::worker_2);
    workers_types.push_back(ns_Workers::worker_3);
    runWorkers(workers_types);
}
