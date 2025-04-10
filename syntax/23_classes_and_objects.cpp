// classes and object
/* in real life, a car is an object. The car has attributes, such as weight and color, and methods, such as drive and brake.
* Attributes and methods are basically variables and functions that belongs to the class. 
* These are often referred to as "class members".
* A class is a user-defined data type that we can use in our program, 
* and it works as an object constructor, or a "blueprint" for creating objects.
*/

#include <iostream>
#include <string>

int main(void) {

    class myCustom {                // the class
        public:                     // access specifier which specifies that members (attributes and methods) of the class are accessible from outside the class.
            int myNum;              // attribute (variable int)
            std::string myString;   // attribute (variable string)
    };

    myCustom myObject; // multiple objects can be created with the class
    myObject.myNum = 8;
    myObject.myString = "Learning oop";
    std::cout << myObject.myNum << " & " << myObject.myString << '\n';

    return 0;
}
