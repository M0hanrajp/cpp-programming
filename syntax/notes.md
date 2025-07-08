## Notes

### Compilation

- Most C++ compilers can compile C code (with some exceptions), because C++ was designed as a superset of C (more or less).
- But a C compiler (like gcc in -std=c11 mode) will reject C++ syntax and semantics.

## Basics

### What is `::` operator in C++ ?
- The `::` is called scope resolution operator. Can be used like this:
- `class-name :: identifier` & `namespace :: identifier`
- [Stack overflow](https://stackoverflow.com/questions/15649580/using-scope-resolution-operator-in-c), [Microsoft](https://learn.microsoft.com/en-us/cpp/cpp/scope-resolution-operator?view=msvc-170&viewFallbackFrom=vs-2017)
```c
// Online C++ compiler to run C++ program online
#include <iostream>

const int x = 5;

namespace foo {
  const int x = 0;
}

int bar() {
  int x = 1;
  return x;
}

struct Meh {
  static const int x = 2;
};

int main() {
  std::cout << x; // => 5
  {
    int x = 4;
    std::cout << x; // => 4
    {
        int x = 3;
        std::cout << x; // => 3
        std::cout << ::x; // ? => 5
    }
    std::cout << ::x; // => 5, this one looks for x outside the current scope
  }
  std::cout << Meh::x; // => 2, use the definition of x inside the scope of Meh
  std::cout << foo::x; // => 0, use the definition of x inside foo
  std::cout << bar(); // => 1, use the definition of x inside bar (returned by bar)
}
```

### Empty `;` declarations inside class
```c
struct A {
    void foo() { /*…*/ }    // definition ends at the `}`
    void fooBar() { /*…*/ }; // definition ends at `}`, then the `;` is just an empty declaration
};
```
- After the } ends the function body, the extra ; introduces an empty declaration, which does nothing but is syntactically permitted.
- The C++ standard explicitly includes “empty declaration” as one of the forms a declaration can take (it’s literally just a ; with 
  no declarators). Inside a class you can mix access-specifiers, member data, member functions, typedefs, nested types… 
  and—even—empty declarations. [stack-overflow](https://stackoverflow.com/questions/33722551/purpose-of-allowing-unnecessary-semicolons-in-class-definition/33722778), [cppreference](https://en.cppreference.com/w/cpp/language/declarations.html?utm_source=chatgpt.com)

### error: use of deleted function 'DerivedNOTOK::DerivedNOTOK()

```bash
Always initialize default constructor for Dervied class 031_inheritance_constructor_implicit_error.cpp
```
