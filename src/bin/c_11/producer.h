#ifndef WHYNOTEA_CPP_EXAMPLES_C_11_PRODUCER_H
#define WHYNOTEA_CPP_EXAMPLES_C_11_PRODUCER_H

#include <vector>
#include <mutex>
#include <condition_variable>
#include <optional>

namespace whynotea::cpp_examples::c_11
{
class Producer
{
private:
  std::vector<int> producerOutput_;
  std::mutex mutex_;
  std::condition_variable cv_;

  void produce();
  int generateValue();
public:
  Producer();
  ~Producer();
  void start();
  std::condition_variable& cv();
  std::optional<int> provide();
};

} // namespace whynotea::cpp_examples::c_11


#endif // WHYNOTEA_CPP_EXAMPLES_C_11_PRODUCER_H
