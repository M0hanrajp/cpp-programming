// User function Template for C++

// function should find if the string p is
// in the string s. Return the starting index
// of the string p in s. Return -1 if the
// string doesnot exists in s.
#include <string>
using namespace std;
int findPattern(string &s, string &p) {
    // code here
    return s.find(p, 0);
}
