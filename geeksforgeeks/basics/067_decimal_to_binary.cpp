#include <iostream>
#include <cmath>
using namespace std;

int main() {
    // code here
    int n = 0;
    cin >> n;
    int d = 0;
    int p = 0;
    int arr[64] = {0};
    int idx = 0;
    while(d != n) {
        if((n & (1u << p)) != 0) {
            d += pow(2, p);
            arr[idx++] = 1;
            p++;
        } else {
            arr[idx++] = 0;
            p++;
        }
    }
    
    for(int i = idx - 1; i > -1; i--) {
        cout << arr[i];
    }
    return 0;
}
