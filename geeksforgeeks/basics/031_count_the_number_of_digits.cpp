#include <string>
using namespace std;
int countDigits(int n) {
    // code here
    string str = to_string(n);
    return str.length();
}
