#include <fstream>
#include "RootTestSuite.h"

int main() {
    std::filebuf fb;
    if (!fb.open("log.txt", std::ios::out)) {
        std::cerr << "Couldn't open log file" << std::endl;
        exit(EXIT_FAILURE);
    }
    std::ostream out(&fb);

    RootTestSuite().executeTests(out);
}
