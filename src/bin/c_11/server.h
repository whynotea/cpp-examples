#pragma once
#include <boost/asio.hpp>
#include "connection.h"
#include <deque>

namespace whynotea::cpp_examples::c_11::server
{
 typedef std::deque<std::shared_ptr<connection::Connection>> connection_list;

 class Server
 {
 private:
  boost::asio::ip::tcp::acceptor* acceptor_;
  boost::asio::io_context io_context_;
  boost::asio::ip::tcp::endpoint endpoint_;
  connection_list connections_;

 public:
  Server(int port);
  ~Server();
  void start();
  void stop();
  void closeConnections();
  void listen();
  void read();
 };
 
} // namespace whynotea::cpp_examples::c_11::server
