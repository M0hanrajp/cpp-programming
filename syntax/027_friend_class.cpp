/* Friend class
 * ============
 * A friend function is not a member of the class, but it is allowed to access the class's private data:
 * https://en.cppreference.com/w/cpp/language/friend.html
 */

#include <iostream>
using namespace std;

class BoxPrinter;
class BoxModifier;

class Box {
    private:
        double width;
        double height;
        double depth;
    public:
        Box(double w, double h, double d) {
            width = w;
            height= h;
            depth = d;
        }
        /* const comes after the parameter list: it qualifies the method, not the return
         * type this member function promises not to modify any of the object’s members.
         * Only a const‑qualified member can be called on a const instance (e.g. inside
         * void foo(const Box& b), or if you have const Box b */
        double volume(void) const {
            return width * height * depth;
        }
    /* BoxPrinter has access to width, height, depth, Box() & volume() */
    friend BoxPrinter;
    /* Box will declare BoxModifier a friend, so only BoxModifier can poke
     * into Box’s internals and adjust them.
     * Box can’t reach into BoxModifier to read its own private toolName.
     *     In other words, Box does not know who modified the dimensions.
     * Holds true for both BoxPrinter and BoxModifier */
    friend BoxModifier;
};

class BoxPrinter {
    public:
        void printBoxDetails(const Box &b) {
            cout << "Width : " << b.width << " Height : " << b.height << " Depth : " << b.depth << endl;
            cout << "Volume of the box: " << b.volume() << endl;
        }
};

// NOTE: Friendship is not mutual
// each friendship you declare is one‑way only—nobody gets automatic reciprocal access unless you explicitly grant it.
class BoxModifier {
    private:
        // consider BoxModifier is aware of who did the modification
        // But Box has no special access to BoxModifier::toolName (or any other privates in BoxModifier).
        string toolName;
    public:
        // increase box dimensions by certain factor
        void scale(Box &b, double factor) {
            b.width *= factor;
            b.depth *= factor;
            b.height*= factor;
        }
        void enterToolName(string tn) {
            toolName = tn;
        }
    friend void whoChangedTheDimensions(BoxModifier &bm);
};

// How to give function access to private members of a class
void whoChangedTheDimensions(BoxModifier &bm) {
    cout << bm.toolName << endl;
}

int main(void) {
    Box meow(10, 10, 10);
    BoxPrinter display;
    // since display has access to all members, constructors & functions
    display.printBoxDetails(meow);
    // Friend class is mutual in the declared base class
    BoxModifier modify;
    modify.scale(meow, 1.56);
    modify.enterToolName("Owner");
    display.printBoxDetails(meow);
    whoChangedTheDimensions(modify);
    return 0;
}
