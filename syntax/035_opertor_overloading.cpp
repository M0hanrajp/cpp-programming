/* Operator overloading is a compile-time polymorphism.
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
