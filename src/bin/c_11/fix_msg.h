#pragma once

#include "message.h"

namespace whynotea::cpp_examples::c_11::fix
{
  class FixMsg : public message::Message
  {
  private:
    
  public:
    FixMsg();
    ~FixMsg();

    void decodeFix();
  };
  
} // namespace whynotea::cpp_examples::c_11::fix
