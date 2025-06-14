// User function Template for C++
#include <iostream>
using namespace std;
void fizzBuzz(int number) {
    // Write your code here.
    (number % 3 == 0 && number % 5 == 0) ? cout << "FizzBuzz\n" :
           number % 3 == 0 ? cout << "Fizz\n" :
           number % 5 == 0 ? cout << "Buzz\n" :
           cout << number << endl;
}
