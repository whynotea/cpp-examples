#include "scratch.h"
#include "server.h"

#include <iostream>
#include <array>
#include <thread>
#include <chrono>
#include <memory>

namespace whynotea::cpp_examples::c_11::scratch
{
  struct Timer{
    std::chrono::time_point<std::chrono::high_resolution_clock> start,  end;
    std::chrono::duration<float> duration;

    Timer(){
      start = std::chrono::high_resolution_clock::now();
    }
    ~Timer(){
      end = std::chrono::high_resolution_clock::now();
      duration = end - start;

      float ms = duration.count() * 1000.0f;
      std::cout << "Timer took: " << ms << "ms " << std::endl;
    }
  };

  MyClass::MyClass(){
    std::cout << "Constructing MyClass" << std::endl;
  }
  MyClass::~MyClass(){
    std::cout << "Destructing MyClass" << std::endl;
  }
  void MyClass::run(){
    //operators();
    testing();
  }

  void operator_arithmetic() {
    std::cout << "- Arithmetic -" << std::endl << std::endl;

    int first = 1, second = 2;
    std::cout << "First: " << first << ", ";
    std::cout << "Second " << second << std::endl << std::endl;

    std::cout << "First: " << first++ << ", ";
    std::cout << "Second " << second++ << std::endl << std::endl;
    
    std::cout << "First: " << first << ", ";
    std::cout << "Second " << second << std::endl << std::endl;
    
    std::cout << "First: " << ++first << ", ";
    std::cout << "Second " << ++second << std::endl << std::endl;

    std::cout << "Float First/Second wrong: " << first/second << std::endl;
    std::cout << "Float First/Second correct: " << (float)first/second << std::endl << std::endl;

    std::cout << "------------------------" << std::endl << std::endl;
  }

  std::string intToBinaryString(int num, int bits) {
      std::string binaryString;
      for (int i = bits - 1; i >= 0; i--) {
          binaryString += (num >> i & 1) + '0';
      }
      return binaryString;
  }

  void operator_bitwise() {
    std::cout << "- Bitwise -" << std::endl << std::endl;

    int first = 1, second = 2;
    
    std::cout << "First: " << intToBinaryString(first, 4) << ", ";
    std::cout << "Second " << intToBinaryString(second, 4) << std::endl << std::endl;

    std::cout << "AND: " << intToBinaryString(first & second, 4) << ", ";
    std::cout << "OR " << intToBinaryString(first | second, 4) << std::endl << std::endl;

    std::cout << "XOR: " << intToBinaryString(first ^ second, 4) << ", ";
    std::cout << "~ " << intToBinaryString(~(first & second), 4) << std::endl << std::endl;
    
    first = 5, second = 3;
    std::cout << "First: " << intToBinaryString(first, 4) << ", ";
    std::cout << "Second " << intToBinaryString(second, 4) << std::endl << std::endl;

    std::cout << "OR " << intToBinaryString(first | second, 4) << ", ";
    std::cout << "XOR: " << intToBinaryString(first ^ second, 4) << std::endl << std::endl;

    std::cout << "------------------------" << std::endl << std::endl;
  }

  void operator_ternary() {
    std::cout << "- Ternary -" << std::endl << std::endl;

    int first = 1, second = 2;
    std::cout << "First: " << first << ", ";
    std::cout << "Second " << second << std::endl;

    auto result1 = first > second ? first : second;
    auto result2 = first < second ? first : second;
    std::cout << "First > Second: " << result1 << std::endl;
    std::cout << "First < Second: " << result2 << std::endl << std::endl;
    std::cout << "------------------------" << std::endl << std::endl;
  }

  void operator_sizeof() {
    std::cout << "- Sizeof -" << std::endl << std::endl;

    int first = 1;
    char second = 'a';
    std::cout << "First: " << first << ", ";
    std::cout << "Second " << second << std::endl;

    size_t s_first = sizeof(first);
    size_t s_second = sizeof(second);
    std::cout << "Sizeof(First): " << s_first << std::endl;
    std::cout << "Sizeof(Second): " << s_second << std::endl << std::endl;
    std::cout << "------------------------" << std::endl << std::endl;
  }

  void operator_switch(int case_value) {
    std::cout << "- Switch -" << std::endl;

    std::cout << "Value: " << case_value << std::endl;

    switch(case_value) {
      case 1:
        std::cout << "Chosen value is 1";
        break;
      case 2:
        std::cout << "Chosen value is 2";
        break;
      default:
        std::cout << "Chosen value is not handled";
    }
    std::cout << "------------------------" << std::endl;
  }

