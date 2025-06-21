#include <cstdio>
#include <string>
using namespace std;
class Solution {
  public:
    string compareNum(int A, int B) {
        // code here
        char buff[25] = {};
        A > B ? sprintf(buff, "%d is greater than %d", A, B) :
        A < B ? sprintf(buff, "%d is less than %d", A, B) :
                sprintf(buff, "%d is equals to %d", A, B);
        return buff;
    }
};
