#include <iostream>
#include <cmath>

int main(void) {

    std::cout << "Max   :: " << std::max(9, 8)   << std::endl;
    std::cout << "Min   :: " << std::min(9, 8)   << '\n';
    std::cout << "SQRT  :: " << std::sqrt(64)    << '\n';
    std::cout << "ROUND :: " << std::round(4.56) << '\n';
    std::cout << "Log   :: " << std::log(2)      << '\n';
    return 0;
}

// When you call log(2) in C++, you are asking for ln(2), the natural logarithm of 2.
// The natural logarithm uses the base e, where e is an irrational and transcendental number approximately equal to 2.71828.
