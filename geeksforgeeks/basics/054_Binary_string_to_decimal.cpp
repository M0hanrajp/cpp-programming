#include <cmath>
#include <string>
using namespace std;
class Solution {
  public:
    int binaryToDecimal(string &b) {
        // Code here.
        int n = 0;
        int p = b.length() - 1;
        for(int i = 0; b[i] != '\0'; i++) {
            if(b[i] == '1')
                n += pow(2, p);
            p--;
        }
        return n;
    }
};
