#include <leetcode/multi_thread.h>
#include <leetcode/two_sum.h>

#include <array>
#include <cstdlib>
#include <iostream>
#include <tuple>
#include <vector>
using namespace whynotea::cpp_examples::leetcode;

using Test = tuple<vector<int>, int>;

std::ostream& operator<<(std::ostream& out, const std::vector<int>& v) {
  if (!v.empty()) {
    out << '[';
    for (vector<int>::size_type i = 0; i < v.size(); ++i) {
      out << v[i];
      if (i != v.size() - 1) {
        out << ',';
      }
    }
    out << ']';
  }
  return out;
}

void multithread() {
  multi_thread::Runner runner = multi_thread::Runner();
  runner.run();
}

void twosum() {
  two_sum::Solution solution = two_sum::Solution();
  array<Test, 3> tests{
      Test{{2, 7, 11, 15}, 9},
      Test{{3, 2, 4}, 6},
      Test{{3, 3}, 6},
  };
  for (auto test : tests) {
    vector<int> nums;
    int target;
    tie(nums, target) = test;
    auto result = solution.twoSum(nums, target);
    std::cout << "TEST: " << nums << ", RESULT: " << result << "\n";
  }
}

int main(int argc, char const* argv[]) {
  multithread();
  // twosum();
  return EXIT_SUCCESS;
}
