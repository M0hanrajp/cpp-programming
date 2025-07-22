// When you know exactly how many times you want to loop through a block of code, use the for loop instead of a while loop:
/* Syntax 
for (statement 1; statement 2; statement 3) {
  // code block to be executed
}
Statement 1 is executed (one time) before the execution of the code block.
Statement 2 defines the condition for executing the code block.
Statement 3 is executed (every time) after the code block has been executed.
*/
#include <iostream>

int main(void) {
    // print even numbers less than 20
    for(int i = 2; i < 21; i += 2) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}

/*
Other examples::
// Outer loop
for (int i = 1; i <= 2; ++i) {
  cout << "Outer: " << i << "\n"; // Executes 2 times

  // Inner loop
  for (int j = 1; j <= 3; ++j) {
    cout << " Inner: " << j << "\n"; // Executes 6 times (2 * 3)
  }
}

*/
