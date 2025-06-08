// User function Template for C++
#include <iostream>
using namespace std;
void divisor(int n) {
    // Write your code here
    for(int i = 1; i <= n; i++) {
        if(n % i == 0) {
            cout << i << " ";
        }
    }
}
