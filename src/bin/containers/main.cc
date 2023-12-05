#include <algorithm>
#include <array>
#include <deque>
#include <iostream>
#include <map>
#include <memory>
#include <mutex>
#include <set>
#include <stack>
#include <thread>
#include <vector>

using namespace std;

template <typename T>
void printMap(const T& container) {
  cout << "[";
  const int s = container.size();
  int i{0};
  for (auto item : container) {
    ++i;
    if (i == s) {
      cout << "{" << item.first << "," << item.second << "}";
    } else {
      cout << "{" << item.first << "," << item.second << "}, ";
    }
  }
  cout << "]" << endl;
}

template <typename T>
void print(const T& container) {
  cout << "[";
  const int s = container.size();
  int i{0};
  for (auto item : container) {
    ++i;
    if (i == s) {
      cout << item;
    } else {
      cout << item << ", ";
    }
  }
  cout << "]" << endl;
}

struct SetStruct {
  int first;
  int second;
};

bool setComparator(const int& first, const int& second) {
  return first < second;
}

bool setComparator2(const SetStruct& first, const SetStruct& second) {
  return first.first < second.first;
}

void sets() {
  set<int, decltype(&setComparator)> mySet(setComparator);
  mySet.insert(2);
  mySet.insert(4);
  mySet.insert(1);
  print(mySet);
  auto iter = mySet.find(4);
  if (iter == mySet.end()) {
    cout << "Failed to find value 6" << endl;
  } else {
    cout << "Found " << *iter << endl;
  }
  auto value = mySet.extract(1);
  print(mySet);

  set<SetStruct, decltype(&setComparator2)> mySet2(setComparator2);
  mySet2.insert(std::move(SetStruct({1, 2})));
  mySet2.insert(std::move(SetStruct({1, 3})));
  mySet2.insert(std::move(SetStruct({2, 2})));

  for (auto s : mySet2) {
    cout << "[" << s.first << "," << s.second << "]" << endl;
  }
}

void deques() {
  deque<int> myDeque = deque<int>{1, 2, 3, 2};
  print(myDeque);
  printf("First: %d\n", myDeque.front());
  myDeque.pop_front();
  printf("New First: %d\n", myDeque.front());
  myDeque.push_back(4);
  print(myDeque);
  cout << myDeque[1] << endl;
}

void vectors() {
  vector<int> myVector = vector<int>{1, 2, 3, 4, 2};
  print(myVector);
  auto val = myVector.front();
  cout << "Front: " << val << endl;
  val = myVector.back();
  cout << "Back: " << val << endl;
  sort(myVector.begin(), myVector.end());
  print(myVector);
  cout << myVector[1] << endl;
}

void arrays() {
  array<int, 4> myArray{{1, 2, 3, 2}};
  print(myArray);
  sort(myArray.begin(), myArray.end());
  print(myArray);
}

void maps() {
  map<int, int> myMap{{1, 1}, {3, 4}, {2, 3}};
  printMap(myMap);
  myMap[3] = 2;
  printMap(myMap);
}

template <typename T>
void processStack(T& myStack) {
  while (!myStack.empty()) {
    cout << myStack.top() << endl;
    myStack.pop();
  }
}

void processPtrStack(unique_ptr<stack<int>>& stackPtr) {
  while (!(*stackPtr).empty()) {
    cout << (*stackPtr).top() << endl;
    (*stackPtr).pop();
  }
}

void stacks() {
  stack<int> myStack{{1, 2, 3, 4}};
  myStack.push(3);
  processStack(myStack);
  myStack.push(2);
  unique_ptr<stack<int>> myPtr = make_unique<stack<int>>(std::move(myStack));
  myPtr->push(2);
  cout << endl;
  processPtrStack(myPtr);
}

mutex myMutex;
int sharedValue{0};

void incrementor(int inc) {
  myMutex.lock();
  sharedValue += inc;
  sharedValue *= inc;
  myMutex.unlock();
}

void threads() {
  thread t1 = thread(incrementor, 2);
  thread t2 = thread(incrementor, 3);
  t1.join();
  t2.join();
  cout << "The value of shared: " << sharedValue << endl;
}

int main(int argc, const char* argv[]) {
  cout << "Containers" << endl;
  // sets();
  // deques();
  // vectors();
  // arrays();
  // maps();
  // stacks();
  threads();
  return 0;
}
