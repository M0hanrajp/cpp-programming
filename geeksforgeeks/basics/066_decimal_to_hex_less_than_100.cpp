#include <iostream>
using namespace std;

int main() {
    int a;
    cin >> a;
    // printing hexadecimal value of a.
    char hex[3] = {};
    int d = 1;
    int h = 16;
    int m = 1;
    if(a < 16) {
        switch(a) {
            case  1: cout << '1' << endl; break;
            case  2: cout << '2' << endl; break;
            case  3: cout << '3' << endl; break;
            case  4: cout << '4' << endl; break;
            case  5: cout << '5' << endl; break;
            case  6: cout << '6' << endl; break;
            case  7: cout << '7' << endl; break;
            case  8: cout << '8' << endl; break;
            case  9: cout << '9' << endl; break;
            case 10: cout << 'a' << endl; break;
            case 11: cout << 'b' << endl; break;
            case 12: cout << 'c' << endl; break;
            case 13: cout << 'd' << endl; break;
            case 14: cout << 'e' << endl; break;
            case 15: cout << 'f' << endl; break;
            default:                      break;
        }
    } else {
        while(a) {
            d = 16 * m;
            if(d > a)
                break;
            m++;
        }
        hex[0] = '0' + (m - 1);
        d = (a - (16 * (m - 1)));
        hex[1] = d > 9 ? 'a' + (d - 10) : '0' + d;
        hex[2] = '\0';
        cout << hex << endl;
    }
    return 0;
}
