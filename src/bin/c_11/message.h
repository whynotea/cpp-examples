#pragma once

#include <cstdio>
#include <cstdlib>
#include <cstring>

namespace whynotea::cpp_examples::c_11::message
{
  class Message
  {
  public:
    static constexpr std::size_t header_length = 4;
    static constexpr std::size_t max_body_length = 512;
    
    Message();
    virtual ~Message();

    const char* data() const;

    char* data();

    std::size_t length() const;
    const char* body() const;

    char* body();

    std::size_t body_length() const;

    void body_length(std::size_t new_length);

    bool decode_header();

    void encode_header();
  
  private:
    std::size_t body_length_;
    char data_[header_length + max_body_length];
    
  };
} // namespace whynotea::cpp_examples::c_11::message
