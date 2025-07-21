int gcd(int a, int b) {
    // code here to calculate and return gcd of a and b
    // euclid's algo.
    while(a != b) {
        if(a > b) {
            a = a - b;
            continue;
        }
        if(b > a) {
            b = b - a;
        }
    }
    return a;
}
