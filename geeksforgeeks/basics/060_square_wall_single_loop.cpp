#include <iostream>
using namespace std;
void squareWall(int s) {
    // Write your code here
    for(int i = 0; i < s * s; i++) {
        cout << "* ";
        if((i + 1) % s == 0)
            cout << endl;
    }
}
