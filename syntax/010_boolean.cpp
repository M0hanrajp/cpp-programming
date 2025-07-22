// A program to check if you are old enough to vote
#include <iostream>

int main(void) {
    int requiredAge = 18;
    int userAge = 0;

    std::cout << "Please enter your age: "; std::cin >> userAge;
    std::cout << "Result :: " << (userAge >= requiredAge) << std::endl;
    std::cout << "If Result is 1 you are eligible to vote else you are not eligible\n";
    return 0;
}
