// User function Template for C++
int fibonacci(int n) {
    int a = 1;
    int b = 1;
    int c = 1;
    // the fibonacci numbers were 1 based index
    n -= 2;
    while(n--) {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}
