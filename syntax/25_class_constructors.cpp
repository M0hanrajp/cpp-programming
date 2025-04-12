// CPP constructors
/* 
* A constructor in C++ is a special method that is automatically called when an object of a class is created.
* To create a constructor, use the same name as the class, followed by parentheses (): 
* Note: The constructor has the same name as the class, it is always public, and it does not have any return value.
*/

#include <iostream>
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
            operandA = *a;
            operandB = *b;
            addition = *a + *b;
            substraction = *a - *b;
            multiplication = *a * *b;
            divison = *a / *b;
        };
};

class calculatorDemo_da {
    public:
        int someth;
        int ada;
};

class calculatorDemo_modulo {
    public:
        int operandA;
        int operandB;
        int modulo;
        calculatorDemo_modulo(int *a, int *b);
};

calculatorDemo_modulo::calculatorDemo_modulo(int *a, int *b) {
    operandA = *a;
    operandB = *b;
    modulo = operandA % operandB;
}

int main(void) {
    int a = 8, b = 8;
    calculatorDemo operations(&a, &b);
    calculatorDemo_modulo modulo(&a, &b);
    std::cout << "Addition : " << operations.addition << std::endl;
    std::cout << "Substraction : " << operations.substraction << std::endl;
    std::cout << "Multiplication : " << operations.multiplication << std::endl;
    std::cout << "Division : " << operations.divison << std::endl;
    std::cout << "Modulo : " << modulo.modulo << std::endl;
    return 0;
}
