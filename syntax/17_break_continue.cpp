/*
* The break statement can also be used to jump out of a loop.
* The continue statement breaks one iteration (in the loop), 
* if a specified condition occurs, and continues with the next iteration in the loop.
*/

#include <iostream>
#include <ostream>

int main(void) {
    // print odd numbers till 20
    int n = 1;
    while (true) { // will run infinite times if "n" is not checked
        if(n % 2 == 0) {
            n++;
            continue;
        }
        if(n > 20) {
            break; // end the program if n is greater than 20
        }
        std::cout << n << " ";
        n++;
    }
    std::cout << std::endl;
    return 0;
}
