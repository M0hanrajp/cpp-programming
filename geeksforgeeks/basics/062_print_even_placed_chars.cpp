#include <iostream>
using namespace std;
class Solution {
  public:
    void printEvenIndices(const string& s) {
        // code here
        for(int i = 0; s[i] != '\0'; i++) {
            if(i % 2 == 0) {
                cout << s[i];
            }
        }
    }
};
