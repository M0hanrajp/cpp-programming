#include <iostream>
using namespace std;

template<class subElements>
/* template, allows generic function parameters
 * no need to duplicate code,
 * https://en.cppreference.com/w/cpp/language/templates.html
 * https://www.geeksforgeeks.org/cpp/templates-cpp/
 */
inline subElements subtract(const subElements data[], subElements size, subElements result = 0) {
    /* This function uses a default parameters initialized to 0
     * Allows a function to be called without providing one or more trailing arguments.
     * https://en.cppreference.com/w/cpp/language/default_arguments.html
     */
    for(int i = 0; i < size; i++)
        result -= data[i];
    return result;
}

template<class sourceType, class destinationType>
inline void copyElements(const sourceType data[], destinationType copy) {
    // copyElements<float, double*> (data=0x7fffffffdee0, copy=0x7fffffffdf00) at 034_functions_and_generics.cpp:22
    // double copy is a double * type, even though copy is a destinationType copy in the function argument
    for(int i = 0; i < 5; i++) {
        copy[i] = static_cast<sourceType>(data[i]);
        cout << copy[i] << " ";
    }
    cout << endl;
}

int main(void) {
    float data[] = {1, 2, 3, 4, 5};
    cout << "The subtraction of all array elements: " << subtract(data, 5.0f) << endl;
    double copy[5] = {};
    copyElements(data, copy);
    cout << "The subtraction of all array elements: " << subtract(copy, 5.0) << endl;
    return 0;
}
