// Marcus Pennington Coding 1 Spring 2026
// Random Numbers, Switch Statements & While Loops

// Fill out the rest of the code so that it displays "Random Numbers" to the console
// Then run it.


#include <iostream>
// for srand and rand
#include <cstdlib>
// for time
#include <ctime>
// Extra Random
#include <random>

using namespace std;



int main () {
        
    //only once, at the beginning of the program
    // seed the random number generator
    srand(time(0));

    cout << "Random Numbers" << endl;

    cout << "Our first random number: " << rand() << endl;

    int counter = 0;

    while (counter++ < 10) {
        int number = rand();
        int min = 50;
        int max = 100;
        int range = max - min; // 50
        int clampedNumber = (number % range) + min; // 50 -> 100

        cout << clampedNumber << endl;
    }

    // Set variables
        // the random number to be guessed
    int randomNumber = (rand() % 10) + 1;
        // the player's guess/input
    int playerGuess = -1;

    int totalGuesses = 0;

    // Start loop
    while (totalGuesses < 10) {
        // Ask for player's guess
        cout << "What is your guess from 1 to 10?\n>>";
        cin >> playerGuess;
        totalGuesses++;
        // Compare guess to random number
        if (playerGuess > randomNumber) {
            // Give result
            cout << "Too High." << endl;
        } else if (playerGuess < randomNumber) {
            cout << "Too Low." << endl;
        } else {
            cout << "Correct!" << endl;
            break;
        }
    }

    string guessSyntax = "guesses";

    if (totalGuesses == 1) {
        guessSyntax = "guess";
    }

    cout << "It took you " << totalGuesses << " " << guessSyntax << " to guess the number." << endl;

    minstd_rand0 randomGen (rand());

    cout << "An even more random number: " << randomGen() << endl;

    return 0;
}