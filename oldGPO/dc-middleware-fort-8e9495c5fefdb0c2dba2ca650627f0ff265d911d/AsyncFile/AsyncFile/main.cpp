#include <iostream>
#include <ctime>
#include <iostream>
#include <string>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/asio.hpp>
#include <vector>
#include <fstream>

using boost::asio::ip::tcp;
using std::cout;
using std::endl;

void getFile(std::vector<char>& buf)
{
    std::ifstream file ("/home/fort/GPOProject/dc-middleware/SendFile/PartOneLessonFive", std::ios_base::ate | std::ios_base::binary);
    if(!file)
    {
        cout << "File can`t be opened." << endl;
        exit(1);
    }

    std::fstream::pos_type fileSize = file.tellg();             // Get number of bytes in file
    file.seekg(0, std::ios_base::beg);                          // Set pointer to the begining of file
    buf.resize(fileSize);
    file.read(&buf[0], fileSize);                               // Read file in buffer
    file.close();
}

class tcp_connection
  : public boost::enable_shared_from_this<tcp_connection>
{
public:
  typedef boost::shared_ptr<tcp_connection> pointer;

  static pointer create(boost::asio::io_context& io_context)
  {
    return pointer(new tcp_connection(io_context));
  }

  tcp::socket& socket()
  {
    return socket_;
  }

  void start()
  {
    getFile(fileForSending);
    // записываем все данные в сокет асинхронно
    boost::asio::async_write(socket_, boost::asio::buffer(fileForSending),
        boost::bind(&tcp_connection::handle_write, shared_from_this(), // достаточно указать только аргументы, необходимые обработчику
          boost::asio::placeholders::error,
          boost::asio::placeholders::bytes_transferred));
  }

private:
  tcp_connection(boost::asio::io_context& io_context)
    : socket_(io_context)
  {
  }

  void handle_write(const boost::system::error_code& /*error*/,
      size_t transferred)
  {
      cout << "Byte transferred: " << transferred << endl;
  }

  tcp::socket socket_;
  std::vector<char> fileForSending;
};

class tcp_server
{
public:
    // инициализирует акцептор на прослушивание 13 порта
  tcp_server(boost::asio::io_context& io_context)
    : acceptor_(io_context, tcp::endpoint(tcp::v4(), 4567))
  {
    start_accept();
  }

private:
  // создаёт сокет и запускает асинхронный приём нового соединения
  void start_accept()
  {
    tcp_connection::pointer new_connection =
      tcp_connection::create(acceptor_.get_executor().context());

    acceptor_.async_accept(new_connection->socket(),
        boost::bind(&tcp_server::handle_accept, this, new_connection,
          boost::asio::placeholders::error));

    cout << "Connected" << endl;
  }
    // вызывается, когда завершается операция асинхронного приёма
    // обслуживает клиентский запрос, и снова инициирует следующую операцию приёма.
  void handle_accept(tcp_connection::pointer new_connection,
      const boost::system::error_code& error)
  {
    if (!error)
    {
      new_connection->start();
    }

    start_accept();
  }

  tcp::acceptor acceptor_;
};

int main()
{
  try
  {
    boost::asio::io_context io_context;
    tcp_server server(io_context);
    io_context.run();
  }
  catch (std::exception& e)
  {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}
