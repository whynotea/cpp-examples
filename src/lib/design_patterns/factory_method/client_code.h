#ifndef WHYNOTEA_CPP_EXAMPLES_DESIGN_PATTERNS_FACTORY_METHOD_CLIENT_CODE_H
#define WHYNOTEA_CPP_EXAMPLES_DESIGN_PATTERNS_FACTORY_METHOD_CLIENT_CODE_H
#include <iostream>

#include "creator.h"

namespace whynotea::cpp_examples::design_patterns::factory_method {

/// @param creator The concrete creator implementing the factory method
void ClientCode(const Creator& creator) {
  std::cout
      << "Client: I'm not aware of the creator's class, but it still works.\n"
      << creator.SomeOperation() << std::endl;
}
}  // namespace whynotea::cpp_examples::design_patterns::factory_method
#endif  // WHYNOTEA_CPP_EXAMPLES_DESIGN_PATTERNS_FACTORY_METHOD_CLIENT_CODE_H
