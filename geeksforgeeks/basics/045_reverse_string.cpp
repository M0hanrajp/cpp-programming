// User function Template for C++

// complete the function
// the function should return the reversed string
#include <string>
using namespace std;
string reverseString(string &s) {
    // code here
    char temp[s.size()] = {0};
    int idx = 0;
    // copy the string
    for(int i = 0; s[i] != '\0'; i++) {
        temp[idx++] = s[i];
    }
    idx -= 1;
    // reverse the string
    for(int i = 0; temp[i] != '\0'; i++) {
        s[i] = temp[idx--];
    }
    return s;
}
