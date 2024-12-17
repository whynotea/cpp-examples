#ifndef WHYNOTEA_CPP_EXAMPLES_C_11_CONSUMER_H
#define WHYNOTEA_CPP_EXAMPLES_C_11_CONSUMER_H
#include "producer.h"

namespace whynotea::cpp_examples::c_11
{
 class Consumer
 {
 private:
  Producer& producer_;
 public:
  Consumer(Producer& producer);
  ~Consumer();
  void start();
  void consume();
 };
 
} // namespace whynotea::cpp_examples::c_11


#endif // WHYNOTEA_CPP_EXAMPLES_C_11_CONSUMER_H
