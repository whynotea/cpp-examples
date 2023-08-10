#ifndef WHYNOTEA_CPP_EXAMPLES_DESIGN_PATTERNS_FACTORY_METHOD_CONCRETE_PRODUCT_2_H
#define WHYNOTEA_CPP_EXAMPLES_DESIGN_PATTERNS_FACTORY_METHOD_CONCRETE_PRODUCT_2_H
#include "product.h"

namespace whynotea::cpp_examples::design_patterns::factory_method {
class ConcreteProduct2 : public IProduct {
 public:
  std::string Operation() const override;
};
}  // namespace whynotea::cpp_examples::design_patterns::factory_method
#endif  // WHYNOTEA_CPP_EXAMPLES_DESIGN_PATTERNS_FACTORY_METHOD_CONCRETE_PRODUCT_2_H
