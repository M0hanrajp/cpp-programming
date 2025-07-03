// Methods are functions that belongs to the class.
/* 
* There are two ways to define functions that belongs to a class:
* Inside class definition
* Outside class definition
* NOTE: the methods inside the class are by default as inline so they are efficient
*/

#include <iostream>
#include <ostream>

class calculatorDemo { // class
    public: // access specifier
        int operandA;
        int operandB;
        int addTwoNumbers(int *a, int *b) { // Method defined inside class
            return *a + *b;
        }
        int multiplyTwoNumbers(int *a, int *b); // Method/function declaration
};

// To define a function outside the class definition, you have to declare it inside 
// the class and then define it outside of the class. This is done by specifiying the 
// name of the class, followed the scope resolution :: operator, followed by the name of the function:
// Method/function definition outside the class
int calculatorDemo::multiplyTwoNumbers(int *a, int *b) {
    return *a * *b;
}

int main(void) {

    calculatorDemo addNumbers;
    addNumbers.operandA = 8;
    addNumbers.operandB = 8;
    std::cout << "Addition :: " << addNumbers.addTwoNumbers(&addNumbers.operandA, &addNumbers.operandB) << std::endl;
    calculatorDemo multiplyNumbers;
    multiplyNumbers.operandA = 8;
    multiplyNumbers.operandB = 8;
    std::cout << "Multiplication :: " << addNumbers.multiplyTwoNumbers(&multiplyNumbers.operandA, &multiplyNumbers.operandB) << std::endl;
    return 0;
}
