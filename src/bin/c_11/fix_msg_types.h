#pragma once

#include <iostream>
#include <string>
#include "message.h"

namespace whynotea::cpp_examples::c_11::fix
{
  struct IMsg
  {
    virtual void parse(message::Message* msg) = 0;
    IMsg(){};
    virtual ~IMsg(){};
  };

  struct NewOrderSingle : public IMsg
  {
    std::string SenderCompID;
    std::string TargetCompID;
    std::string ClOrdID;
    std::string Symbol;
    char Side; // '1' for buy, '2' for sell
    int OrderQty;
    double Price;

    void parse(message::Message* msg){
      std::cout << "NewOrderSingle parser called" << std::endl;
    };
  };
  
} // namespace whynotea::cpp_examples::c_11::fix
