#include "producer.h"
#include <iostream>
#include <thread>

namespace whynotea::cpp_examples::c_11
{
  Producer::Producer() {}

  Producer::~Producer() {}

  void Producer::start() {
    std::thread producer_thread(&Producer::produce, this);
    producer_thread.detach();
  }

  void Producer::produce() {
    while (true)
    {
      int value = generateValue();
      {
        std::lock_guard<std::mutex> lock(mutex_);
        producerOutput_.push_back(value);
        std::cout << "Producing value of: " << value << std::endl;
        cv_.notify_all();
      }
      std::this_thread::sleep_for(std::chrono::seconds(1));
    }

  }

  int generateValue() {
    return 1;
  }
  std::condition_variable& Producer::cv() {
    return cv_;
  }

  std::optional<int> Producer::provide() {
    std::lock_guard<std::mutex> lock(mutex_);
    if (!producerOutput_.empty()) {
      int value = producerOutput_.front();
      producerOutput_.erase(producerOutput_.begin());
      std::cout << "Providing value of: " << value << std::endl;
      return value;
    } else {
      return std::nullopt;
    }
  }

} // namespace whynotea::cpp_examples::c_11
