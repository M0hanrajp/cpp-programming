#include <iostream>
#include <typeinfo>
using namespace std;

int main() {
    int a = 3;
    float b = 5.57;

    // calculate typeid for variable a and b in variables id1 and id2.
    string t_id1 = typeid(a).name();
    string t_id2 = typeid(b).name();

    // printing the typeid's
    cout << t_id1 << " " << t_id2 << endl;
}
