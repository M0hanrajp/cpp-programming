/* 
 * The switch expression is evaluated once
 * The value of the expression is compared with the values of each case
 * If there is a match, the associated block of code is executed
 * The break and default keywords are optional, and will be described later in this chapter 
 * When C++ reaches a break keyword, it breaks out of the switch block.
 * This will stop the execution of more code and case testing inside the block.
 * The default keyword specifies some code to run if there is no case match:
 * */
#include <iostream>
using namespace std;
int main(void) {
    int day = 4;
    switch (day) {
      case 6:
        cout << "Today is Saturday";
        break;
      case 7:
        cout << "Today is Sunday";
        break;
      default:
        cout << "Looking forward to the Weekend";
    }
    return 0;
}
