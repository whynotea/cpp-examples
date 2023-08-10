#include <design_patterns/factory_method/client_code.h>
#include <design_patterns/factory_method/concrete_creator_1.h>
#include <design_patterns/factory_method/concrete_creator_2.h>
#include <gtest/gtest.h>

using namespace whynotea::cpp_examples::design_patterns;

namespace {
TEST(FactoryMethod, StdOut) {
  testing::internal::CaptureStdout();
  factory_method::Creator* creator1 = new factory_method::ConcreteCreator1();
  factory_method::ClientCode(*creator1);
  std::string output = testing::internal::GetCapturedStdout();
  std::string expected =
      "Client: I'm not aware of the creator's class, but it still "
      "works.\nCreator: The same creator's code has just worked with {Result "
      "of the ConcreteProduct1}\n";
  EXPECT_STREQ(output.c_str(), expected.c_str());
}

}  // namespace
