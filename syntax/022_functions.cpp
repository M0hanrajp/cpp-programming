/* Functions

// Function declaration
void myFunction();

// The main method
int main() {
  myFunction();  // call the function
  return 0;
}

// Function definition
void myFunction() {
  cout << "I just got executed!";
}

*/

#include <iostream>
#include <ostream>
#include <string>

// check pass by reference
void checkFu(std::string &str) {
    std::cout << "From checkFu() String :: " << str << " & address: " << &str << std::endl;
    // modified value
    str += " in the way...hmmmm";
}

// Pass an array
void passArr(std::string q[4], int *z) {
// Declaring the parameter as std::string q[4] causes the array to decay to a pointer.
// thus the range-based for loop lacks the size information needed to iterate over the array.
/*     for (std::string x : q) {
        std::cout << x;
    } */
    for (int i = 0; i < 4; i++) {
        std::cout << q[i] << " " << z[i] << std::endl;
    }
    // Warning:
    // using length(), size() functions for object type string
    // will give the length of the string, not the whole array.
}

int main(void) {
    std::string _str = "Something";
    std::cout << "From main() String :: " << _str << " & address: " << &_str << std::endl;
    // Both _str and str from checkFU print out the same address
    checkFu(_str);
/*  From main() String :: Something & address: 0x7ffc82e9de80
    From checkFu() String :: Something & address: 0x7ffc82e9de80
*/  // check if _str was modified
    std::cout << _str << std::endl;


    // array
    std::string q[4] = {"ydo", "yo", "oy", "oy"};
    int z[4] = {1, 2, 3, 4};
    passArr(q, z);
    return 0;
}

/* notes

* Parameters are specified after the function name, inside the parentheses. 
* You can add as many parameters as you want, just separate them with a comma:

void functionName(parameter1, parameter2, parameter3) {
  // code to be executed
}

* You can also use a default parameter value, by using the equals sign (=).
* If we call the function without an argument, it uses the default value ("Norway"):

Example
void myFunction(string country = "Norway") {
  cout << country << "\n";
}

int main() {
  myFunction("Sweden");
  myFunction("India");
  myFunction();
  myFunction("USA");
  return 0;
}

// Sweden
// India
// Norway
// USA

* If you want your function to return a value:

data_type function_name(parameter1...) {
    return data_type;
}

* in main you can do cout << data_type;
*
*
* Function Overloading
With function overloading, multiple functions can have the same name with different parameters:
int plusFuncInt(int x, int y) {
  return x + y;
}

double plusFuncDouble(double x, double y) {
  return x + y;
}

int main() {
  int myNum1 = plusFuncInt(8, 5);
  double myNum2 = plusFuncDouble(4.3, 6.26);
  cout << "Int: " << myNum1 << "\n";
  cout << "Double: " << myNum2;
  return 0;
}

Note: Multiple functions can have the same name as long as the number and/or type of parameters are different.
*/
