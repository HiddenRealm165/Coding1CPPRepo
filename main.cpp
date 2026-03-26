// Marcus Pennington Coding 1 Spring 2026
// Testing code for Coding 1 class

// IN-OUT stream, for sending and recieving text from the console.
#include <iostream>
//for playerName;
#include <string>

// so we don't have to type "std::" all the time.
using namespace std;

// This is where we begin the program
int main() {

    //variables declared at the top is best practice.
    string playerName;

    cout << "What is your name, Player? ";

    // Assigns player's input as the playerName.
    cin >> playerName;

    // Greet the player by playerName
    cout << "Hello " << playerName << "." << endl;

    // user Control+Slash to comment out lines.
    //cout = console out, endl = end line
    // cout << "Hello World!" << endl;

    // end the program
    return 0;
}