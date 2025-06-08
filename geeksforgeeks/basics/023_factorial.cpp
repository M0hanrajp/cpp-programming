int nFactorial(int n) {
    int ans = 1;
    // Write your code here
    while(n) {
        ans *= n--;
    }
    return ans;
}
