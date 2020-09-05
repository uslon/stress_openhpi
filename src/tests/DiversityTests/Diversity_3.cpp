//
// Created by amir on 04.09.2020.
//

#include "Diversity_3.h"

#include <list>

#include "WorkersHub.h"


std::string Diversity_3::getTestName() {
    return "Diversity-3";
}

void Diversity_3::runTest() {
    std::list <worker_t> workers_types;
    workers_types.push_back(ns_Workers::worker_4);
    workers_types.push_back(ns_Workers::worker_5);
    workers_types.push_back(ns_Workers::worker_6);
    workers_types.push_back(ns_Workers::worker_7);
    runWorkers(workers_types);
}
