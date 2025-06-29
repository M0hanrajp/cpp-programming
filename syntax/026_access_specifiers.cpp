/* Access specifiers
 * The public keyword is an access specifier. Access specifiers define how the members (attributes and methods) of a class can be accessed.
 * if members are public - which means that they can be accessed and modified from outside the code.
 * public - members are accessible from outside the class
 * private - members cannot be accessed (or viewed) from outside the class
 * protected - members cannot be accessed from outside the class, however, they can be accessed in inherited classes. 
 */

class MyClass {
  public:    // Public access specifier
    int x;   // Public attribute
  private:   // Private access specifier
    int y;   // Private attribute
};

int main() {
  MyClass myObj;
  myObj.x = 25;  // Allowed (public)
  myObj.y = 50;  // Not allowed (private)
  return 0;
}

// Note: It is possible to access private members of a class using a public method inside the same class. 
// The above statement refers to encapsulation
// Note: By default, all members of a class are private if you don't specify an access specifier
/*
26_access_specifiers.cpp: In function ‘int main()’:
26_access_specifiers.cpp:19:9: error: ‘int MyClass::y’ is private within this context
   19 |   myObj.y = 50;  // Not allowed (private)
      |         ^
26_access_specifiers.cpp:13:9: note: declared private here
   13 |     int y;   // Private attribute
      |         ^
*/
