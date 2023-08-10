#ifndef WHYNOTEA_CPP_EXAMPLES_DESIGN_PATTERNS_FACTORY_METHOD_PRODUCT_H
#define WHYNOTEA_CPP_EXAMPLES_DESIGN_PATTERNS_FACTORY_METHOD_PRODUCT_H
#include <string>

namespace whynotea::cpp_examples::design_patterns::factory_method {
class IProduct {
 public:
  virtual ~IProduct(){};
  virtual std::string Operation() const = 0;
};
}  // namespace whynotea::cpp_examples::design_patterns::factory_method

#endif  // WHYNOTEA_CPP_EXAMPLES_DESIGN_PATTERNS_FACTORY_METHOD_PRODUCT_H
