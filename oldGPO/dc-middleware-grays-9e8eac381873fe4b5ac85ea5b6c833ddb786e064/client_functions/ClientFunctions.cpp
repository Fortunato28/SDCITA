#include "ClinetFucntions.h"

namespace clientFunctions
{
// подключаемся к серверу
boost::asio::ip::tcp::socket  nakeConnetction( std::string targetDns , std::string tergetPort )
{
    boost::asio::io_context io_context;
    boost::asio::ip::tcp::resolver resolver( io_context );
    boost::asio::ip::tcp::resolver::results_type endpoints =
    resolver.resolve( targetDns, tergetPort );  // TODO: сделать нормальный DNS & PORT
    boost::asio::ip::tcp::socket socket( io_context );
    boost::asio::connect( socket, endpoints );
    return socket;
}


// сообщаем сереверу, что клиент подключен
bool iAmOk( std::string targetDns )
{
    try
      {
        std::string tergetPort = ""; // TODO: Узнать порт у антона
        boost::asio::ip::tcp::socket socket = nakeConnetction( targetDns , tergetPort );
        for (;;)
        {
          boost::array<char, 128> buf;
          boost::system::error_code error;         // ошибка если не получили сообщенеи от сервера
          boost::system::error_code ignored_error; // ошибка если сервере не получил сообщение
          int errorFlag = 0;
          std::string iAmOkMessage = "I'm OK";
          size_t serverOk;                         // ответ сервера

          boost::asio::write( socket, boost::asio::buffer( iAmOkMessage ), ignored_error );

          while( 1 )
          {
                serverOk = socket.read_some( boost::asio::buffer ( buf ), error );
                if ( !error )
                {
                        return true;
                }
                else if ( errorFlag >= 25 )
                {
                    return false;
                }
                else { errorFlag++; }
          }
        }
      }
      catch ( std::exception& e )
      {
        std::cerr << e.what() << std::endl;
      }
}


int getFile(int argc, char* argv[])
{
    try
    {
        std::string tergetPort = "4567"; // TODO: Узнать порт у антона
        std::string targetDns = "fort-pc";


        boost::asio::ip::tcp::socket socket = nakeConnetction( targetDns , tergetPort );
        std::ofstream writeFile ( "file" );
        size_t buffsize= 0;
        int i = 0;
        for (;;)
        {

            boost::array<char, 300000> buf;
            boost::system::error_code error;

            size_t len = socket.read_some(boost::asio::buffer(buf), error);

            if (error == boost::asio::error::eof)
                break; // Connection closed cleanly by peer.
            else if (error)
                throw boost::system::system_error(error); // Some other error.
          //  std::count << len << std::endl;
            char data[len];
          //  std::copy(buf.begin(), buf.begin()+len, data);
            std::cout << "i = " << i << std::endl;
            i++;
            writeFile.write( buf.data(), len);

            std::stringstream ss;
            buffsize=len;
            ss << buffsize << std::endl;
            std::cout << ss.str() << std::endl << "DATA = "<<sizeof(data) << std::endl;
            //std::cout.write(buf.data(), len);
        }

        writeFile.close();
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}


// просим задание у сервера
std::string giveMeSomething( char targetIp )
{

}
}
