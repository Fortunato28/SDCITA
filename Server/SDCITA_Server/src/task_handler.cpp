#include "task_handler.h"
#include <fstream>
#include <string>
#include <iostream>
#include <boost/filesystem.hpp>

// TODO: Выделить в отдельный класс
FileChunk UploadFile(const std::string& fullFileName, bool isExecutable)
{
    // Open file in binary mod
    std::ifstream file (fullFileName, std::ios_base::ate | std::ios_base::binary);
    if(!file)
    {
        throw "Bad file request!";
    }

    std::vector<char> buf;
    std::fstream::pos_type fileSize = file.tellg();             // Get number of bytes in file
    file.seekg(0, std::ios_base::beg);                          // Set pointer to the begining of file
    buf.resize(fileSize);
    file.read(&buf[0], fileSize);                               // Read file in buffer
    file.close();
    std::string rawFileData(buf.begin(), buf.end());

    FileChunk _result;

    boost::filesystem::path filePath(fullFileName);
    // TODO extract like class FileUploader`s member
    // TODO extract fileName
    _result.__set_fileName(filePath.filename().string());
    // TODO get file Format
    _result.__set_fileFormat("Reserved");
    _result.__set_data(rawFileData);
    // TODO hash zapili mne
    _result.__set_hash("Vot tebe hash");
    // TODO isExecutable
    _result.__set_isExecutable(isExecutable);

    return _result;
}

// TODO захардкоженные данные потом должны тянуться из файла конфига задания!
TaskHandler::TaskHandler()
{
    // Task constructor
    std::vector<FileChunk> filesToReceive;
    filesToReceive.emplace_back(UploadFile("../example/FrequencyAnalysis", true));
    filesToReceive.emplace_back(UploadFile("../example/first_part.txt", false));
    filesToReceive.emplace_back(UploadFile("../example/second_part.txt", false));

    currentTask_.__set_taskName("War end piece\n");
    currentTask_.__set_taskDescription("SDCITA Prototype\n");
    currentTask_.__set_files(filesToReceive);
    currentTask_.__set_cmdToExec("time ./FrequencyAnalysis");
    // BUG
    // What the HUG! If string = "No other Data", stack will be smashed
    currentTask_.__set_otherData("No other Data SSDDS");
    currentTask_.__set_estimatedLeadTime(2000);
}

// Ugly, TODO fix it
// Залипуха, чтобы улетали нужные файлы. Куда-нибудь потом её оторвать

Task TaskHandler::fileBalancing()
{
    Task balancedTask = currentTask_;
    FileChunk currentFileToReceived = balancedTask.files.at(1);
    FileChunk executableFile;

    // Search file with lowest shipping counter
    for(auto& file : balancedTask.files)
    {
        if(!file.isExecutable)
        {
            if(file.shippingCounter < currentFileToReceived.shippingCounter)
            {
                currentFileToReceived = file;
            }
        }
        else
        {
            executableFile = file;
        }
    }

    // Erase all files, except needed for a particular client
    balancedTask.files.clear();
    balancedTask.files.push_back(currentFileToReceived);
    balancedTask.files.push_back(executableFile);

    for(auto& file : currentTask_.files)
    {
        if(file == currentFileToReceived)
        {
            ++file.shippingCounter;
        }
    }

    return balancedTask;
}

Task TaskHandler::GetTask()
{
    return fileBalancing();
}
