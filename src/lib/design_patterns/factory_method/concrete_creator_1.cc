#include "concrete_creator_1.h"

#include "concrete_product_1.h"

namespace whynotea::cpp_examples::design_patterns::factory_method {
IProduct* ConcreteCreator1::FactoryMethod() const {
  return new ConcreteProduct1();
}
}  // namespace whynotea::cpp_examples::design_patterns::factory_method
