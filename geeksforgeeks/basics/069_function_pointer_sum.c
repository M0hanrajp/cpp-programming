#include <stdio.h>
// User function Template for C
int sub(int a, int b) {
    return a - b;
    // code here
}

int add(int a, int b) {
    return a + b;
    // code here
}

void compute(int a, int b, int (*op)(int, int)) {
    // print result as per function pointer
    // code here
    printf("%d\n", op(a, b));
}
