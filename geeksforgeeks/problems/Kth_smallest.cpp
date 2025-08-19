// User function template for C++
#include <vector>
using namespace std;
class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        for(int i = 0; i < arr.size(); i++) {
            bool isSwap = false;
            for(int j = 1; j < arr.size(); j++) {
                if(arr[j - 1] > arr[j]) {
                    int temp = arr[j - 1];
                    arr[j - 1] = arr[j];
                    arr[j] = temp;
                    isSwap = true;
                }
            }
            if(!isSwap)
                break;
        }
        // return the kth
        return arr[k - 1];
    }
};
