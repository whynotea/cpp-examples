#pragma once

#include <boost/asio.hpp>
#include "fix_msg.h"

#include <memory>

namespace whynotea::cpp_examples::c_11::connection
{
class Connection : public std::enable_shared_from_this<Connection>
{
  public:
    boost::asio::ip::tcp::socket socket_;
    
    Connection(boost::asio::ip::tcp::socket socket);
    ~Connection();

    void read();
    void do_read_header();
    void do_read_body();
    void close();
  private:
    fix::FixMsg read_msg_;
};
  
} // namespace whynotea::cpp_examples::c_11::connection
