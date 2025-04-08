// There is also a "for-each loop" (also known as ranged-based for loop), 
// which is used exclusively to loop through elements in an array (or other data structures):
// Good to know: The for-each loop was introduced in C++ version 11 (2011).
/* Syntax :
for (type variableName : arrayName) {
  // code block to be executed
}
*/
#include <iostream>

int main(void) {
    int myNumbers[5] = {10, 20, 30, 40, 50};
    for (int i : myNumbers) {
        // the variable itself is the value of the elements in the array
        // no need to use array[i] to get the value here
      std::cout << i << "\n";
    }
    return 0;
}
