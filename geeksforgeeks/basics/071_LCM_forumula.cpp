// User function Template for C++

int gcd(int a, int b) {
    while(a != b) {
        if(a > b) {
            a = a - b;
            continue;
        }
        if(b > a) {
            b = b - a;
            continue;
        }
    }
    return a;
}

int LCM(int a, int b) {
    return b * (a / gcd(a, b));
}
