#include <iostream>
#include <string>
using namespace std;

// https://stackoverflow.com/questions/28002/regular-cast-vs-static-cast-vs-dynamic-cast
// https://stackoverflow.com/questions/332030/when-should-static-cast-dynamic-cast-const-cast-and-reinterpret-cast-be-used
// https://madhawapolkotuwa.medium.com/understanding-static-and-dynamic-casting-in-c-b73cf3f92ec2

class Base {
    public:
    virtual string name(void) {return "Base";}
};

class DerivedA : public Base {
    public:
    string name(void) override {return "DerivedA";}
    void onlyA() { cout << "Im A" << endl;}
};

class DerivedB : public Base {
    public:
    string name(void) override {return "DerivedB";}
    void onlyB() { cout << "Im B" << endl;}
};

int main(void) {
    // up-cast is always safe,
    DerivedA *a = new DerivedA;
    Base *b = static_cast<Base *>(a); // will print “DerivedA”
    cout << b->name() << endl;
    /* Whenever you call a virtual method through a base pointer/reference, 
     * C++ looks up the actual (dynamic) type’s v‑table. Since the object is 
     * still a DerivedA, you call DerivedA::name().
     */

    // Down‑cast with static_cast (unsafe)
    Base*   b1 = new DerivedA;
    // static cast DerivedA to the type DerivedA
    DerivedA* a1 = static_cast<DerivedA*>(b1);
    a1->onlyA();                          // OK
    Base*   b2 = new DerivedB;
    // static cast DerivedB to the type DerivedA
    DerivedA* a2 = static_cast<DerivedA*>(b2);
    a2->onlyA();                       // compiles, but UB at run‑time! (no runtime checks)

    //Down‑cast with dynamic_cast (safe, RTTI‑checked)
    Base*   b3 = new DerivedA;
    if (auto* a3 = dynamic_cast<DerivedA*>(b3))
        a3->onlyA();                      // OK
    else
        std::cout << "b3 wasn’t a DerivedA\n";
    Base*   b4 = new DerivedB;
    // dynamic cast DerivedB to the type DerivedA
    if (auto* a4 = dynamic_cast<DerivedA*>(b4))
        a4->onlyA();
    else
        std::cout << "b4 wasn’t a DerivedA\n";  // error detected

    // cross cast
    DerivedB* bCast = new DerivedB;
    Base*     b5    = bCast;
    b5 = static_cast<DerivedA*>(b5); // ⇒ compiles, UB
    b5 = dynamic_cast<DerivedA*>(b5); // ⇒ nullptr
    b5->name(); // seg fault
    return 0;
}
