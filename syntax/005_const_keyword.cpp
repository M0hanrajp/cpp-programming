#include <iostream>

int main(void) {
    // When you do not want others (or yourself) to change existing variable values, 
    // use the const keyword (this will declare the variable as "constant", 
    // which means unchangeable and read-only):
    const int v = 2;
    bool value = 0;
    v = value;
    return 0;
}

/* 5_const_keyword.cpp: In function ‘int main()’:
5_const_keyword.cpp:6:7: error: assignment of read-only variable ‘v’
    6 |     v = value;
      |     ~~^~~~~~~ */

/* const int minutesPerHour;
minutesPerHour = 60; // error */
