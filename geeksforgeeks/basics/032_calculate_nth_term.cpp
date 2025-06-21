/* Where a is the first term, d is the common difference of an A.P.  
 * Calculate the nth term of A.P. The nth term is given by an = a + (n-1)d
 */
int apTerm(int a, int d, int n) {
    // code here

    int ans = a + (n - 1) * d;
    return ans;
}
