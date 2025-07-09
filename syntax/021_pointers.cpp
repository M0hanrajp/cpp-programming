#include <iostream>
#include <memory>
#include <string>

int main(void) {
    // Referencing a variable
    
    std::string foodType = "Pizza";
    // this is how references can be created
    // https://stackoverflow.com/questions/6877052/use-of-the-operator-in-c-function-signatures
    /* References are syntactic sugar for hidden pointers, with stricter rules (no reseating, no null).
     * Lifetime rules differ for lvalue vs. rvalue binding (watch out for dangling).
     * The address‑of operator & itself can be overloaded; use std::addressof when you really mean “raw” address.
     * In templates, T&, T&&, and forwarding references lead to reference‑collapsing quirks.
     * You also have reference qualifiers on members, and pointer‑to‑member syntax that reuses &.
     */
    std::string &order = foodType;
    std::cout << "I will have my " << order << "\n";
    std::cout << "address order: " << std::addressof(order) << " & address foodType: " << std::addressof(foodType) << "\n";
    
    // A pointer however, is a variable that stores the memory address as its value.
    std::string* orderTwo = &foodType;
    // Dereference: Output the value of food with the pointer (Pizza)
    std::cout << "I too will have " << *orderTwo << ", & address: " << orderTwo << "\n";
    std::cout << "address orderTwo: " << std::addressof(orderTwo) << " & address foodType: " << std::addressof(foodType) << "\n";
    return 0;
}
