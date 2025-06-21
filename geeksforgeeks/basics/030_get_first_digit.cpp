// Complete the function
int firstDigit(int n) {
    // code here
    int d = 1;
    while (n / d > 9) {
        d *= 10;
    }
    return n / d;
}
