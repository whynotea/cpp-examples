#include <design_patterns/factory_method/client_code.h>
#include <design_patterns/factory_method/concrete_creator_1.h>
#include <design_patterns/factory_method/concrete_creator_2.h>

#include <iostream>
#include <string>

using namespace whynotea::cpp_examples::design_patterns;
using namespace std;

void factoryMethod() {
  std::cout << "App: Launched with the ConcreteCreator1.\n";
  factory_method::Creator* creator1 = new factory_method::ConcreteCreator1();
  factory_method::ClientCode(*creator1);
  std::cout << std::endl;

  std::cout << "App: Launched with the ConcreteCreator2.\n";
  factory_method::Creator* creator2 = new factory_method::ConcreteCreator2();
  factory_method::ClientCode(*creator2);

  delete creator1;
  delete creator2;
}

int main(int argc, char* argv[]) {
  factoryMethod();

  return EXIT_SUCCESS;
}
