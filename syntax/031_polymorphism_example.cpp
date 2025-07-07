/* NOTE: Virtual functions are a key part of polymorphism in C++. They let different objects respond differently 
 * to the same function call. A virtual function is a member function in the base class that can be overridden in derived classes.
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Abstract base class Device
class Device {
    public:
      /* virtual - Marks on() as a virtual function, so calls via a base‑class pointer/reference dispatch
         * to the most‑derived override at run time.
         * = 0 Turns it into a pure virtual function (sometimes called an “abstract” method).
         * You don’t provide any implementation in the base class.
         * As soon as you have one pure virtual function, the class itself becomes abstract, meaning:
         * You cannot instantiate it (Device d; is illegal).
         * You must subclass it and provide a concrete override of on() before you can create objects of that subclass.
         */
        virtual void on() = 0;
        virtual void off() = 0;
        virtual string status() const = 0;
        virtual ~Device() = default;
        /* Gives you a concrete (non‑abstract) destructor implementation, equivalent to writing an empty {} body.
         * virtual ~Device() = 0;
         * Makes the destructor itself one of the pure‑virtual members, ensuring the class is abstract even if 
         * you removed all other = 0 functions. Still requires you to provide a definition out‑of‑line, e.g. Device::~Device() {}.
         */
};

/* Polymorphism: Polymorphism, in general, refers to the ability of something to
 * take on multiple forms or appearances
 *
 * That separation—one interface, many implementations—is polymorphism in action.
 * The controller doesn’t need to know what kind of device it’s talking to; it
 * just calls on(), off(), or status(), and each device behaves appropriately.
 */

// derived class Light
class Light : public Device {
    public:
        void on() override {
            cout << "Light turned on" << endl;
        }
        void off() override {
            cout << "Light turned off" << endl;
        }
        string status() const override {
            return "active";
        }
};

// derived class Thermostat
class Thermostat : public Device {
    public:
        void on() override {
            cout << "Thermostat turned on" << endl;
        }
        void off() override {
            cout << "Thermostat turned off" << endl;
        }
        string status() const override {
            return "disabled";
        }
};

int main(void) {
    Light deviceBulb;
    Thermostat deviceThermostat;
    vector<Device *> homeIoT = {&deviceBulb, &deviceThermostat};
    /* This is an example of "Runtime polymorphism"
     * What: Runtime polymorphism lets you call derived‑class methods through a
     * base‑class pointer or reference, with the actual override chosen at run time.
     *
     * Why: To write code against a single interface (Device*) while supporting many
     * behaviors (Light::on(), Thermostat::on(), etc.), making your system extensible
     * and decoupled.
     *
     * When Whenever you have a family of related classes sharing an interface and you
     * need to operate on them uniformly (e.g. a container of Device*).
     *
     * Where (in code) In the base class: declare methods virtual (or pure virtual).
     * In derived classes: override those methods.
     * In client code: store or pass around pointers/references to the base, then call
     * the methods.
     *
     * How: At compile time the compiler emits a v‑table for each class. When you do
     * d->on(), it looks up the correct function pointer in that table and invokes the
     * override matching the object’s real type.
     */
    for(Device *d : homeIoT) {
        d->on();
        d->off();
        cout << d->status() << endl;
    }
    return 0;
}

/* about the default operator:
 * https://www.geeksforgeeks.org/cpp/explicitly-defaulted-deleted-functions-c-11/#:~:text=What%20are%20the%20advantages%20of%20%27%3Ddefault%27%20when%20we%20could%20simply%20leave%20an%20empty%20body%20of%20the%20function%20using%20%27%7B%7D%27%3F%C2%A0
 * https://www.geeksforgeeks.org/cpp/explicitly-defaulted-deleted-functions-c-11/ (default and delete)

  Instead of mentioning an empty body like, virtual void foo(params) {}, we declare it as virtual void foo(params) = default;

    In C++ the = default; specifier can only be used on special member functions (and even then under certain conditions).

    Only special member functions can be explicitly defaulted. A “special member function” is one of these five:
    default constructor
    destructor
    copy constructor
    move constructor
    copy‑ or move‑assignment operator
*/
