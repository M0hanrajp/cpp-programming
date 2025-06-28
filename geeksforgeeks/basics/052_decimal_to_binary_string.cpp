// User function Template for C++

#include <cmath>
#include <string>
#include <bits/stdc++.h>
using namespace std;
string toBinary(int n) {
    // Your code here
    int res = 0;
    // declare a string with all values initialized to null
    string s(64, 0); int index = 0;
    while(res != n) {
    /* build the string unitl res is equal to input
     * this way we print characters required only
     * to build the string per output
     * exmaple ip 7, op 111. so bits should be till
     * it represents the number not 8bit or 32 bit representation.
    */
        if((n & (1u << index)) != 0) {
            res += pow(2, index);
            s[index++] = '1';
        } else {
            s[index++] = '0';
        }
    }
    reverse(s.begin(), s.end());
    // once you copy the characters they will be in reverse
    // hence use reverse to align the bit's in their proper
    // place
    return s;
}
