#include <fmt/format.h>
#include <version.h>

#include <iostream>
#include <string>

#ifdef USE_ADDER
#include <adder.h>
#endif

using namespace std;

string base_name(string const& path);

int main(int argc, char* argv[]) {
  cout << base_name(argv[0]) << "Version " << CPP_EXAMPLES_VERSION_MAJOR << "."
       << CPP_EXAMPLES_VERSION_MINOR << "." << CPP_EXAMPLES_VERSION_PATCH
       << "\n";
  cout << "Hello, World!"
       << "\n";
#ifdef USE_ADDER
  cout << "Using Adder Library"
       << "\n";
  cout << "1 + 1 = " << add(1.0f, 1.0f) << "\n";
#else
  cout << "Not using Adder Library"
       << "\n";
#endif

  fmt::print(stdout, "Using fmt provided by vcpkg to print this statement\n");

  return EXIT_SUCCESS;
}

string base_name(string const& path) {
  return path.substr(path.find_last_of("/\\") + 1);
}
