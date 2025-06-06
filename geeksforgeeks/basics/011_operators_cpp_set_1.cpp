#include <vector>
using namespace std;
class Solution {
  public:
    vector<int> cppOperators(int A, int B) {
        vector<int> v;
        // code here
        v.push_back(A + B);
        /* adds to 0th index the sum of a + b */
        v.push_back(A * B);
        if(A > B)  {
            v.push_back(A - B);
            v.push_back(A / B);
        } else {
            v.push_back(B - A);
            v.push_back(B / A);
        }
        return v;
    }
};
