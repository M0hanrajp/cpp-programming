// User function Template for C++

// functions should slice the given string
// i.e. remove the first and the last character
// of the given string and return the sliced
// string
#include <string>
using namespace std;
string sliceString(string &s) {
    // code here
    string res(s.size() - 2, 0); 
    int idx = 0;
    for(int i = 1; i < s.size() - 1; i++)
        res[idx++] = s[i];
    return res;
}
