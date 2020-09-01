cmake_minimum_required(VERSION 3.17)
project(stress_openhpi)

set(CMAKE_CXX_STANDARD 20)

add_executable(stress_openhpi src/main.cpp include/wrapSaHpi.h
        include/getCPUTime.c include/getCPUTime.h
        src/framework/TestSuite.cpp src/framework/TestSuite.h
        src/framework/TestCase.cpp src/framework/TestCase.h
        include/getMemoryUsage.c include/getMemoryUsage.h
        src/tests/saHpiDomainInfoGet.cpp src/tests/saHpiDomainInfoGet.h
        src/tests/saHpiMyEntityPathGet.cpp src/tests/saHpiMyEntityPathGet.h
        src/tests/saHpiDrtEntryGet.cpp src/tests/saHpiDrtEntryGet.h
        src/tests/saHpiDiscover.cpp src/tests/saHpiDiscover.h
        src/tests/saHpiRptEntryGet.cpp src/tests/saHpiRptEntryGet.h
        src/tests/saHpiResourceIdGet.cpp src/tests/saHpiResourceIdGet.h
        src/tests/saHpiEventLogInfoGet.cpp src/tests/saHpiEventLogInfoGet.h src/tests/Diversity.cpp src/tests/Diversity.h src/tests/MiddleLoad.cpp src/tests/MiddleLoad.h)

# tests
target_include_directories(stress_openhpi PRIVATE
        src/framework
        src/tests)

# glib-2.0
target_include_directories(stress_openhpi PRIVATE
        /usr/local/include/glib-2.0
        /usr/local/lib/x86_64-linux-gnu/glib-2.0/include)

target_link_directories(stress_openhpi PRIVATE /usr/local/lib/x86_64-linux-gnu)

target_link_libraries(stress_openhpi PRIVATE -lglib-2.0)

# openhpi
target_include_directories(stress_openhpi PRIVATE
        /usr/local/include/openhpi
        include/)

target_link_directories(stress_openhpi PRIVATE /usr/local/lib)

target_link_libraries(stress_openhpi PRIVATE -lopenhpi)

# pthread
target_link_libraries(stress_openhpi PRIVATE -lpthread)
