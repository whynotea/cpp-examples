#include "creator.h"

namespace whynotea::cpp_examples::design_patterns::factory_method {

Creator::~Creator(){};

std::string Creator::SomeOperation() const {
  IProduct* product = this->FactoryMethod();
  std::string result =
      "Creator: The same creator's code has just worked with " +
      product->Operation();
  delete product;
  return result;
}

}  // namespace whynotea::cpp_examples::design_patterns::factory_method
