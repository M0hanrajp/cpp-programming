/* Use if to specify a block of code to be executed, if a specified condition is true
 * Use else to specify a block of code to be executed, if the same condition is false
 * Use else if to specify a new condition to test, if the first condition is false
 * Use switch to specify many alternative blocks of code to be executed 
 * */
#include <iostream>
#include <ostream>

int main(void) {

    // the following program is to check if you need to carry umbrella
    bool isRaining = false;
    bool isOvercast = false;
    char userInput = 0;
    std::cout << "You are in home, you are preparing to go to office\n"
              << "Is it raining Y/N ? :: "; std::cin >> userInput;
    isRaining = (userInput == 'y' || userInput == 'Y') ? 1 : 0;

    if(isRaining) {
        std::cout << "It's raining today, take umbrella!\n";
    } 
    if(!isRaining) {
        std::cout << "Is it cloudy/overcast Y/N ? :: "; std::cin >> userInput;
        isOvercast = (userInput == 'y' || userInput == 'Y') ? 1 : 0;
    } 
    if(isOvercast) {
        std::cout << "It might rain today, take umbrella!\n";
    } else if(!isOvercast) {
        std::cout << "It's sunny, no need for umbrella!\n";
    } else {
        std::cout << "User inputs incorrect 4XX\n";
    }
    return 0;
}

/* Less than: a < b
Less than or equal to: a <= b
Greater than: a > b
Greater than or equal to: a >= b
Equal to a == b
Not Equal to: a != b */

/* 
if (condition) {
  // block of code to be executed if the condition is true
} else {
  // block of code to be executed if the condition is false
} 

if (condition1) {
  // block of code to be executed if condition1 is true
} else if (condition2) {
  // block of code to be executed if the condition1 is false and condition2 is true
} else {
  // block of code to be executed if the condition1 is false and condition2 is false
}

Short Hand If...Else (Ternary Operator)
There is also a short-hand if else, which is known as the ternary operator because it consists of three operands.

variable = (condition) ? expressionTrue : expressionFalse;

*/
