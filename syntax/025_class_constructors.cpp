// CPP constructors
/* 
* A constructor in C++ is a special method that is automatically called when an object of a class is created.
* To create a constructor, use the same name as the class, followed by parentheses (): 
* Note: The constructor has the same name as the class, it is always public, and it does not have any return value.
*
* rules for creating constructors
* a. Only constructors can have the same name as the class.
*   a.a this is also like special member function, but it does not have any return type, not even void.
* b. They can be declared outside the class or inside the class.
* c. they can have default parameters.
* d. every constructor is a member function, but not every member function is a constructor.
*/

#include <iostream>
#include <ostream>
class calculatorDemo { // class
    public: // access specifier
        int operandA; // attributes
        int operandB;
        int addition;
        int substraction;
        int multiplication;
        int divison;
        // constructor method
        calculatorDemo(int *a, int *b) { // constructor defined inside class
            //operandA = *a;
            //operandB = *b;
            addition = *a + *b;
            substraction = *a - *b;
            multiplication = *a * *b;
            divison = *a / *b;
        };
        // constructor overload
        calculatorDemo(double *a, double *b) {
            addition = *a + *b;
            substraction = *a - *b;
            multiplication = *a * *b;
            divison = *a / *b;
        };
};

class calculatorDemo_modulo {
    public:
        int operandA;
        int operandB;
        int modulo;
        calculatorDemo_modulo(int *a, int *b);
};

// constructor defined outside of it's class's definition
calculatorDemo_modulo::calculatorDemo_modulo(int *a, int *b) {
    operandA = *a;
    operandB = *b;
    modulo = operandA % operandB;
}

int main(void) {
    int a = 8, b = 8;
    calculatorDemo intOperations(&a, &b);
    calculatorDemo_modulo modulo(&a, &b);
    std::cout << "Using int data types" << std::endl;
    std::cout << "Addition : " << intOperations.addition << std::endl;
    std::cout << "Substraction : " << intOperations.substraction << std::endl;
    std::cout << "Multiplication : " << intOperations.multiplication << std::endl;
    std::cout << "Division : " << intOperations.divison << std::endl;
    std::cout << "Modulo : " << modulo.modulo << std::endl;
    double aa = 4.7, bb = 7.2;
    calculatorDemo doubleOperations(&aa, &bb);
    std::cout << "Using double data types, only int is reflected in io as class members are int" << std::endl;
    std::cout << "Addition : " << doubleOperations.addition << std::endl;
    std::cout << "Substraction : " << doubleOperations.substraction << std::endl;
    std::cout << "Multiplication : " << doubleOperations.multiplication << std::endl;
    std::cout << "Division : " << doubleOperations.divison << std::endl;
    return 0;
}
