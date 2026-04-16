// Marcus Pennington - Coding 1 class Spring 2026
// Functions

// To Compile: 'cl /EHsc fx.cpp'
// To Compile then Execute: 'cl /EHsc fx.cpp && fx'


/*
    Block Comment
*/

/*
    Functions
        returnType, Name, (Input Parameters), {Code}

    Sending and recieving variables to and from a function
    Passing by value
    Passing by reference
*/

#include <iostream>
#include <string>
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()
#include <vector>

using namespace std;

// Declare and define new function
// ReturnType = Void, which means it returns nothing

void sayHello() {
    cout << "Hello World!\n";
}

void doAddition(int firstNum, int secondNum) {
    cout << "Our first number is " << firstNum << ".\n";
    cout << "Our second number is " << secondNum << ".\n";
    cout << "Together they make " << firstNum + secondNum << ".\n";
}

int diceRoll(int diceSize = 6) {
    return rand() % diceSize + 1;    
}

bool askYesNo(string question = "Yes or No?\n") {
    int attempts = 0;
    while(attempts < 3) {
        cout << question;
        string input;
        getline(cin, input);
        if (input == "yes" || input == "YES" || input == "Yes") {
            return true;
        } else if (input == "no" || input == "No" || input == "NO") {
            return false;
        } else {
            cout << "Could not understand input, please respond 'Yes' or 'No'.\n";
        }
        attempts++;
    }
    cout << "Could not get valid input, returning 'Yes'.\n";
    return true;
}

void showVec(vector<string>& rVec) {
    for (int i = 0; i < rVec.size(); i++) {
        cout << rVec[i] << endl;
    }
}

void addStringToVec(vector<string>& rVec) {
    cout << "What name would you like to add?\n";
    cout << ">>";
    string input;
    getline(cin, input);

    rVec.push_back(input);
}

int main() {
    // Seed the random number generator
    srand(time(0));

    vector<string> names = {"Markiplier", "Pewdiepie", "JohnTron", "Jacksepticeye", "Ethan", "Muyskerm", "LordMinion77", "Smi77y", "Yumi", "Blarg"};

    showVec(names);

    addStringToVec(names);

    showVec(names);

    /*
        cout << "Finally, functions!\n";
        
        sayHello();

        doAddition(7,3);

        cout << diceRoll(20) << "\n";
        cout << diceRoll(20) << "\n";
        cout << diceRoll(20) << "\n";
        cout << diceRoll(20) << "\n";
        cout << diceRoll(20) << "\n";
        cout << diceRoll(20) << "\n";
        cout << diceRoll(20) << "\n";
        cout << diceRoll(20) << "\n";
        cout << diceRoll(20) << "\n";
        cout << diceRoll(20) << "\n";
        cout << diceRoll(20) << "\n";
        
        doAddition(diceRoll(20), diceRoll(20));
        doAddition(diceRoll(), diceRoll(20));

        bool shouldContinue = askYesNo("Do you want to keep playing?\n");
        cout << "Keep playing the game? " << shouldContinue;
    */

    if (askYesNo("Can I has Cheezburg?\n")) {
        cout << "Yippie!\n";
    } else {
        cout << "Fine, I will trap you in a forever loop.\n";
        int loops = rand() % 10 + 1;
        for (int i = 0; i < loops; i++) {
            string input;
            getline(cin, input);
            cout << "You are trapped forever.\n";
        }
        cout << "Okay I got bored, you're free to go.";
    }
    
    return 0;
}