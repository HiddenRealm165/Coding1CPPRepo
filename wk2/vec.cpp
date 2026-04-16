//Marcus Pennington Coding 1 Spring 2026
// Vectrs, Iterators, and ALgorithms

// To Compile: 'cl /EHsc vec.cpp'
// To Compile then Execute: 'cl /EHsc vec.cpp && vec'

#include <iostream>
// for getline()
#include <string>
//for vectors and iterators
#include <vector>
// for find(), sort(), and random_shuffle()
#include <algorithm>


using namespace std;

int main() {
    cout << "Let's learn about vectors\n";

    string input;
    vector<string> favGames = {
        "Red Dead Redepmtion 2",
        "Pokemon Channel",
        "One Shot",
        "Pokemon Snap",
        "Z.A.T.O.",
        "Omori",
        "Ready or Not"
    };

    // to get int from an input:
        // int numberInput = stoi(input);

    do {
        cout << "What would you like to do?\n";
        cout << "You can type 'push', 'find', 'remove', or 'quit'.\n";

        getline(cin, input); // get input from the player
        

        if (input == "push") {
            cout << "Lets make our first vector of strings.\n";

            vector<string> names;

            names.push_back("Pikachu");
            names.push_back("Bulbasaur");
            names.push_back("Charizard");
            names.push_back("Squirtle");
            names.push_back("Kingler");
            names.push_back("Pidgeotto");
            names.push_back("Muk");
            names.push_back("Butterfree");

            cout << "here are your names!\n";
            for (int i = 0; i < names.size(); i++) {
                cout << "\t" << names[i] << "\n";
            }

            cout << "Those are " << names.size() << " names.\n\n";

            cout << *(names.end() - 1) << " found a partner. Release them from your team.\n";

            names.pop_back(); // pop_back() removes the last element form the vector;
            
            cout << "Your new list of names\n";
            for (int i = 0; i < names.size(); i++) {
                cout << "\t" << names[i] << "\n";
            }

            cout << "Those are " << names.size() << " names.\n\n";

        } else if (input == "find") {
            cout << "Lets try to use the find algorithm.\n";

            // a collection of strings to use for the iterator
            vector<string> favs = {"Gengar", "Gallade", "Lycanrock", "Mew", "Deoxys", "Latias", "Latios", "Lugia"};
            
            // building an iterator that 'points' to a spot in the vector.
            vector<string>::iterator iter;

            cout << "These are your favorites.\n";
            for (int i = 0; i < favs.size(); i++) {
                cout << "\t" << favs[i] << "\n";
            }

            // make iter point at the first element in the vector
            iter = favs.begin();

            // the asterisk is a "dereference operator" so that we can get
                // the value that the iter is pointing with a direct reference.
            cout << "iter is pointing at " << *iter << ".\n";

            cout << "What name would you like to find?\n";
            getline(cin, input);

            // use the find algorithm
            iter = find(favs.begin(), favs.end(), input);
            if (iter != favs.end()) {
                cout << "We've found " << *iter << ".\n";
                cout << "Would you like to change this item?\n";
                getline(cin, input);
                if (input == "yes") {
                    cout << "What would you likie to change this fav to?\n";
                    getline(cin, input);

                    *iter = input; // changing the vectorfav at the interator index.
                }

                cout << "These are your updated favorites.\n";
                for (int i = 0; i < favs.size(); i++) {
                    cout << "\t" << favs[i] << "\n";
                }
            } else {
                cout << "We could not find that name.\n";
            }

        } else if (input == "quit") {
            cout << "Thanks for playing!\n";
            break;
        } else if (input == "remove") {
            // Sort the list of games alphabetically
            sort(favGames.begin(), favGames.end());

            cout <<  "Here are your favorite games:\n";
            
            for (int i = 0; i < favGames.size(); i++) {
                cout << favGames[i] << "\n";
            }

            cout << "What game would you like to remove from the list?\n";
            getline(cin, input);

            auto iter = find(favGames.begin(), favGames.end(), input);

            if (iter != favGames.end()) {
                cout << "We found the game in the list: " << *iter << "\n";
                cout << "Removing it from the list.";

                favGames.erase(iter);
            }
            cout << "Here is your new list of games:\n";
            for (int i = 0; i < favGames.size(); i++) {
                cout << favGames[i] << "\n";
            }


        } else {
            cout << "I didn't recognize that command.\n";
        }

    } while (input != "quit");

    // create a new vector of strings


    return 0;
}