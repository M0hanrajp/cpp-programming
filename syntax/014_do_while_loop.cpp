/* The do/while loop is a variant of the while loop. 
* This loop will execute the code block once, before checking if the condition is true, 
* then it will repeat the loop as long as the condition is true.
*/
/* Synatx::
do {
  // code block to be executed
}
while (condition);
*/

#include <iostream>
#include <ostream>

int main(void) {
    int number = 12345;
    int revNumber = 0;
    do {
        revNumber = revNumber * 10 + number % 10;
        number /= 10;
    }while(number);
    std::cout << "Reversed number is = " << revNumber << std::endl;
    return 0;
}
