#include "server.h"
#include "message.h"

#include <iostream>

using namespace boost::asio::ip;

namespace whynotea::cpp_examples::c_11::server
{
Server::Server(int port) 
{
  endpoint_ = tcp::endpoint(tcp::v4(), port);
  acceptor_ = new tcp::acceptor(io_context_,endpoint_);
  std::cout << "Server initialising on port " << port << "..." << std::endl;
}

Server::~Server()
{
  delete acceptor_;
  std::cout << "Server terminated" << std::endl;
}

void Server::start()
{
  std::cout << "Server accepting connections..." << std::endl;
  acceptor_->async_accept(
    [this](boost::system::error_code ec, tcp::socket socket) {
      if (!ec)
      {
        auto connection = std::make_shared<connection::Connection>(std::move(socket));
        this->connections_.push_back(connection);
        connection->read();
      }
    }
  );
  io_context_.run();
}

void Server::listen(){
}
void Server::read()
{
}
void Server::closeConnections()
{
  boost::asio::post(io_context_, [this]()
    {
      std::cout << "Connection terminating..." << std::endl;
      for(auto connection : this->connections_)
        connection->close();
      std::cout << "Connection terminated." << std::endl;
    }
  );
}
void Server::stop()
{
  std::cout << "Server stopping..." << std::endl;
  io_context_.stop();
  std::cout << "Server stopped." << std::endl;
} 
}// namespace whynotea::cpp_examples::c_11::server
