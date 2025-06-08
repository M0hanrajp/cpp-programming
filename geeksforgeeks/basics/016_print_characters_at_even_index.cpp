#include <iostream>
#include <string>
using namespace std;
void utility(string s) {
    // length of string is given by s.length()
    // character at any index i is given by s[i]

    // Write your code here
    for(int i = 0; s[i] != '\0'; i++) {
        if(i % 2 == 0) {
            cout << s[i];
        }
    }
}
