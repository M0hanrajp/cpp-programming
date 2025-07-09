#include <iostream>
using namespace std;

// BaseOK: no user-defined constructors → implicit BaseOK()
class BaseOK {
public:
    int x = 8;  // default member initializer
    // No constructors declared by user:
    // compiler-provided default constructor (BaseOK() = default)
    // when: when no constructors are user‑declared, the compiler will create ClassName().
    // The rule of thumb
    // Every constructor (explicit or implicit) of a derived class must initialize each of its direct base classes.
    // If you omit the initializer for a base, the compiler injects a call to that base’s default (no‑arg) constructor.
    // If that default constructor doesn’t exist, the derived constructor can’t be formed and is therefore deleted by the compiler.
};

// DerivedOK: inherits from BaseOK which has a default constructor
class DerivedOK : public BaseOK {
public:
    int y = 8;  // default member initializer
    // No constructors declared by user:
    // compiler-provided default constructor (DerivedOK() = default)
    // The generated DerivedOK() calls BaseOK() first, then initializes y
};

// BaseNOTOK: user-defined constructor suppresses implicit default
class BaseNOTOK {
public:
    int x = 88;
    // Because a constructor is declared, no implicit BaseNOTOK() is generated
    BaseNOTOK(int value)
      : x(value)   // initialize x from the argument
    {
    }
};

// DerivedNOTOK: implicitly-declared default constructor is defined as deleted
class DerivedNOTOK : public BaseNOTOK {
public:
    int z = 1;
    // Compiler implicitly declares DerivedNOTOK():
    //     DerivedNOTOK() : BaseNOTOK() { }
    // but BaseNOTOK() doesn't exist, so DerivedNOTOK() is deleted → compile error
    // Even when it’s implicitly declared, the default constructor might be defined as deleted if it can’t initialize something:
};

class DerviedNOTOK_OK : public BaseNOTOK {
public:
    int z = 1;
    /* Inherit all the constructor from BaseNOTOK
     * Please import (i.e. ‘inherit’) all of Base’s constructors into Derived.
     * using Base::Base;, you get exactly the same constructors that Base has, except they now construct a Derived object:
     * After the using‑declaration, Derived also has a constructor with signature Derived(int).
     */
    using BaseNOTOK::BaseNOTOK;
};

int main() {
    DerivedOK ok;  // OK: calls BaseOK() then DerivedOK()
    cout << "ok.x = " << ok.x << ", ok.y = " << ok.y << endl;

    // DerivedNOTOK notOK;   // error: use of deleted function 'DerivedNOTOK::DerivedNOTOK()'
    DerviedNOTOK_OK dok(3);  // no errors, but can't do dok; (this again looks for default no-arg constructor
    return 0;
}
