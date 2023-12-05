#include "two_sum.h"

#include <iostream>
#include <map>

using namespace std;

namespace whynotea::cpp_examples::leetcode::two_sum {
vector<int> Solution::twoSum(vector<int>& nums, int target) {
  map<int, int> m;
  for (int i = 0; i < nums.size(); i++) {
    auto num = nums.at(i);
    int complement = target - num;
    auto match = m.find(complement);
    if (match != m.end()) {
      return vector<int>{match->second, i};
    }
    m[num] = i;
  }
  return {};
}

}  // namespace whynotea::cpp_examples::leetcode::two_sum
