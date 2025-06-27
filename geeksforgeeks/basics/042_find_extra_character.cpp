// User function Template for C++

#include <string>
using namespace std;
char extraChar(string &s1, string &s2) {
    // code here
    for(int i = 0; s2[i] != '\0'; i++) {
        bool found = false;
        for(int j = 0; s1[j] != '\0'; j++) {
            if(s2[i] == s1[j]) {
                found = true;
                break;
            }
        }
        if(!found) {
            return s2[i];
        }
    }
    return s2[s2.size() - 1];
}
