#include "basic_class.h"
#include "arrays.h"
#include "scratch.h"
#include "server.h"
#include "client.h"
#include "fix_msg.h"
#include <thread>
#include <iostream>

using namespace whynotea::cpp_examples::c_11;

int main(int argc, char const* argv[]) {
  // BasicClass myClass;
  // myClass.print();
  // myClass.range();
  // myClass.lambda();
  // myClass.null();
  // myClass.pointers();

  // arrays myArray;
  // myArray.run();
  // myArray.run2();

  scratch::MyClass myClass;
  myClass.run();

#ifdef SERVER
  using namespace std::literals::chrono_literals;

  // Instantiate a server
  server::Server myServer(9090);
  std::thread server(&server::Server::start, &myServer);

  // Instantiate a client
  client::Client myClient("localhost",9090);
  std::thread client(&client::Client::start, &myClient);

  // Build a message for sending from the client
  fix::FixMsg myMessage;

  const char* myFixMsg = "8=FIX.4.4;9=123;35=D;49=ABC;56=DEF;55=IBM;54=1;38=100;40=1;44=200.00;59=0;60=20130913-10:15:00;10=000";
  //const char * myContent = "Hello from Client\n";
  myMessage.body_length(std::strlen(myFixMsg));
  std::memcpy(myMessage.body(), myFixMsg, myMessage.body_length());
  myMessage.encode_header();
  myClient.write(myMessage);

  // Wait a second to complete the send
  std::this_thread::sleep_for(1s);

  // Close the client and then the server
  myClient.close();
  myServer.closeConnections();
  std::this_thread::sleep_for(1s);
  myServer.stop();

  // Join the client and server threads to make sure they've completed
  std::cout << "Waiting on tear down..." << std::endl;
  client.join();
  server.join();
  std::cout << "Tear down completed." << std::endl;
#endif
  return 0;
}
