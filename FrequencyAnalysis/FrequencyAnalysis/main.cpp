#include <iostream>
#include "analyser.h"
#include <string>

using std::cout;
using std::endl;

int main(int argc, char* argv[])
{
    Analyser textAnalyser(static_cast<std::string>(argv[1]));
    textAnalyser.printFrequency();

    return 0;
}
