/* Syntax
type variableName = value; */

#include <iostream>

using namespace std;

int main(void) {
    int day = 0;
    double coverage = 20.25; // float also is valid
    char newLine = '\n';
    string programmingLanguage = "C++";
    bool value = 1;
    
    cout << "It's day " << day + value
         << " & I have covered " << coverage << "% of "
         << programmingLanguage << newLine;

    // declare multiple variables, assigning one value to multiple variables
    int x = 5, y = 6, z = 50;
    x = y = z = 50; // it's valid in C
    cout << x + y * z << newLine;
    float w = 5e5;
    double q = 5e10;
    cout << "Value of float : " << w << "\n"
         << "Value of double: " << q << "\n";

    return 0;
}
/* Data types 
int - stores integers (whole numbers), without decimals, such as 123 or -123
double - stores floating point numbers, with decimals, such as 19.99 or -19.99
char - stores single characters, such as 'a' or 'B'. Char values are surrounded by single quotes
string - stores text, such as "Hello World". String values are surrounded by double quotes
bool - stores values with two states: true or false */

/* Data types 
boolean	1 byte	Stores true or false values
char	1 byte	Stores a single character/letter/number, or ASCII values
int	2 or 4 bytes	Stores whole numbers, without decimals
float	4 bytes	Stores fractional numbers, containing one or more decimals. Sufficient for storing 6-7 decimal digits
double	8 bytes	Stores fractional numbers, containing one or more decimals. Sufficient for storing 15 decimal digits */

/* Notes
 * you can assign any variable that holds non zero value to bool excpet a string
 * The precision of float is only six or seven decimal digits, while double variables have a precision of about 15 digits. 
 * Therefore it is safer to use double for most calculations.
 */ 

/* bool isCodingFun = true;
bool isFishTasty = false;
cout << isCodingFun;  // Outputs 1 (true)
cout << isFishTasty;  // Outputs 0 (false) */

// output
/* It's day 1 & I have covered 20.25% of C++
2550
Value of float : 500000
Value of double: 5e+10 */
