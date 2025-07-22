#include <iostream>
using namespace std;
class Solution {
  public:
    void printDivisors(int n) {
        // code here
        int i = 1;
        while(i <= n) {
            if(n % i == 0)
                cout << i << " ";
            i++;
        }
    }
};
