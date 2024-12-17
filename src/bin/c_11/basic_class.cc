#include "basic_class.h"

#include <iostream>
#include <memory>
#include <vector>
#include <fmt/format.h>

namespace whynotea::cpp_examples::c_11 {
BasicClass::BasicClass() {}

BasicClass::~BasicClass() {}

void BasicClass::print() {
  fmt::println("Another line");
  fmt::println("{}", "This is a line in basic class");
}

void BasicClass::range() { 
  std::vector<int> numbers = {1, 2, 3, 4, 5};
  std::cout << "COPY:" << std::endl;
  for (auto num : numbers)
  {
    std::cout << "  BEFORE:"  << num << " ";
    ++num;
    std::cout << "  AFTER:" << num << " ";
  }
  std::cout << std::endl << "REFERENCE:" << std::endl;
  for (auto &num : numbers)
  {
    std::cout << "  BEFORE:"  << num << " ";
    ++num;
    std::cout << "  AFTER:" << num << " ";
  }
  std::cout << std::endl  << "MOVE REFERENCE:" << std::endl;
  for (auto &&num : numbers)
  {
    std::cout << "  BEFORE:"  << num << " ";
    ++num;
    std::cout << "  AFTER:" << num << " ";
  }
  std::cout << std::endl;
}

void BasicClass::lambda() {
  int multiplier = 2;
  auto multiply = [multiplier](int x) { return x * multiplier; };
  int result = multiply(5);
  std::cout << "The result of calling the lambda function multiplier of 2 on 5 is: " << result << std::endl;
  // The following will fail to provide the expected result as the multiplier is not updated on the lambda function
  multiplier = 1;
  std::cout << "The result of calling the lambda function multiplier of 1 on 5 is: " << result << std::endl;
  // The following will fail to provide the expected result as the multiplier is not updated on the lambda function
  multiplier = 1;
  std::cout << "The result of calling the lambda function multiplier of 1 on 5 is: " << result << std::endl;

  
}

void BasicClass::null() {
  int* ptr = nullptr;
  if(!ptr) {
    std::cout << "The provided ptr was null" << std::endl;
  }
  ptr = new int(1);
  if(ptr) {
    std::cout << "The provided ptr value is: " << *ptr << std::endl;
  }
  delete ptr;
}

class LocalClass
{
private:
  /* data */
public:
  LocalClass(int data);
  ~LocalClass();
  void print();
  int data;

  LocalClass(LocalClass&& other) noexcept : data(std::move(other.data)) {
    std::cout << "Move constructor called\n";
    std::cout << "Data value: " << data << std::endl;
    std::cout.flush();
  }
};

LocalClass::LocalClass(int data)
{
  std::cout << "LocalClass instantiation" << std::endl;
  this->data = data;
}

LocalClass::~LocalClass()
{
  std::cout << "LocalClass destruction" << std::endl;
}

void LocalClass::print()
{
    std::cout << "From Print, Data value: " << data << std::endl;
}

void BasicClass::pointers(){
  std::unique_ptr<LocalClass> ptr1(new LocalClass(1));

  ptr1->print();
  std::unique_ptr<LocalClass> ptr2 = std::move(ptr1);
  ptr2->print();

  std::cout << "SHARED:\n";
  std::shared_ptr<LocalClass> sptr1(new LocalClass(1));
  sptr1->print();
  std::shared_ptr<LocalClass> sptr2 = sptr1;
  sptr2->print();

  std::weak_ptr<LocalClass> wptr1 = sptr1;
  if(std::shared_ptr<LocalClass> sptr3 = wptr1.lock()) {
    std::cout << "Transferred weak ptr to shared pointer\n";
  }

}
}  // namespace whynotea::cpp_examples::c_11
