//
// Created by amir on 04.09.2020.
//

#include "WorkersHub.h"

#include <atomic>
#include <iostream>
#include <thread>

#include <wrapSaHpi.h>

namespace ns_Workers {
    void worker_0 (std::atomic_int& workers_finished) {
        SaHpiSessionIdT session_id;
        SaErrorT rv;
        rv = saHpiSessionOpen(SAHPI_UNSPECIFIED_DOMAIN_ID, &session_id, NULL);
        if (rv != SA_OK) {
            std::cerr << "Couldn't open session" << std::endl;
            exit(EXIT_FAILURE);
        }

        SaHpiDrtEntryT drt_entry;
        SaHpiEntryIdT entry_id;
        SaHpiEventLogInfoT info;
        SaHpiResourceIdT resource_id = 0;
        const int times_to_ask_query = 32 * 1024;
        for (int i = 1; i <= times_to_ask_query; ++i) {
            rv = saHpiDrtEntryGet(session_id, SAHPI_FIRST_ENTRY, &entry_id, &drt_entry);
            std::this_thread::sleep_for(std::chrono::microseconds(100));
            rv = saHpiEventLogInfoGet(session_id, resource_id, &info);
            std::this_thread::sleep_for(std::chrono::microseconds(100));
        }

        workers_finished.fetch_add(1);
    }

    void worker_1 (std::atomic_int& workers_finished) {
        SaHpiSessionIdT session_id;
        SaErrorT rv;
        rv = saHpiSessionOpen(SAHPI_UNSPECIFIED_DOMAIN_ID, &session_id, NULL);
        if (rv != SA_OK) {
            std::cerr << "Couldn't open session" << std::endl;
            exit(EXIT_FAILURE);
        }

        SaHpiEventLogInfoT info;
        SaHpiResourceIdT resource_id = 0;
        const int times_to_ask_query = 64 * 1024;
        for (int i = 1; i <= times_to_ask_query; ++i) {
            rv = saHpiEventLogInfoGet(session_id, resource_id, &info);
            std::this_thread::sleep_for(std::chrono::microseconds(100));
        }

        workers_finished.fetch_add(1);
    }

    void worker_2 (std::atomic_int& workers_finished) {
        SaHpiSessionIdT session_id;
        SaErrorT rv;
        rv = saHpiSessionOpen(SAHPI_UNSPECIFIED_DOMAIN_ID, &session_id, NULL);
        if (rv != SA_OK) {
            std::cerr << "Couldn't open session" << std::endl;
            exit(EXIT_FAILURE);
        }

        SaHpiDomainInfoT domain_info;
        SaHpiEventLogInfoT info;
        SaHpiResourceIdT resource_id = 0;
        const int times_to_ask_query = 32 * 1024;
        for (int i = 1; i <= times_to_ask_query; ++i) {
            rv = saHpiDomainInfoGet(session_id, &domain_info);
            std::this_thread::sleep_for(std::chrono::microseconds(100));
            rv = saHpiEventLogInfoGet(session_id, resource_id, &info);
            std::this_thread::sleep_for(std::chrono::microseconds(100));
        }

        workers_finished.fetch_add(1);
    }

    void worker_3 (std::atomic_int& workers_finished) {
        SaHpiSessionIdT session_id;
        SaErrorT rv;
        rv = saHpiSessionOpen(SAHPI_UNSPECIFIED_DOMAIN_ID, &session_id, NULL);
        if (rv != SA_OK) {
            std::cerr << "Couldn't open session" << std::endl;
            exit(EXIT_FAILURE);
        }

        SaHpiDomainInfoT domain_info;
        SaHpiEventLogInfoT info;
        SaHpiResourceIdT resource_id = 0;
        const int times_to_ask_query = 16 * 1024;
        for (int i = 1; i <= times_to_ask_query; ++i) {
            rv = saHpiDiscover(session_id);
            std::this_thread::sleep_for(std::chrono::microseconds(100));
            rv = saHpiDomainInfoGet(session_id, &domain_info);
            std::this_thread::sleep_for(std::chrono::microseconds(100));
            rv = saHpiDiscover(session_id);
            std::this_thread::sleep_for(std::chrono::microseconds(100));
            rv = saHpiEventLogInfoGet(session_id, resource_id, &info);
            std::this_thread::sleep_for(std::chrono::microseconds(100));
        }

        workers_finished.fetch_add(1);
    }

