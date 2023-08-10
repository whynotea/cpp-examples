#include "concrete_creator_2.h"

#include "concrete_product_2.h"

namespace whynotea::cpp_examples::design_patterns::factory_method {
IProduct* ConcreteCreator2::FactoryMethod() const {
  return new ConcreteProduct2();
}
}  // namespace whynotea::cpp_examples::design_patterns::factory_method
