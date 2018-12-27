#include "analyser.h"
#include <fstream>
#include <stdexcept>


Analyser::Analyser(const std::string& fileName)
        : fileName_(fileName)
{
    try
    {
        readFile();
    }
    catch (std::exception &ex)
    {
        cout << "Something is going wrong! " << ex.what() << endl;
    }
}


void Analyser::readFile()
{
    std::ifstream file(fileName_);
    if(!file)
    {
        throw std::runtime_error("Could not open file!");
    }

    file.seekg(0, std::ios::end);
    ssize_t fileSize = file.tellg();
    gettedText.resize(fileSize);
    file.seekg(0);
    file.read(&gettedText[0], fileSize); // по стандарту можно в C++11, по факту работает и на старых компиляторах
    file.close();
}


void Analyser::analyseFrequency()
{
    for(char &symbol : gettedText)
    {
        if(symbol != '\n')
        {
            // Если элемента нет в словаре
            auto it = frequencyList_.find(symbol);
            if(it == frequencyList_.end())
            {
                frequencyList_.insert( std::pair<char, size_t>(symbol, 1) );
            }
            else
            {
                it->second += 1;
            }
        }
    }
}


void Analyser::printFrequency()
{
    analyseFrequency();

    std::ofstream resultFile("result_" + fileName_);

//    cout << "Size = " << frequencyList_.size() << endl;
    for(auto &key : frequencyList_)
    {
        resultFile << key.first << " = " << key.second << endl;
    }
}
