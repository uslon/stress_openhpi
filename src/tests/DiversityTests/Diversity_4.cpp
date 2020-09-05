//
// Created by amir on 04.09.2020.
//

#include "Diversity_4.h"

#include <list>

#include "WorkersHub.h"

std::string Diversity_4::getTestName() {
    return "Diversity-4";
}

void Diversity_4::runTest() {
    std::list <worker_t> workers_types;
    workers_types.push_back(ns_Workers::worker_4);
    workers_types.push_back(ns_Workers::worker_3);
    workers_types.push_back(ns_Workers::worker_5);
    workers_types.push_back(ns_Workers::worker_2);
    runWorkers(workers_types);
}
