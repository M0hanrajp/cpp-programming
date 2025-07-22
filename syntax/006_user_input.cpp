#include <iostream>

int main(void) {
    float operandA = 0;
    float operandB = 0;
    std::cout << "Enter value of A: ";
    // cin is a predefined variable that reads data from the keyboard with the extraction operator (>>).
    // we don't use address of operator here
    std::cin >> operandA;
    std::cout << "Enter value of B: ";
    std::cin >> operandB;
    std::cout << "Sum of A + B = " << operandA + operandB << "\n";
    return 0;
}
