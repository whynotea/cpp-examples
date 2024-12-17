#include "consumer.h"
#include <thread>

namespace whynotea::cpp_examples::c_11
{
  
 Consumer::Consumer(Producer& producer) : producer_(producer)
 {
 }
 
 Consumer::~Consumer()
 {
 }

 void Consumer::start(){
  std::thread consumer_thread(&Consumer::consume, this);
  consumer_thread.detach();
 }

 void Consumer::consume() {
  std::unique_lock<std::mut
 } 
} // namespace whynotea::cpp_examples::c_11
