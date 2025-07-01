// User function Template for C++
#include <string>
using namespace std;
class Solution {
  public:
    string substring(string &s, int L, int R) {
        // code here
        string res(L + R + 1, 0);
        int idx = 0;
        for(int i = L; i <= R; i++) {
            res[idx++] = s[i];
        }
        return res;
    }
};
