#include "fix_msg.h"
#include <sstream>
#include "fix_msg_types.h"

namespace whynotea::cpp_examples::c_11::fix
{
  FixMsg::FixMsg()
  {

  }
  
  FixMsg::~FixMsg()
  {
  }

  //8=FIX.4.4;9=123;35=D;49=ABC;56=DEF;55=IBM;54=1;38=100;40=1;44=200.00;59=0;60=20130913-10:15:00;10=000
  void FixMsg::decodeFix()
  {
    std::istringstream iss(data());
    std::string field;

    fix::IMsg* msg;

    while (std::getline(iss, field, ';')) {
      std::size_t pos = field.find('=');
      if (pos != std::string::npos) {
        std::string tag = field.substr(0,pos);
        std::string value = field.substr(pos + 1);

        switch (atoi(tag.c_str()))
        {
        case 9:
          /* code */
          break;
        case 35:
          if (value == "D") {
            msg = new NewOrderSingle;
            msg->parse(this);
          }
          break;
        
        default:
          break;
        }
      }
    }
  } 
} // namespace whynotea::cpp_examples::c_11::fix
