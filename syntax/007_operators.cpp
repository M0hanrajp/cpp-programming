#include <iostream>

using namespace std;

int main(void) {
    int a = 5;
    int b = 5;
    // arithmetic operators
    cout << a + b << "\n"
         << a * b << "\n"
         << a - b << "\n"
         << a / b << "\n"
         << a++   << "\n" // prints 5 to stdout, becomes 6 later
         << --b   << "\n" // 4
         << a % b << "\n";
    // assignment operators
    cout << (a += b) << "\n" // not using () will give an error // a = 10
         << (b *= a) << '\n'; // 4 * 10
    // comparison operators (<, >, etc..)

    return 0;
}

/* Operator	Name	Description	Example	
+	Addition	Adds together two values	x + y	
-	Subtraction	Subtracts one value from another	x - y	
*	Multiplication	Multiplies two values	x * y	
/	Division	Divides one value by another	x / y	
%	Modulus	Returns the division remainder	x % y	
++	Increment	Increases the value of a variable by 1	++x	
--	Decrement	Decreases the value of a variable by 1	--x	
 */

/* Operator	Example	
=	x = 5	x = 5	
+=	x += 3	x = x + 3	
-=	x -= 3	x = x - 3	
*=	x *= 3	x = x * 3	
/=	x /= 3	x = x / 3	
%=	x %= 3	x = x % 3	
&=	x &= 3	x = x & 3	
|=	x |= 3	x = x | 3	
^=	x ^= 3	x = x ^ 3	
>>=	x >>= 3	x = x >> 3	
<<=	x <<= 3	x = x << 3 */

/* Operator	Name	Example
==	Equal to	x == y	
!=	Not equal	x != y	
>	Greater than	x > y	
<	Less than	x < y	
>=	Greater than or equal to	x >= y	
<=	Less than or equal to	x <= y */

// logical operator
/* Operator	Name	Description	Example	Try it
&& 	Logical and	Returns true if both statements are true	x < 5 &&  x < 10	
|| 	Logical or	Returns true if one of the statements is true	x < 5 || x < 4	
!	Logical not	Reverse the result, returns false if the result is true	!(x < 5 && x < 10) */
