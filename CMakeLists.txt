cmake_minimum_required(VERSION 3.17)
project(stress_openhpi)

set(CMAKE_CXX_STANDARD 20)

add_executable(stress_openhpi src/main.cpp include/wrapSaHpi.h
        src/utils/getCPUTime.c src/utils/getCPUTime.h
        src/framework/BaseTestSuite.cpp src/framework/BaseTestSuite.h
        src/framework/BaseTestCase.cpp src/framework/BaseTestCase.h
        src/utils/getMemoryUsage.c src/utils/getMemoryUsage.h
        src/tests/RootTestSuite.cpp src/tests/RootTestSuite.h
        src/utils/WorkersHub.cpp src/utils/WorkersHub.h
        src/tests/OneFunctionTests/saHpiDomainInfoGet.cpp src/tests/OneFunctionTests/saHpiDomainInfoGet.h
        src/tests/OneFunctionTests/saHpiMyEntityPathGet.cpp src/tests/OneFunctionTests/saHpiMyEntityPathGet.h
        src/tests/OneFunctionTests/saHpiDrtEntryGet.cpp src/tests/OneFunctionTests/saHpiDrtEntryGet.h
        src/tests/OneFunctionTests/saHpiDiscover.cpp src/tests/OneFunctionTests/saHpiDiscover.h
        src/tests/OneFunctionTests/saHpiRptEntryGet.cpp src/tests/OneFunctionTests/saHpiRptEntryGet.h
        src/tests/OneFunctionTests/saHpiResourceIdGet.cpp src/tests/OneFunctionTests/saHpiResourceIdGet.h
        src/tests/OneFunctionTests/saHpiEventLogInfoGet.cpp src/tests/OneFunctionTests/saHpiEventLogInfoGet.h
        src/tests/DiversityTests/Diversity_0.cpp src/tests/DiversityTests/Diversity_0.h
        src/tests/MiddleLoadTests/MiddleLoad.cpp src/tests/MiddleLoadTests/MiddleLoad.h
        src/tests/DiversityTests/Diversity_1.cpp src/tests/DiversityTests/Diversity_1.h
        src/tests/DiversityTests/Diversity_2.cpp src/tests/DiversityTests/Diversity_2.h
        src/tests/DiversityTests/Diversity_3.cpp src/tests/DiversityTests/Diversity_3.h
        src/tests/DiversityTests/Diversity_4.cpp src/tests/DiversityTests/Diversity_4.h
        src/tests/DiversityTests/TestSuite.cpp src/tests/DiversityTests/TestSuite.h
        src/tests/OneFunctionTests/TestSuite.cpp src/tests/OneFunctionTests/TestSuite.h
        src/tests/MiddleLoadTests/TestSuite.cpp src/tests/MiddleLoadTests/TestSuite.h)

# tests
target_include_directories(stress_openhpi PRIVATE
        src/framework
        src/tests
        src/utils)

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
