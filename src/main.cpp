#include <fstream>
#include "TestSuite.h"

int main() {
    TestSuite test_suite;

    std::filebuf fb;
    if (!fb.open("log.txt", std::ios::out)) {
        std::cerr << "Couldn't open log file" << std::endl;
    }
    std::ostream out(&fb);

    test_suite.executeTests(out);
}
