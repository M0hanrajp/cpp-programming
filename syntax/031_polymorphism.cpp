// Inheritance lets us inherit attributes and methods from another class. 
// Polymorphism uses those methods to perform different tasks. This allows us to perform a single action in different ways.
// Base class
#include <iostream>

using namespace std;

class Animal {
  public:
    void animalSound() {
      cout << "The animal makes a sound \n";
    }
};

// Derived class
class Pig : public Animal {
  public:
    void animalSound() {
      cout << "The pig says: wee wee \n";
    }
};

// Derived class
class Dog : public Animal {
  public:
    void animalSound() {
      cout << "The dog says: bow wow \n";
    }
};

int main() {
  Animal myAnimal;
  Pig myPig;
  Dog myDog;

  myAnimal.animalSound();
  myPig.animalSound();
  myDog.animalSound();
  return 0;
}

/*
 * Compile time Polymorphism 035.cpp
 *
 * What:
 * Multiple functions or operators share the same name but differ by signature (parameters) 
 * or template instantiation.
 * Common forms: Function overloading: several add(int,int), add(double,double), etc.
 *               Operator overloading: defining Point operator+(const Point&, const Point&).
 *               Function templates: one template<typename T> T add(T,T) works for any type.
 * Why: You get expressive, natural syntax without runtime overhead.
 *
 * When: Whenever you want the compiler to pick the right routine based on argument types 
 *       or template parameters. Ideal for mathematical libraries, container classes, small 
 *       utility functions.
 *
 * Overload resolution: the compiler matches the call add(2,3.0) to the best‑fitting overload 
 * at compile time. Template instantiation: writing addAny(1,2) generates a addAny<int>(int,int) 
 * behind the scenes. No v‑tables or runtime lookups—every call site is bound to a single function 
 * address during compilation
 */

/* Runtime Polymorphism: 031.cpp
 *
 * What: Runtime polymorphism lets you call derived‑class methods through a
 * base‑class pointer or reference, with the actual override chosen at run time.
 *
 * Why: To write code against a single interface (Device*) while supporting many
 * behaviors (Light::on(), Thermostat::on(), etc.), making your system extensible
 * and decoupled.
 *
 * When Whenever you have a family of related classes sharing an interface and you
 * need to operate on them uniformly (e.g. a container of Device*).
 *
 * Where (in code) In the base class: declare methods virtual (or pure virtual).
 * In derived classes: override those methods.
 * In client code: store or pass around pointers/references to the base, then call
 * the methods.
 *
 * How: At compile time the compiler emits a v‑table for each class. When you do
 * d->on(), it looks up the correct function pointer in that table and invokes the
 * override matching the object’s real type.
 */
