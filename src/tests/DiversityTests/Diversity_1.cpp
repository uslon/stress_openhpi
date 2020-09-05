//
// Created by amir on 04.09.2020.
//

#include "Diversity_1.h"

#include <list>

#include "OneFunctionTests/saHpiDiscover.h"
#include "OneFunctionTests/saHpiDomainInfoGet.h"
#include "OneFunctionTests/saHpiDrtEntryGet.h"
#include "OneFunctionTests/saHpiEventLogInfoGet.h"


std::string Diversity_1::getTestName() {
    return "Diversity_0-1";
}

void Diversity_1::runTest() {
    std::list <worker_t> workers_types;
    workers_types.push_back(ns_saHpiDomainInfoGet::worker);
    workers_types.push_back(ns_saHpiDiscover::worker);
    workers_types.push_back(ns_saHpiDrtEntryGet::worker);
    workers_types.push_back(ns_saHpiEventLogInfoGet::worker);
    runWorkers(workers_types);
}
