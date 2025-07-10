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

### cpp style string, allowed not allowed.

| Scenario                                         | Allowed? | Notes                                                                           |
| ------------------------------------------------ | :------: | ------------------------------------------------------------------------------- |
| **Initialization from string literal**           |          |                                                                                 |
| `std::string s = "hello";`                       |     ✅    | Copy‑initialization; calls `std::string(const char*)`.                          |
| `std::string s("hello");`                        |     ✅    | Direct initialization; same constructor.                                        |
| **Assignment from string literal**               |          |                                                                                 |
| `std::string s; s = "hello";`                    |     ✅    | Calls `std::string& operator=(const char*)`.                                    |
| **Initialization from another `std::string`**    |          |                                                                                 |
| `std::string s2 = s1;`                           |     ✅    | Copy‑initialization; calls copy constructor.                                    |
| `std::string s2(s1);`                            |     ✅    | Direct initialization; same copy constructor.                                   |
| **Assignment from another `std::string`**        |          |                                                                                 |
| `std::string s1, s2; s2 = s1;`                   |     ✅    | Calls copy‑assignment operator.                                                 |
| **Moves**                                        |          |                                                                                 |
| `std::string s2 = std::move(s1);`                |     ✅    | Directly calls move constructor (leaves `s1` in a valid but unspecified state). |
| `s2 = std::move(s1);`                            |     ✅    | Calls move‑assignment operator.                                                 |
| **Construction from `std::string_view`** (C++17) |          |                                                                                 |
| `std::string s = std::string_view("abc");`       |     ✅    | Calls `std::string(const std::string_view&)`.                                   |
| **Assignment from `std::string_view`** (C++23)   |          |                                                                                 |
| `s = std::string_view("xyz");`                   |     ✅    | Calls `operator=(std::string_view)`.                                            |
| **Conversion to C‑string**                       |          |                                                                                 |
| `const char* p = s;`                             |     ❌    | No implicit conversion; use `s.c_str()` or `s.data()`.                          |
| **Removing const from C‑string view**            |          |                                                                                 |
| `char* p = s.c_str();`                           |     ❌    | `c_str()` returns `const char*`; dropping `const` is ill‑formed.                |
| **Nullptr and literals**                         |          |                                                                                 |
| `std::string s = nullptr;`                       |     ❌    | No constructor from `nullptr_t`; ambiguous with `const char*`.                  |
| **Partial‑buffer initialization**                |          |                                                                                 |
| `std::string s(buf, len);`                       |     ✅    | Constructs from the first `len` chars of `buf` (no `'\0'` needed).              |
| **Substring construction**                       |          |                                                                                 |
| `std::string t(s, pos, count);`                  |     ✅    | Copies `count` chars of `s` starting at `pos`.                                  |
