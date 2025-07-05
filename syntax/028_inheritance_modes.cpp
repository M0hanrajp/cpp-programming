/* 
 * Public Inheritance Mode: Public member of the base class will become public in the derived class and 
 *                          protected members of the base class will become protected in the derived class.
 *
 * Protected Inheritance Mode: Both public and protected members of the base class will become protected in 
 *                             the derived class.
 * 
 * Private Inheritance Mode: Both public members and protected members of the base class will become private 
 *                           in the derived class. Private mode is the default mode that is applied when we 
 *                           don't specify any mode.
 */
#include <iostream>
#include <string>
using namespace std;

// Base class
class MI6 {
    private:
        string mission = "Classified";
    protected:
        string agent   = "Classified";
    public:
        void setMission(string newMission) {
            mission = newMission;
        }
        void getMission(void) {
            cout << mission << endl;
        }
        void setAgent(string newAgent) {
            agent = newAgent;
        }
        void getAgent(void) {
            cout << agent << endl;
        }
};

// inhertiance mode is protected hence public and protected members of base will become protected
// A “protected” HQ that can assign missions but hides them from external users.
class MainHeadquarters : protected MI6 {
    public:
        MainHeadquarters(string assignAgent, string assignMission) {
            /* Agent is a protected member, can be used in derived class
             * setMission is public member, for Headquarters class it's protected, can be used in derived class
             * but public methods setMission, getMission, getAgent cannot be accessed through Headquarter's object
             */
            setAgent(assignAgent);
            setMission(assignMission);
        }
        void missionStatistics(void) {
            getMission();
            getAgent();
        }
};

class HackHeadquarters : public MI6 {
    public:
        HackHeadquarters(string otherAgent, string otherMission) {
            setMission(otherMission);
            setAgent(otherAgent);
        }
};

/* The private members in the base class cannot be directly accessed in the derived class, 
 * while protected and public members can be directly accessed. 
 * To access or update the private members of the base class in derived class, use get-set of the base class 
 * or declare the derived class as friend class. 027.cpp
 */

int main(void) {
    MainHeadquarters missionImpossible("Ethan", "Bunker destruction");
    //missionImpossible.getMission(); error since getMission becomes protected due to protected inheritance mode
    missionImpossible.missionStatistics();

    HackHeadquarters missionPossible("Bond", "Sky-Fall");
    // since MI6 was declared public in HackHeadquarters we can use all it's public methods
    missionPossible.getMission();
    missionPossible.getAgent();
    // missionPossible can change mission and agents
    return 0;
}
