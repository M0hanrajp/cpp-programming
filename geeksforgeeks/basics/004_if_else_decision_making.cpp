#include <string>
class Solution {
  public:
    std::string compareFive(int n) {
        // code here
        return n > 5 ? "Greater than 5" :
               n < 5 ? "Less than 5"    :
                       "Equal to 5";
    }
};
