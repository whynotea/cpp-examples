#ifndef WHYNOTEA_CPP_EXAMPLES_DESIGN_PATTERNS_FACTORY_METHOD_CREATOR_H
#define WHYNOTEA_CPP_EXAMPLES_DESIGN_PATTERNS_FACTORY_METHOD_CREATOR_H
#include <string>

#include "product.h"

namespace whynotea::cpp_examples::design_patterns::factory_method {
class Creator {
 public:
  virtual ~Creator();
  virtual IProduct* FactoryMethod() const = 0;

  std::string SomeOperation() const;
};
}  // namespace whynotea::cpp_examples::design_patterns::factory_method

#endif  // WHYNOTEA_CPP_EXAMPLES_DESIGN_PATTERNS_FACTORY_METHOD_CREATOR_H
