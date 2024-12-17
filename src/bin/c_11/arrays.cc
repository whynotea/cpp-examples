#include "arrays.h"
#include <iostream>
#include <array>

namespace whynotea::cpp_examples::c_11
{
arrays::arrays()
{
}

arrays::~arrays()
{
}

void arrays::run()
{
  const size_t array_size = 3;
  int ia[array_size] = {0,1,2};
  char ca[] = "c++";
  for(size_t ix = 0; ix !=array_size; ++ix) {
    std::cout << "Array value: " << ia[ix] << std::endl;
    std::cout << "Array value: " << ca[ix] << std::endl;
  }
}

void arrays::run2()
{
  std::array<int,3> myArray = {1,2,3};
  for(auto it = myArray.begin(); it != myArray.end(); ++it) {
    std::cout << "Iterator: " << *it << std::endl;
  }
  for(auto value : myArray) {
    std::cout << "Range: " << value << std::endl;
  }
  for(std::array<int,3UL>::iterator it = myArray.begin(); it != myArray.end(); ++it) {
    std::cout << "Iterator: " << *it << std::endl;
  }
}

} // namespace whynotea::cpp_examples::c_11
