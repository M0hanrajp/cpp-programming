// In C++, it is possible to inherit attributes and methods from one class to another. 
// We group the "inheritance concept" into two categories:
// derived class (child) - the class that inherits from another class
// base class (parent) - the class being inherited from
// To inherit from a class, use the : symbol.
//
// The capability of a class to derive properties and characteristics from another class is called Inheritance.
// Why And When To Use "Inheritance"?
// It is useful for code reusability: reuse attributes and methods of an existing class when you create a new class.

#include <iostream>
#include <string>

using namespace std;

// Base class
class Vehicle {
  public:
    string brand = "Ford";
    void honk() {
      cout << "Tuut, tuut! \n" ;
    }
};

// Derived class level 1 from base Vehicle
class Car: public Vehicle {
  public:
    string model = "Mustang";
};

// NOTE: Derived class level 2 from base Car (multilevel inheritance)
class Mustang : public Car {
  public:
    // Car specific details
    string rimSize = "Rim size: 21'";
    string isCustomBodyKit = "Car equipped with custom body kit";
};

int main() {
  Mustang myCar;
  myCar.honk();
  cout << myCar.brand + " " + myCar.model << endl;
  cout << myCar.rimSize << endl;
  cout << myCar.isCustomBodyKit << endl;
  return 0;
}

/* 
 * A class can also be derived from one class, which is already derived from another class.
// Base class (parent)
class MyClass {
  public:
    void myFunction() {
      cout << "Some content in parent class." ;
    }
};

// Derived class (child)
class MyChild: public MyClass {
};

// Derived class (grandchild)
class MyGrandChild: public MyChild {
};

int main() {
  MyGrandChild myObj;
  myObj.myFunction();
  return 0;
}
 */
