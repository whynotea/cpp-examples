#include <fmt/format.h>
#include <version.h>

#include <iostream>
#include <string>
#include <thread>

#ifdef USE_ADDER
#include <adder.h>
#endif

using namespace std;
#ifdef USE_ADDER
using namespace whynotea::cpp_examples;
#endif

string base_name(string const& path);

class thread_obj {
 public:
  void operator()(int x) {
    for (int i = 0; i < x; i++) {
      cout << "Thread using function object as callable\n";
    }
  }
};

int main(int argc, char* argv[]) {
  cout << base_name(argv[0]) << "Version " << CPP_EXAMPLES_VERSION_MAJOR << "."
       << CPP_EXAMPLES_VERSION_MINOR << "." << CPP_EXAMPLES_VERSION_PATCH
       << "\n";
  cout << "Hello, World!"
       << "\n";
#ifdef USE_ADDER
  cout << "Using Adder Library"
       << "\n";
  cout << "1 + 2 = " << adder::add(1.0f, 2.0f) << "\n";
#else
  cout << "Not using Adder Library"
       << "\n";
#endif

  fmt::print(stdout, "Using fmt provided by vcpkg to print this statement\n");

  thread th2(thread_obj(), 3);

  // auto f = [](int x) thread th3(f, 3);

  th2.join();

  return EXIT_SUCCESS;
}

string base_name(string const& path) {
  return path.substr(path.find_last_of("/\\") + 1);
}
