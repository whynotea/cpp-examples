#pragma once
#include <boost/asio.hpp>
#include "message.h"
#include <deque>

namespace whynotea::cpp_examples::c_11::client
{
  typedef std::deque<message::Message> message_queue;

  class Client
  {
  private:
    boost::asio::io_context io_context_;
    boost::asio::ip::tcp::endpoint endpoint_;
    boost::asio::ip::tcp::socket* socket_;
    message::Message read_msg_;
    message_queue write_msgs_;

    
  public:
    Client(const char* const host, int port);
    ~Client();
    void connect(const boost::asio::ip::tcp::resolver::results_type& endpoints);
    void do_read_header();
    void do_read_body();
    void write(const message::Message&);
    void close();
    void send();
    void start();
  };
  
} // namespace whynotea::cpp_examples::c_11::client
