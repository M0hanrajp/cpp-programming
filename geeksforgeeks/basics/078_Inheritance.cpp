#include <iostream>
using namespace std;
class Cuboid {
    public:
        int length;
        int width;
        int height;
    // Add your code here.
        void display() {
            cout << length << " " << width << " " << height << endl;
        }
};

class CuboidVol : public Cuboid {
    // Add your code here.
    public:
    void read_input(int l, int w, int h) {
        length = l;
        width  = w;
        height = h;
    }
    void display() {
        cout << length * width * height << endl;
    }
};
