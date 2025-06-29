#include <iostream>
#include <ostream>
using namespace std;

int main(void) {
    // The try statement allows you to define a block of code to be tested for errors while it is being executed.
    try {
      int age = 17;
      if (age >= 18) {
        cout << "Access granted - you are old enough." << endl;
      } else {
        // The throw keyword throws an exception when a problem is detected, which lets us create a custom error.
        throw (age);
      }
    }
    // The catch statement allows you to define a block of code to be executed, if an error occurs in the try block.
    // catch (...)  >> To handle any type of exception
    catch (int myNum) {
      cout << "Access denied - You must be at least 18 years old.\n";
      cout << "Age is: " << myNum << endl;
    }
    return 0;
}
