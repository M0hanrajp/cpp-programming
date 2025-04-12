// The third specifier, protected, is similar to private, but it can also be accessed in the inherited class:

#include <iostream>
#include <ostream>

class fOneRace {
    protected:
        bool boxbox = false;
};

class operatorBono: public fOneRace {
    public:
        bool p2InRace(bool driverAnswer) {
            return boxbox = driverAnswer ? false : true;
        }
        bool rainExpect(bool driverAnswer) {
            return boxbox = driverAnswer ? true : false;
        }
};

int main(void) {
    operatorBono decisionMaking;
    std::cout << "Bono: box box!\n" << "Hamliton at P2:" << (!(decisionMaking.p2InRace(false)) ? 
                                       " No bono no\n" : 
                                       " this is getting manipulating\n") << std::endl;

    std::cout << "Hamilton: It's raining guys!\n" << "Bono:" << (decisionMaking.rainExpect(true) ? 
                                       " Negative!, stay on race!\n" : 
                                       " box, box\n") << std::endl; 

    return 0;
}
