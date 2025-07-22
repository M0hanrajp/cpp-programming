// User function Template for C++
#include <iostream>
#include <cmath>
using namespace std;
void toBinary(int n) {
    // your code here
    char bin[64] = {0};
    int d = 0;
    int p = 0;
    int i = 0;
    while(d != n) {
        if((n & (1ul << p)) != 0) {
            d += pow(2, p);
            p++;
            bin[i++] = '1';
        } else {
            p++;
            bin[i++] = '0';
        }
    }
    cout << bin << endl;
}
