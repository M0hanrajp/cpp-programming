/* 
* The while loop loops through a block of code as long as a specified condition is true:
* while (condition) {
  // code block to be executed
}
*/

#include <iostream>
#include <ostream>

int main(void) {
    int _char = 0;
    while (_char < 128) {
        std::cout << "Element :: " << _char << " = " << (char)_char << std::endl;
        _char++;
    }
    return 0;
}
