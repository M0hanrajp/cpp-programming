// User function Template for C++

// function should print the alphabets
// from c1 to c2 (space separated)
// No need to print the new line
// The new line will be printed by the
// driver's code.

#include <iostream>
using namespace std;
void alphabets(char c1, char c2) {
    // code here
    for(char alpha = c1; alpha <= c2; alpha++) {
        cout << alpha << " ";
    }
}
