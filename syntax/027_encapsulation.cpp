/* Encapsulation
   =============
 * The meaning of Encapsulation, is to make sure that "sensitive" data is hidden from users. 
 * To achieve this, you must declare class variables/attributes as private (cannot be accessed from outside the class). 
 * If you want others to read or modify the value of a private member, you can provide public get and set methods.
 */

#include <ostream>
#include <string>
#include <iostream>

class sqlite3Database {
    private:
        std::string schema;
        std::string module;
        std::string key;
    public:
        // the methods below act as a encapsulator to the private members
        // set the values
        void sqlite3Set(std::string s, std::string m, std::string k) {
            schema = s;
            module = m;
            key = k;
        }
        // get the values
        void sqlite3Get() {
            std::cout << "{" << schema << "," << module << "," << key << "};" << std::endl;
        }
};

int main(void) {
    sqlite3Database instanceOne;
    sqlite3Database instanceTwo;
    instanceOne.sqlite3Get(); // will be empty
    instanceOne.sqlite3Set("Earth", "Continets", "Country");
    instanceOne.sqlite3Get();
    instanceTwo.sqlite3Get(); // will be empty as it's different instance
    return 0;
    // output
/*  {, , };
    {Earth, Continets, Country};
    {, , }; */
}
