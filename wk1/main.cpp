// Marcus Pennington Coding 1 Spring 2026
// Variables and Logic

// Compile with the Developer Command Prompt
// 'cl /EHsc main.cpp' its what you type to compile
// 'main' or 'main.exe' to run the program.

#include <iostream>
#include <string>
using namespace std;


int main() {

    cout << "lets learn about variables and logic!\n";

    // declaring and defining variables
    int playerAge = -1;
    string playerName = "Darth Vader";
    float happinessPercent = 0.61f;
    bool keepPlaying = true;

    bool debug = false;

    

    // If statemenets
    // If the test is true run this code.
    if (playerAge == -1) {
        cout << "How old are you?\n";
        cin >> playerAge;

        if (playerAge <= 12) {
            cout << "This game is 13+ only\n";

            // Quit the game early
            return 0;
        } else if (playerAge == 2147483647) {
            cout << "Sorry immortal person, this program caps off at the age 2147483647\n";
        } else if (playerAge >= 150) {
            cout << "Are you immortal?\n";
        } else {
            cout << "Okay, " << playerAge << " is old enough to play.\n";
        }
    } // end of if(playerAge)

    if (playerName == "Darth Vader") {
        cout << "Is your name " << playerName << "?\n";
        std::string input = "";
        input = input;
        cin >> input;
        if (input == "yes" || input == "Yes" || input == "YES") {
            cout << "Well, that's convenient.\n";
        } else {
            cout << "What is your name?\n";
            cin >> playerName;
        }
    } // end of if(playerName)

    cout << "Hello " << playerName << ".\n";

    if (playerAge == 28 && playerName == "Marcus") {
        debug = true;
        cout << "Hello Creator. Debug mode is ON.\n";
    }

    if (debug) {
        cout << "playerAge = " << playerAge << ".\n";
        cout << "playerName = " << playerName << ".\n";
        cout << "happinessPercent = " << happinessPercent << ".\n";
        cout << "keepPlaying = " << keepPlaying << ".\n";
    }

    return 0;
}