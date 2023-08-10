#ifndef WHYNOTEA_CPP_EXAMPLES_DESIGN_PATTERNS_FACTORY_METHOD_CONCRETE_CREATOR_1_H
#define WHYNOTEA_CPP_EXAMPLES_DESIGN_PATTERNS_FACTORY_METHOD_CONCRETE_CREATOR_1_H
#include "creator.h"

namespace whynotea::cpp_examples::design_patterns::factory_method {
class ConcreteCreator1 : public Creator {
 public:
  IProduct* FactoryMethod() const override;
};
}  // namespace whynotea::cpp_examples::design_patterns::factory_method

#endif  // WHYNOTEA_CPP_EXAMPLES_DESIGN_PATTERNS_FACTORY_METHOD_CONCRETE_CREATOR_1_H
