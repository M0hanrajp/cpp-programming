// Arrays are used to store multiple values in a single variable, instead of declaring separate variables for each value.
/* syntax :
    data_Type variable_name[size] = {element 1, element 2 ...;
* You access an array element by referring to the index number inside square brackets [].
* Array indexes start with 0: [0] is the first element. [1] is the second element, etc.
* Change the element value by assinging a new value based on index of the element.
*/

#include <iostream>
#include <ostream>
#include <string>

int main(void) {
    int _arr[4] = {1, 2, 3, 4};
    std::string _str[4] = {"Something", "in", "the", "way"};

    // Accessing elements through for loop
    for (int i = 0; i < 4; i++) {
        std::cout << "Element " << i << " = " << "int_arr " << _arr[i] << " string_arr " << _str[i] << std::endl;
    }
    
    std::cout << "\nUsing For-each loop\n";
    // Using the foreach loop & printing out address
    for(int x : _arr) {
        int i = 0;
        std::cout << "Element " << i << " = " << x << " address: " << &_arr[i]  << std::endl;
        i++;
    }
    for(std::string x : _str) {
        int i = 0;
        std::cout << "Element " << i << " = " << x << " address: " << &_arr[i]  << std::endl;
        i++;
    }

    // calculating array size
    std::cout << "Access elements using sizeof operator :: ";
    for (unsigned long i = 0; i < sizeof(_arr)/sizeof(*_arr); i++) {
        std::cout << _arr[i] << " ";
    }
    std::cout << '\n';
    return 0;
}

/* Error without specifying the type size 
string cars[];  // Array size is not specified
cars[0] = "Volvo";
cars[1] = "BMW";
cars[2] = "Ford";
cars[3] = "Mazda";
cars[4] = "Tesla";

// error: array size missing in 'cars' 

Arrays - Fixed Size Example
// An array with 3 elements
string cars[3] = {"Volvo", "BMW", "Ford"};
// Trying to add another element (a fourth element) to the cars array will result in an error
cars[3] = "Tesla";

Vectors - Dynamic Size Example
The size of a vector is dynamic, meaning it can grow and shrink as needed.
Vectors are found in the <vector> library, and they come with many useful functions to add, remove and modify elements:
// A vector with 3 elements
vector<string> cars = {"Volvo", "BMW", "Ford"};
// Adding another element to the vector
cars.push_back("Tesla");

string letters[2][4] = {
  { "A", "B", "C", "D" },
  { "E", "F", "G", "H" }
};

string letters[2][2][2] = {
  {
    { "A", "B" },
    { "C", "D" }
  },
  {
    { "E", "F" },
    { "G", "H" }
  }
};

string letters[2][4] = {
  { "A", "B", "C", "D" },
  { "E", "F", "G", "H" }
};

cout << letters[0][2];  // Outputs "C"

string letters[2][4] = {
  { "A", "B", "C", "D" },
  { "E", "F", "G", "H" }
};

for (int i = 0; i < 2; i++) {
  for (int j = 0; j < 4; j++) {
    cout << letters[i][j] << "\n";
  }
}


*/
