// https://www.geeksforgeeks.org/cpp/inheritance-in-c/
// Single inheritance
// Multilevel inheritance
// Multiple inheritance
// Hierarchical inheritance
// Hybrid inheritance
#include <iostream>

using namespace std;

// Base class
class MyClass {
  public:
    void myFunction() {
      cout << "Some content in parent class." ;
    }
};

// Another base class
class MyOtherClass {
  public:
    void myOtherFunction() {
      cout << "Some content in another class." ;
    }
};

// Multiple inheritance
// Derived class from 2 different base classes MyClass and MyOtherClass
class MyChildClass: public MyClass, public MyOtherClass {
};

int main() {
  MyChildClass myObj;
  myObj.myFunction();
  myObj.myOtherFunction();
  return 0;
}

// TODO: Learn how we can declare a multiple inheritance for 25.cpp file
