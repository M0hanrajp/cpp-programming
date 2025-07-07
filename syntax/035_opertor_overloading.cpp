/* Operator overloading is a compile-time polymorphism.
 * https://en.cppreference.com/w/cpp/language/operators.html
 * https://stackoverflow.com/questions/4421706/what-are-the-basic-rules-and-idioms-for-operator-overloading
 *
 * If we specify a user defined class, and want to add class objects using arithmetic operators we cannot do it,
 * why ? arithmetic operators only work over built in data types not user defined.
 *
 * In order to do that we have something called as operator overloading, which allow us to define 
 * a member function that helps in adding two class objects.
 */
#include <iostream>
using namespace std;

class CoordinatePoints {
    public:
        int pointX;
        int pointY;

        CoordinatePoints(int px = 0, int py = 0) {
            pointX = px;
            pointY = py;
        }

        // operator overloading
        // Since we cannot add two CoordinatePoints type data directly we are telling the compiler
        // that + below if used between two CoordinatePoints type then refer to the below member function.

        // addition
        CoordinatePoints operator+(CoordinatePoints &obj) {
            CoordinatePoints res;
            res.pointX = pointX + obj.pointX;
            /* how to read this equation, c(x) = a(x) + b(x)
             * where a(x) is the left hand, which is implicit CoordinatePoints * so (CoordinatePoints->pointX = a(x))
             * where b(x) is the right hand, which is reference of CoordinatePoints obj, CoordinatePoints->obj = b(x))
             */
            res.pointY = pointY + obj.pointY;
            return res;
        }

        // subtraction
        CoordinatePoints operator-(CoordinatePoints &obj) {
            CoordinatePoints res;
            res.pointX = pointX - obj.pointX; // a.pointX + b.pointY
            res.pointY = pointY - obj.pointY; // a.pointY + b.pointY
            return res;
        }

        void print() {
            cout << "X = " << pointX << " Y = " << pointY << endl;
        }
};

int main(void) {

    // declare two points on the plane
    CoordinatePoints a(2, 7);
    CoordinatePoints b(3, 4);
    CoordinatePoints c = a + b;
    c.print();
    CoordinatePoints d = a - b;
    d.print();

    /* How does this work ?
     * When constructor is called in main, they store the two parts of a point in pointX and pointY for a(2, 7) & b(3, 4)
     * CoordinatePoints operator+(CoordinatePoints &obj)
     * what does this mean ?
     * The left‐hand operand is the object on which you call it (the implicit *CoordinatePoints).
     *      inside the code when pointX + obj.pointX is written,
     *      it means, obj->pointX (where is obj is a (CoordinatePoints *) passed from main by a & b
     * The right‐hand operand is passed in as obj by reference.
     * It returns a brand‐new CoordinatePoints by value.
     */

    return 0;
}

/* Operator overloading
 * At least one operand must be user‑defined for overloads to be considered.
 * The compiler does the exact same overload resolution machinery it uses for functions.
 * If no viable overload is found, it falls back on built‑in behavior (if both operands are built‑in) or issues an error.
 * Ambiguities (multiple equally good matches) and invalid conversions 
 * (no way to convert your operands to any overload’s parameters) are compile‑time errors.
 * That’s how the compiler “knows” to invoke your overloaded operators instead of the default ones.

 a + b;
 - The compiler first lexes + as the binary‑plus token and recognizes you’re writing a built‑in operator expression.
 - It looks at the types of a and b, If both are built‑in arithmetic types (e.g. int, double), it binds to the built‑in addition.
 - If at least one is a user‑defined type (class, struct, or enum‑class), it considers overloaded operator+ candidates.

 When it looks for the definition(of the overload operator),
 * if, Member functions: if a’s type has a member, T T::operator+(U) const; that’s a candidate (read as a.operator+(b)).
 * if Non‑member functions: it also looks for free functions in the enclosing namespace(s), including via 
 * Argument‑Dependent Lookup (Koenig lookup), of the form: T operator+(T, U); or U operator+(U, T);
* 
* Now the compiler has a set of viable candidates: some built‑ins, some member, some non‑member.
* It ranks them by how well their parameter types match the actual operand types (exact match beats conversion, 
* conversion beats user‑defined conversion, etc.).
* If a single candidate is “best,” that’s chosen.
* If there’s a tie (two equally good overloads), you get an ambiguity error.


+  -  *  /  %      // arithmetic
+= -= *= /= %=    // compound assignment
++ --             // increment/decrement
== != < > <= >=   // comparisons
&& || !           // logical (note: &&, || must be non‑member)
[] () ->          // subscription, function‑call, pointer‑member
<< >>             // bit‑shift (and stream I/O when made friends)
new delete        // allocation/deallocation
,                 // comma
^ | & ~           // bitwise
+=, |=, ^=, &=    // bitwise compound assignment

|               Operator               | Reason                                                  |
| :----------------------------------: | :------------------------------------------------------ |
|                  `.`                 | Direct member access is hard‑wired                      |
|                 `.*`                 | Pointer‑to‑member access is built‑in                    |
|                 `::`                 | Scope resolution is purely compile‑time                 |
|                 `?:`                 | The ternary conditional is not an overloadable function |
|               `sizeof`               | Yields compile‑time constant                            |
|               `typeid`               | RTTI support via built‑in keyword                       |
|               `alignof`              | Reveals alignment of type at compile time               |
| cast operators (`static_cast`, etc.) | These are language constructs, not functions            |

*/
