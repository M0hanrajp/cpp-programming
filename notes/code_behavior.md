### File contains all code behavior of cpp

Format for mentioning something
```bash
File:
Question:
Answer/Reason:
```
### Member Variable Shadowing by Function Parameters in C++
```
File:
(any file with class methods)

Question:
Can member variable (defined private, protected, public) & method parameters have the same name ?

Answer/Reason:
The Standard defines a hierarchy of scopes (block, function, class, namespace, global).
A declaration in an inner scope (e.g. a function parameter or local variable) hides any declaration of the 
same name in an *outer* scope (e.g. a class member) for the remainder of that inner scope.

Unqualified name lookup

When you write an unqualified name (just `re`) inside your member function, the compiler performs unqualified 
name lookup, by searching scopes from innermost outward and stops at the first match.  In your setter

   void setRe(double re) {
     re = re;            // both refer to the parameter `re` (block scope)
   }

the parameter `re` is found *before* the class member `Complex::re`, so the member is never reached unless you qualify it 
(`this->re` or `Complex::re`)
```
#### Where to look in the Standard (examples from cppreference)
Scope and hiding: [https://en.cppreference.com/w/cpp/language/scope](https://en.cppreference.com/w/cpp/language/scope) (“Name hiding” section)
Unqualified lookup: [https://en.cppreference.com/w/cpp/language/unqualified\_lookup](https://en.cppreference.com/w/cpp/language/unqualified_lookup) (“Member function definition” section)

In short, the fact that your data member is `private` has *no* bearing on whether it’s shadowed; any inner declaration with the same name always takes precedence in unqualified lookup.

[1]: https://www.ibm.com/docs/SSLTBW_2.4.0/com.ibm.zos.v2r4.cbclx01/name_hiding.htm "Name hiding (C++ only)"
[2]: https://en.cppreference.com/w/cpp/language/unqualified_lookup "Unqualified name lookup - cppreference.com"
``
