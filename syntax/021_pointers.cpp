#include <iostream>
#include <string>

int main(void) {
    // Referencing a variable
    
    std::string foodType = "Pizza";
    // this is how references can be created
    std::string &order = foodType;
    std::cout << "I will have my " << order << "\n";
    std::cout << "address order: " << &order << " & address foodType: " << &foodType << "\n";
    
    // A pointer however, is a variable that stores the memory address as its value.
    std::string* orderTwo = &foodType;
    // Dereference: Output the value of food with the pointer (Pizza)
    std::cout << "I too will have " << *orderTwo << ", & address: " << orderTwo << "\n";
    std::cout << "address orderTwo: " << &orderTwo << " & address foodType: " << &foodType << "\n";
    return 0;
}
