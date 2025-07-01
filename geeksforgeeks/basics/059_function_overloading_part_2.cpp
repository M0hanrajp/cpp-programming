#include <iostream>
using namespace std;
#define PI 3.14159

void volume(int s) {
    // Add your code here.
    cout << s * s * s << "\n";
}

void volume(int r, int h) {
    // Add your code here.
    cout << PI * (r * r) * h << "\n";
}

void volume(int l, int b, int h) {
    // Add your code here.
    cout << l * b * h << "\n";
}
