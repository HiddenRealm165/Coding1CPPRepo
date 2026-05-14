// Marcus Pennington Coding 1 Week 5
// Classes Today

// To Compile: 'cl /EHsc main.cpp'
// To Compile then Execute: 'cl /EHsc main.cpp && main'

#include <iostream>
#include <string>
using namespace std;

// Classes are custom variable types
// variables
// functions

// constructors
// getters and setters (privacy)

class robot {
private:
    string name;
    int charge;
    int boredom;

public:
    // constructor, sets up class with input variables
    // does not have a return type.
    // name must match class name.
    /* Robot
    Params: Name, Charge, Boredom
    */
    robot (string sName, int nCharge, int nBoredom) {
        name = sName;
        charge = nCharge;
        boredom = nBoredom;
        status();
    }
    /* Robot
    No Params
    Default Values
    */
    robot() {
        name = "Rob";
        charge = 10;
        boredom = 10;
        status();
    }

    void status() {
        cout << "Hello World!\nMy name is " << name << ",";
        cout << " and my charge is " << charge << ".\n";

        cout << "I am ";
        if (boredom < 5) cout << "happy";
        else if (boredom < 10) {
            cout << "bored";
        } else if (boredom < 15) {
            cout << "agitated";
        } else if (boredom < 20) {
            cout << "frustraited";
        } else {
            cout << "angry";
        }
        cout << ".\n";
    }

    /* Get/Set Name
    Type string
    */
    string getName() {
        return name;
    }
    void setName(string sName) {
        if (sName.size() <= 5) {
            name = sName;
        } else {
            cout << "Error: " << sName << " is too long.\n";
            cout << "Name should be 5 or less characters.\n";
        }
    }

    /* Get/Set charge
    Type int
    Min: 0, Max: 100
    */
    int getCharge() {
        return charge;
    }
    void setCharge(int nCharge) {
        // clamp charge to between 0 & 100.
        if (nCharge < 0) {
            charge = 0;
        } else if (nCharge > 100) {
            charge = 100;
        } else {
            charge = nCharge;
        }
    }
    /* Add Charge
    Modify Charge by adding Param
    Type int
    Min charge: 0, Max charge: 100
    */
    void addCharge(int nValue) {
        charge += nValue;
        if (charge < 0) {
            charge = 0;
        } else if (charge > 100) {
            charge = 100;
        }
    }

    /* Get/Set boredom
    Type int
    Min: 0, Max: N/A
    */
    int getBoredom() {
        return boredom;
    }
    void setBoredom(int nBoredom) {
        // clamp minimum to 0
        if (nBoredom < 0) {
            boredom = 0;
        } else {
            boredom = nBoredom;
        }
    }
    /* Add Boredom
    Modify boredom by adding param
    Type int
    Min boredom: 0, Max boredom: N/A
    */
    void addBoredom(int nValue) {
        boredom += nValue;
        if (boredom < 0) {
            boredom = 0;
        }
    }

    /* Take Charge
    Params: robot nRobot, int nTargetCharge default 100
    Depleats charge from given robot
    Min nTargetCharge: 0, Max nTargetCharge: 100
    Min charge: 0, Max charge: 100
    Will abort if nRobot charge reaches 1
    */
    void takeCharge(robot nRobot, int nTargetCharge = 100) {
        // Clamp nTargetCharge to 0-100
        if (nTargetCharge < 0) {
            nTargetCharge = 0;
        } else if (nTargetCharge > 100) {
            nTargetCharge = 100;
        }
        cout << "Beginning Charge Protocol\n";
        cout << name << " is attempting to receive charge from " << nRobot.getName() << ".\n";
        while (charge < nTargetCharge && nRobot.getCharge() > 1) {
            nRobot.addCharge(-1);
            charge++;

            if (nRobot.getCharge() <= 1) {
                cout << nRobot.getName() << " has fallen below safe charge levels, aborting charge operation.\n";
                break;
            }
            cout << "Charging Status:\n";
            cout << name << ": " << charge << "\n";
            cout << nRobot.getName() << ": " << nRobot.getCharge() << "\n";
        }
    }

};

int main() {
    cout << "Classes!\n";

    // create our first instance of a robot.
    robot arToo("R2-D2", 3, 4);
    // arToo.name = "R2-D2";
    // arToo.charge = 45;
    // arToo.boredom = 2;

    cout << "ArToo has " << arToo.getName().size() << " characters in their name.\n";

    robot threepio;
    threepio.setName("C-3PO");
    threepio.setCharge(100);
    threepio.setBoredom(16);

    arToo.status();
    threepio.status();

    // Scenario
    // cout << threepio.getName() << " is low on charge.\n";
    // cout << "We should have " << arToo.getName() << " give some of their charge.\n";

    // while (arToo.getCharge() > 0 && threepio.getCharge() < 15) {
    //     arToo.addCharge(-1);
    //     threepio.addCharge(1);
    //     cout << "Charge Status: \n";
    //     cout << arToo.getName() << ": " << arToo.getCharge() << "\n";
    //     cout << threepio.getName() << ": " << threepio.getCharge() << "\n";

    //     if (arToo.getCharge() <= 1) {
    //         cout << arToo.getName() << " is almost out of charge!\n";
    //         cout << "Aborting Charge Transfer.\n";
    //         break;
    //     }
    // }

    arToo.takeCharge(threepio, 25);

    return 0;
}