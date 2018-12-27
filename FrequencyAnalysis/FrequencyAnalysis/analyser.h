#ifndef ANALYSER_H
#define ANALYSER_H

#include <map>
#include <string>
#include <iostream>


using std::cout;
using std::endl;


class Analyser
{
public:
    Analyser(const std::string& fileName);

    void printFrequency();

private:
    void readFile();
    void analyseFrequency();

    std::string fileName_;
    std::string gettedText;
    std::map<char, size_t> frequencyList_;
};

#endif // ANALYSER_H
