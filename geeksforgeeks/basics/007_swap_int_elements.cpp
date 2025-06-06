// User function Template for C++

/* &a and &b act as a reference to the variable
 * they are not the same as pointers, just an alias
 * they are also indicating that function arguments
 * are pass by reference value
 * per https://stackoverflow.com/questions/6877052/use-of-the-operator-in-c-function-signatures
 * or https://isocpp.org/wiki/faq/references
 */
void swap(int &a, int &b) {
    // code here
    int temp = a;
    a = b;
    b = temp;
}
