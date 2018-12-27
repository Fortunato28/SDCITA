//
// main.cpp
// ~~~~~~~~~~
// Sipmple file transport
//

#include <ctime>
#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <fstream>
#include <vector>

using boost::asio::ip::tcp;
using std::cout;
using std::endl;
using std::ifstream;
using std::vector;

int main()
{
    // Open file in binary mod
    ifstream file ("/home/fort/GPOProject/dc-middleware/SendFile/PartOneLessonFive", std::ios_base::ate | std::ios_base::binary);
    if(!file)
    {
        cout << "File can`t be opened." << endl;
        return 1;
    }

    std::vector<char> buf;
    std::fstream::pos_type fileSize = file.tellg();             // Get number of bytes in file
    file.seekg(0, std::ios_base::beg);                          // Set pointer to the begining of file
    buf.resize(fileSize);
    file.read(&buf[0], fileSize);                               // Read file in buffer
    file.close();

    try
    {
        boost::asio::io_context io_context;

        tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), 4567));

        for (;;)
        {
            tcp::socket socket(io_context);
            acceptor.accept(socket);

            boost::system::error_code ignored_error;
            boost::asio::write(socket, boost::asio::buffer(buf), ignored_error);
        }
    }

    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

  return 0;
}
