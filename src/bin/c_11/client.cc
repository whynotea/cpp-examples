#include "client.h"
#include <string>
#include <iostream>

using namespace boost::asio::ip;

namespace whynotea::cpp_examples::c_11::client
{
  Client::Client(const char* const host, int port)
  {
    tcp::resolver resolver(io_context_);
    auto endpoints = resolver.resolve(host, std::to_string(port).c_str());
    socket_ = new tcp::socket(io_context_);
    connect(endpoints);
  }
  
  Client::~Client()
  {
    delete socket_;
    std::cout << "Client terminated" << std::endl;
  }

  void Client::write(const message::Message& msg)
  {
    boost::asio::post(io_context_,
        [this, msg]()
        {
          bool write_in_progress = !write_msgs_.empty();
          write_msgs_.push_back(msg);
          if (!write_in_progress)
          {
            send();
          }
        });
  }

  void Client::close()
  {
    boost::asio::post(io_context_, [this]() { (*socket_).close(); });
  }

  void Client::connect(const tcp::resolver::results_type& endpoints)
  {
    boost::asio::async_connect(*socket_, endpoints,
    [this](boost::system::error_code ec, tcp::endpoint)
    {
      if (!ec)
      {
        do_read_header();
      }
    });
  }

  void Client::start()
  {
    std::cout << "Client starting..." << std::endl;
    io_context_.run();
  }

  void Client::do_read_header()
  {
    boost::asio::async_read(*socket_,
        boost::asio::buffer(read_msg_.data(), message::Message::header_length),
        [this](boost::system::error_code ec, std::size_t /*length*/)
        {
          if (!ec && read_msg_.decode_header())
          {
            do_read_body();
          }
          else
          {
            (*socket_).close();
          }
        });
  }

  void Client::do_read_body()
  {
    boost::asio::async_read((*socket_),
        boost::asio::buffer(read_msg_.body(), read_msg_.body_length()),
        [this](boost::system::error_code ec, std::size_t /*length*/)
        {
          if (!ec)
          {
            std::cout.write(read_msg_.body(), read_msg_.body_length());
            std::cout << "\n";
            do_read_header();
          }
          else
          {
            (*socket_).close();
          }
        });
  }

  void Client::send()
  {
    boost::asio::async_write((*socket_),
        boost::asio::buffer(write_msgs_.front().data(),
          write_msgs_.front().length()),
        [this](boost::system::error_code ec, std::size_t /*length*/)
        {
          if (!ec)
          {
            write_msgs_.pop_front();
            if (!write_msgs_.empty())
            {
              send();
            }
          }
          else
          {
            (*socket_).close();
          }
        });
  }
} // namespace whynotea::cpp_examples::c_11::client
