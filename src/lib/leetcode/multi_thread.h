#ifndef WHYNOTEA_CPP_EXAMPLES_LEETCODE_MULTI_THREAD_H
#define WHYNOTEA_CPP_EXAMPLES_LEETCODE_MULTI_THREAD_H

#include <string>
#include <vector>

namespace whynotea::cpp_examples::leetcode::multi_thread {
class Runner {
 private:
  void basicExample();
  void spinlockExample();
  void promiseFutureExample();
  void asyncFutureExample();

 public:
  Runner(){};
  void run();
  void print(int n, const std::string &str);
};
}  // namespace whynotea::cpp_examples::leetcode::multi_thread

#endif  // WHYNOTEA_CPP_EXAMPLES_LEETCODE_MULTI_THREAD_H
