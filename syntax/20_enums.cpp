/* ENUMS
*
* An enum is a special type that represents a group of constants (unchangeable values).
* Syntax:
    enum Level {
      LOW,
      MEDIUM,
      HIGH
    };
* Note that the last item does not need a comma.
* It is not required to use uppercase, but often considered as good practice.
* Enum is short for "enumerations", which means "specifically listed".
* By default, the first item (LOW) has the value 0, the second (MEDIUM) has the value 1, etc.
* If you now try to print myVar, it will output 1, which represents MEDIUM.
* To make more sense of the values, you can easily change them:
    enum Level {
      LOW = 25,
      MEDIUM = 50,
      HIGH = 75
    };
* Note that if you assign a value to one specific item, the next items will update their numbers accordingly:
    enum Level {
      LOW = 5,
      MEDIUM, // Now 6
      HIGH // Now 7
    };
*/

#include <iostream>

int main(void) {
    enum temperatureLevels {
        IDEAL = 28,
        HOT = 38,
        EXTREME = 48
    };

    std::cout << "The temperature in my hometown is : " << IDEAL << "\n";
    std::cout << "The temperature during summer this season was " << HOT << "\n";
    return 0;
}