    void worker_4 (std::atomic_int& workers_finished) {
        SaHpiSessionIdT session_id;
        SaErrorT rv;
        rv = saHpiSessionOpen(SAHPI_UNSPECIFIED_DOMAIN_ID, &session_id, NULL);
        if (rv != SA_OK) {
            std::cerr << "Couldn't open session" << std::endl;
            exit(EXIT_FAILURE);
        }

        SaHpiDomainInfoT domain_info;
        SaHpiEntityPathT entity_path;
        const int times_to_ask_query = 32 * 1024;
        for (int i = 1; i <= times_to_ask_query; ++i) {
            rv = saHpiMyEntityPathGet(session_id, &entity_path);
            std::this_thread::sleep_for(std::chrono::microseconds(100));
            rv = saHpiDomainInfoGet(session_id, &domain_info);
            std::this_thread::sleep_for(std::chrono::microseconds(100));
        }

        workers_finished.fetch_add(1);
    }

    void worker_5 (std::atomic_int& workers_finished) {
        SaHpiSessionIdT session_id;
        SaErrorT rv;
        rv = saHpiSessionOpen(SAHPI_UNSPECIFIED_DOMAIN_ID, &session_id, NULL);
        if (rv != SA_OK) {
            std::cerr << "Couldn't open session" << std::endl;
            exit(EXIT_FAILURE);
        }


        SaHpiDomainInfoT domain_info;
        SaHpiEntityPathT entity_path;
        SaHpiResourceIdT resource_id;
        const int times_to_ask_query = 16 * 1024;
        for (int i = 1; i <= times_to_ask_query; ++i) {
            rv = saHpiMyEntityPathGet(session_id, &entity_path);
            std::this_thread::sleep_for(std::chrono::microseconds(100));
            saHpiResourceIdGet(session_id, &resource_id);
            std::this_thread::sleep_for(std::chrono::microseconds(100));
            rv = saHpiDomainInfoGet(session_id, &domain_info);
            std::this_thread::sleep_for(std::chrono::microseconds(100));
            saHpiResourceIdGet(session_id, &resource_id);
            std::this_thread::sleep_for(std::chrono::microseconds(100));
        }

        workers_finished.fetch_add(1);
    }

    void worker_6 (std::atomic_int& workers_finished) {
        SaHpiSessionIdT session_id;
        SaErrorT rv;
        rv = saHpiSessionOpen(SAHPI_UNSPECIFIED_DOMAIN_ID, &session_id, NULL);
        if (rv != SA_OK) {
            std::cerr << "Couldn't open session" << std::endl;
            exit(EXIT_FAILURE);
        }


        SaHpiEntityPathT entity_path;
        SaHpiResourceIdT resource_id;
        const int times_to_ask_query = 32 * 1024;
        for (int i = 1; i <= times_to_ask_query; ++i) {
            saHpiResourceIdGet(session_id, &resource_id);
            std::this_thread::sleep_for(std::chrono::microseconds(100));
            rv = saHpiMyEntityPathGet(session_id, &entity_path);
            std::this_thread::sleep_for(std::chrono::microseconds(100));
        }

        workers_finished.fetch_add(1);
    }

    void worker_7 (std::atomic_int& workers_finished) {
        SaHpiSessionIdT session_id;
        SaErrorT rv;
        rv = saHpiSessionOpen(SAHPI_UNSPECIFIED_DOMAIN_ID, &session_id, NULL);
        if (rv != SA_OK) {
            std::cerr << "Couldn't open session" << std::endl;
            exit(EXIT_FAILURE);
        }


        SaHpiDomainInfoT domain_info;
        SaHpiEntryIdT entry;
        SaHpiRptEntryT rpt_entry;
        const int times_to_ask_query = 64 * 1024;
        for (int i = 1; i <= times_to_ask_query; ++i) {
            rv = saHpiDiscover(session_id);
            std::this_thread::sleep_for(std::chrono::microseconds(100));
            rv = saHpiDomainInfoGet(session_id, &domain_info);
            std::this_thread::sleep_for(std::chrono::microseconds(100));
            rv = saHpiDiscover(session_id);
            std::this_thread::sleep_for(std::chrono::microseconds(100));
            rv = saHpiRptEntryGet(session_id, SAHPI_ENTRY_UNSPECIFIED, &entry, &rpt_entry);
            std::this_thread::sleep_for(std::chrono::microseconds(100));
        }

        workers_finished.fetch_add(1);
    }
}