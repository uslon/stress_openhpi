//
// Created by amir on 04.09.2020.
//

#ifndef STRESS_OPENHPI_WORKERSHUB_H
#define STRESS_OPENHPI_WORKERSHUB_H

#include <atomic>

namespace ns_Workers {
    void worker_0 (std::atomic_int& workers_finished);
    void worker_1 (std::atomic_int& workers_finished);
    void worker_2 (std::atomic_int& workers_finished);
    void worker_3 (std::atomic_int& workers_finished);
    void worker_4 (std::atomic_int& workers_finished);
    void worker_5 (std::atomic_int& workers_finished);
    void worker_6 (std::atomic_int& workers_finished);
    void worker_7 (std::atomic_int& workers_finished);
}

class WorkersHub {

};


#endif //STRESS_OPENHPI_WORKERSHUB_H
