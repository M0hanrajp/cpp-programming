#include <iostream>
#include <iomanip>
// https://stackoverflow.com/questions/22515592/how-to-use-setprecision-in-c
using namespace std;
void precise(float a, float b) {
    // perform a/b
    float ans = a / b;
    cout << ans << " ";
    cout << fixed << showpoint;
    cout << setprecision(3);
    cout << ans << endl;
}
