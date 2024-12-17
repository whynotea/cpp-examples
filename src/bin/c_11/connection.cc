#include "connection.h"
#include "message.h"
#include <iostream>

using namespace boost::asio::ip;

namespace whynotea::cpp_examples::c_11::connection
{
  
  Connection::Connection(tcp::socket socket):socket_(std::move(socket)) {};
  
  Connection::~Connection(){};

  void Connection::read()
  {
    do_read_header();
  }

  void Connection::do_read_header()
  {
    auto self(shared_from_this());
    boost::asio::async_read(socket_,
        boost::asio::buffer(read_msg_.data(), message::Message::header_length),
        [this, self](boost::system::error_code ec, std::size_t /*length*/)
        {
          if (!ec && read_msg_.decode_header())
          {
            do_read_body();
          }
        });
  }

  void Connection::do_read_body()
  {
    auto self(shared_from_this());
    boost::asio::async_read(socket_,
        boost::asio::buffer(read_msg_.body(), read_msg_.body_length()),
        [this, self](boost::system::error_code ec, std::size_t /*length*/)
        {
          if (!ec)
          {
            read_msg_.decodeFix();
            std::cout << "MESSAGE: " << read_msg_.body() << std::endl;
            do_read_header();
          }
        });
  }

  void Connection::close()
  {
    socket_.close();
  }
} // namespace whynotea::cpp_examples::c_11::connection
