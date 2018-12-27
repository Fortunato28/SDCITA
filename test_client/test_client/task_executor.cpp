#include <iostream>
#include <fstream>

#include <boost/filesystem.hpp>

#include "task_executor.h"

#define fs boost::filesystem
#define fsp boost::filesystem::perms

// Give us output from linux command
std::string exec(const char* cmd)
{
    std::array<char, 128> buffer;
    std::string result;
    std::shared_ptr<FILE> pipe(popen(cmd, "r"), pclose);
    if (!pipe) throw std::runtime_error("popen() failed!");
    while (!feof(pipe.get())) {
        if (fgets(buffer.data(), 128, pipe.get()) != nullptr)
            result += buffer.data();
    }

    return result;
}

Task_executor::Task_executor(const Task& gettedTask) : gettedTask_(gettedTask), pathToFiles_(gettedTask.taskName)
{
    createDirectory(gettedTask_.taskName);
    PrepareFiles();
}

void Task_executor::setPermissions(const std::string& fileName)
{
    fs::permissions(fileName, fsp::owner_exe);
}

void Task_executor::createDirectory(const std::string& directoryName)
{
    boost::filesystem::create_directory(directoryName);
}

void Task_executor::PrepareFiles()
{
    std::cout << gettedTask_.cmdToExec << "\n";

    auto taskFiles = gettedTask_.files;

    // Save all files filesystem
    // TODO выделить в отдельный класс, осуществляющий загрузку и выгрузку файлов.
    for(auto& gettedFile : taskFiles)
    {
        boost::filesystem::path fullFileName = pathToFiles_ + "/" + gettedFile.fileName;
        std::ofstream fileOnFS(fullFileName.string());
        fileOnFS << gettedFile.data;

        if(gettedFile.isExecutable)
        {
            setPermissions(fullFileName.string());
        }

        fileOnFS.close();
    }
}

bool Task_executor::Execute()
{
    boost::filesystem::current_path(pathToFiles_);

    FileChunk fileForAnalysis;
    for(auto& file : gettedTask_.files)
    {
        if(!file.isExecutable)
        {
            fileForAnalysis = file;
        }
    }

    auto command = gettedTask_.cmdToExec + " " + fileForAnalysis.fileName;

    std::cout << exec(command.c_str()) << "\n";
}

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

// Another HUG up. FileName "result" has to be getted from server
FileChunk Task_executor::GetResult()
{
    FileChunk fileForAnalysis;
    for(auto& file : gettedTask_.files)
    {
        if(!file.isExecutable)
        {
            fileForAnalysis = file;
        }
    }

    FileChunk result(UploadFile("result_" + fileForAnalysis.fileName, false));

    return result;
}




















