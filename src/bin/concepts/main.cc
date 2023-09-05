#include <iostream>

void weaklyTyped();

int main() {
  weaklyTyped();
  return 0;
}

void weaklyTyped() {
  int myInt = 1;
  double myDouble = 2.9;
  int myResult = myDouble + myInt;
  std::cout << "Weakly typed implicit conversion from double to int:\n";
  std::cout << myInt << " + " << myDouble << " = " << myResult << '\n';
}