  class Point {
    public:
      Point(int x = 0, int y = 0) :x(x), y(y){
        coordinates[0] = x;
        coordinates[1] = y;
      };
      Point operator+(const Point& rhs) {
        Point p;
        p.x = x+rhs.x;
        p.y = y+rhs.y;
        return p;
      }
      Point operator-(const Point& rhs) {
        Point p;
        p.x = x-rhs.x;
        p.y = y-rhs.y;
        return p;
      }
      Point operator-() {
        return Point(-x, -y);
      }
      int& operator[](int pos) {
        if ( pos <= 0) {
          return x;
        }
        if ( pos >= 1) {
          return y;
        }
        return x;
      }
      void print() {
        std::cout << "x: " << x << ", ";
        std::cout << "y: " << y << std::endl;
      }
    private:
      int x, y;
      int coordinates[2];
    friend std::istream& operator >> (std::istream& input, Point& obj);
    friend std::ostream& operator << (std::ostream& output, Point& obj);
  };

  std::istream& operator >> (std::istream& input, Point& obj) {
    input >> obj.x;
    return input;
  }
  std::ostream& operator << (std::ostream& output, Point& obj) {
    output << obj.x;
    return output;
  }
  void operator_overload() {
    std::cout << "- Overload -" << std::endl;
    Point p1(1,2), p2(3,4);
    Point p3 = p1 + p2;
    Point p4 = p2 - p1;
    p1.print();
    p2.print();
    p3.print();
    p4.print();
    Point p5 = -p4;
    p5.print();
    std::cout << "[0] = " << p5[0] << std::endl;
    std::cout << "[1] = " << p5[1] << std::endl;
    p1.print();
    std::cout << "[0] = " << p1[0] << std::endl;
    std::cout << "[1] = " << p1[1] << std::endl;

    std::cin >> p1;
    std::cout << "P1.x: " << p1 << std::endl;
    std::cout << "------------------------" << std::endl;
  }

  class TestAssignment {
    public:
      TestAssignment(int x = 0) :x(new int(x)) {}
      ~TestAssignment() { delete x; }
      void setX(int val) { *x = val; }
      void print() {
        std::cout << "x: " << *x << std::endl;
      }
      TestAssignment& operator=(const TestAssignment& rhs) {
        if(this != &rhs) {
          *x = *rhs.x;
        }
        return *this;
      }
      TestAssignment(TestAssignment& rhs) {
        x = new int(*rhs.x);
      }
    private:
      int* x;
  };

  class Pound {
    public:
      Pound(int p = 0) : pound(p) {};

    friend std::ostream& operator << (std::ostream& output, Pound& obj);

    private:
      int pound;
  };

  class Dollar {
    public:
      Dollar(int d = 0) : dollar(d) {};
      operator Pound() {
        return Pound(dollar * 10);
      }

      void * operator new(size_t size) {
        std::cout << "Overloaded new operator with size: " << size << std::endl;
        void * p = malloc(size);
        return p;
      }
      void operator delete(void * p) {
        std::cout << "Overloaded delete operator" << std::endl;
        free(p);
      }
      void setDollars(int d) {
        dollar = d;
      }
    private:
      int dollar;
    
    friend std::ostream& operator << (std::ostream& output, Dollar& obj);
  };

  std::ostream& operator << (std::ostream& output, Dollar& obj) {
    output << obj.dollar;
    return output;
  }

  std::ostream& operator << (std::ostream& output, Pound& obj) {
    output << obj.pound;
    return output;
  }
  void MyClass::operators() {
    operator_arithmetic();
    operator_bitwise();
    operator_ternary();
    operator_sizeof();
    std::vector<int> case_values = {1,2,3};
    for(int case_value: case_values) {
      operator_switch(case_value);
    }
    // operator_overload();
    TestAssignment t1(1);
    TestAssignment t2;
    t2 = t1;
    t2.setX(2);
    t1.print();
    t2.print();
    TestAssignment t3 = t2;
    t3.print();
    t3 = t1;
    t3.print();

    Dollar dollars(10);
    Pound pounds;
    pounds = dollars;
    std::cout << "Dollars: " << dollars << std::endl;
    std::cout << "Pounds: " << pounds << std::endl;
    std::unique_ptr<Dollar> p_dollar = std::make_unique<Dollar>();
    p_dollar->setDollars(10);
    std::cout << "Dollars: " << *p_dollar << std::endl;
  }

  void compare(int x, int y) {
    if(x > y) {
      std::cout << x << " is greater than " << y << '\n';
    } else if (x < y) {
      std::cout << x << " is less than " << y << '\n';
    } else {
      std::cout << x << " is equal to " << y << '\n';
    }
  }
  void MyClass::testing() {
    std::cout << "Enter a number: ";
    int x{};
    std::cin >> x;

    std::cout << "Enter another number: ";
    int y{};
    std::cin >> y;

    compare(x, y);
  }
} // namespace whynotea::cpp_examples::c_11::scratch
