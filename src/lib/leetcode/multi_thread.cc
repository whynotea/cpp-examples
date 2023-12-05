#include "multi_thread.h"

#include <atomic>
#include <future>
#include <iostream>
#include <thread>

namespace whynotea::cpp_examples::leetcode::multi_thread {
class HelloFunctionObject {
 public:
  void operator()() const {
    std::cout << "Hello C++ from a function object." << std::endl;
  }
};

void Runner::basicExample() {
  std::vector<std::string> inputs = {
      "Test1",
      "Test2",
      "Test3",
      "Test4",
  };
  static long long int i;
  std::cout << "Running..." << std::endl;
  std::vector<std::thread> threads;
  for (int i = 0; i < inputs.size(); i++) {
    threads.push_back(std::thread(&Runner::print, this, i + 1, inputs[i]));
  }
  for (auto &th : threads) {
    th.join();
  }

  HelloFunctionObject helloFunctionObject;
  std::thread t2(helloFunctionObject);
  t2.join();
  int value = 12;
  std::thread t3(
      [](int value) {
        std::cout << "Hello from a lambda function with value " << value
                  << std::endl;
      },
      value);
  t3.join();
}

class Spinlock {
  std::atomic_flag flag;

 public:
  Spinlock() : flag(ATOMIC_FLAG_INIT) {}

  void lock() {
    while (flag.test_and_set())
      ;
  }

  void unlock() { flag.clear(); }
};

void workOnResource(Spinlock &spin) {
  spin.lock();
  std::cout << "Working..." << std::endl;
  spin.unlock();
}

void Runner::spinlockExample() {
  std::cout << "Spinlock Example..." << std::endl;
  Spinlock spin;
  std::thread t(workOnResource, std::ref(spin));
  std::thread t2(workOnResource, std::ref(spin));
  t.join();
  t2.join();
}

void product(std::promise<int> &&intPromise, int a, int b) {
  intPromise.set_value(a * b);
}

void Runner::promiseFutureExample() {
  int a = 20;
  int b = 10;

  std::cout << std::endl;

  // define the promise
  std::promise<int> prodPromise;

  // get the future
  std::future<int> prodResult = prodPromise.get_future();

  // calculate the result in a separate thread
  std::thread prodThread(product, std::move(prodPromise), a, b);

  // get the result
  std::cout << "20*10= " << prodResult.get() << std::endl;

  std::cout << "AFTER" << std::endl;
  prodThread.join();

  std::cout << std::endl;
}

std::string helloFunction(const std::string &s) {
  using namespace std::string_literals;
  std::string s1 = "abc\0\0def"s;
  return "Hello from " + s1 + " " + s + ".";
}

class Base {
 public:
  virtual void test() { std::cout << "From Base" << std::endl; };
};

class Derived : public Base {
 public:
  void test() {
    std::cout << "From Derived" << std::endl;
    Base::test();
  };
};

void Runner::asyncFutureExample() {
  Base base;
  base.test();
  Derived derived;
  derived.test();
  Base *bptr = &derived;
  bptr->test();
  auto futureFunction = std::async(helloFunction, "function");

  std::cout << futureFunction.get() << std::endl;
}

void Runner::run() {
  // basicExample();
  // spinlockExample();
  // promiseFutureExample();
  asyncFutureExample();
}

void Runner::print(int n, const std::string &str) {
  std::cout << "Printing integer: " << n << std::endl;
  std::cout << "Printing string: " << str << std::endl;
}
}  // namespace whynotea::cpp_examples::leetcode::multi_thread
