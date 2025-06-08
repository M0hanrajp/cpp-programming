// User function Template for C++

/* &a and &b act as a reference to the variable 
 * they are not the same as pointers, just an alias
 * also any change made to the variables in in the called function are reflected in the calling function.
 * they indicate pass by reference value
 * per https://stackoverflow.com/questions/6877052/use-of-the-operator-in-c-function-signatures
 * or https://isocpp.org/wiki/faq/references
 */
void swap(int &a, int &b) {
    // code here
    int temp = a; // a is an int here
    a = b;
    b = temp;
}
