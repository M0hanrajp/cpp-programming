#include <iostream>
using namespace std;

int main() {
    int x = 2;
    double y = 3.5;
    char z = 'g';

    // store the size of the variables into a, b, c variables;
    auto a = sizeof(x);
    auto b = sizeof(y);
    auto c = sizeof(z);
    // printing the size of the variable x.
    cout << a << " " << b << " " << c << endl;
    return 0;
}
