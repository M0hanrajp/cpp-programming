/* A virtual function is a member function in the base class that can be overridden in derived
 * classes Virtual functions are a key part of polymorphism in C++. They let different objects
 * respond differently to the same function call.
 *
 * Without virtual, C++ decides which function to call based on the pointer type, not the actual
 * object type. With virtual, it checks the actual object the pointer is pointing to.
 *
 * Static type: the type known at compile time — what the compiler sees in your code.
 * Dynamic type: the type of the actual object in memory at runtime.
 * d->on();  // looks like Device::on()
 * But since on() is declared virtual, the compiler doesn’t hard-code a call to Device::on(). 
 * Instead, it tells the CPU:
 * "Look at the object’s v‑table — the dynamic type — and use that to find the actual method."
 * This lets d->on() invoke Light::on() or Thermostat::on() depending on what the object really 
 * is at runtime.
 * That’s the power of runtime polymorphism: the decision is deferred from compile time to run time 
 * based on the dynamic type of the object.
 */
#include <iostream>
using namespace std;

// Base class
class Device {
    // Normal function
    public:
        virtual void deviceStatus(void) {
            cout << "Offline" << endl;
        }
};

// Abstract class 
class DeviceIoT {
    // pure virtual class makes base class abstract,
    public:
        virtual void deviceStatus(void) = 0;
        virtual ~DeviceIoT() = default;
};

class Thermostat : public Device {
    public:
        void deviceStatus(void) override {
            cout << "Thermostat:: Offline" << endl;
        }
};

class ModbusTemperature: public DeviceIoT {
    public:
        void deviceStatus(void) override {
            cout << "ModbusTemperature:: Online" << endl;
        }
};

int main(void) {
    Device a;
    Thermostat t;
    a.deviceStatus(); // prints Device deviceStatus
    t.deviceStatus(); // prints Thermostat deviceStatus

    // DeviceIoT is abstract class hence in main(), we cannot do DeviceIoT obj, obj.member (it's wrong)
    DeviceIoT *d = new ModbusTemperature;
    /* is dynamic type, whcih points to ModbusTemperature,
     * (*d) yields the actual object (of static type DeviceIoT& but dynamic type ModbusTemperature).
     * uses vtable lookup to call the implementation
     */
    d->deviceStatus();
    delete d; // can only be done if the base class has virutal destructor
    return 0;
}

/* NOTE:
 * You cannot achieve runtime polymorphism in C++ with just free functions 
 * (i.e., non-member functions in a .cpp file), even if they’re marked virtual.
 */
