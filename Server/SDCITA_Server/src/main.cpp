#include <iostream>
#include <server_part_handler.h>
#include <thrift_generated.h>

using namespace std;

int main()
{
    try
    {
        sdcita::Server serv(9091, "", "fort-pc");
        serv.Start();

        cout << "Hello World!" << endl;
    }
    catch(std::exception& e)
    {
        cout << e.what() << endl;
    }
    return 0;
}
