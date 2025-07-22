#include <iostream>
using namespace std;

int main() {
    // code here
    int n = 0;
    cin >>  n;
    int d = 0;
    while(n > 0) {
        n /= 10;
        d++;
    } 
    cout << d;
    return 0;
}
