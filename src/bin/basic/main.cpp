#include <iostream>
#include <string>
#include <adder.h>
#include <cpp-examples-config.h>

using namespace std;

string base_name(string const & path);

int main(int argc, char* argv[])
{
  cout << base_name(argv[0]) << "Version " << CPP_EXAMPLES_VERSION_MAJOR << "." << CPP_EXAMPLES_VERSION_MINOR << "." << CPP_EXAMPLES_VERSION_PATCH << "\n";
  cout << "Hello, World!"
       << "\n";
  cout << "1 + 1 = " << add(1.0f, 1.0f) << "\n";

  return EXIT_SUCCESS;
}

string base_name(string const & path)
{
  return path.substr(path.find_last_of("/\\") + 1);
}
