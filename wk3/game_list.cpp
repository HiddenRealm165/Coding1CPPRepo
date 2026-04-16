// Marcus Pennington - Coding 1 class Spring 2026
// Program to manage a list of games

// To Compile: 'cl /EHsc game_list.cpp'
// To Compile then Execute: 'cl /EHsc game_list.cpp && game_list'

#include <iostream>
// for getline()
#include <string>
//for vectors and iterators
#include <vector>
// for find(), sort(), and random_shuffle()
#include <algorithm>


using namespace std;

int main() {
    // Creating required variables;
    string default_message = "No games have been added to the list.";
    vector<string> game_list = {default_message};

    string input;

    // Introduce the User
    cout << "Here is the current state of the list:\n";
    for (int i = 0; i < game_list.size(); i++) {
        cout << game_list[i] << "\n";
    }
    cout << "What would you like to do? \n";
    cout << "Options: 'sort', 'read', 'add', 'edit', 'remove', 'quit'\n";
    cout << ">>";
    getline (cin, input);

    // Begin main input loop
    while (input != "quit") {
        if (input == "sort") {
            // Simple sort request
            sort(game_list.begin(), game_list.end());

            cout << "Game list has been alphabetically sorted.\n";
        } else if (input == "read") {
            // Simple list read function
            cout << "Here is the current state of the list:\n\n";
            for (int i = 0; i < game_list.size(); i++) {
                cout << game_list[i] << "\n";
            }
            cout << "\n";
        } else if (input == "add") {
            // Get new game title.
            cout << "What game title would you like to add?\n";
            cout << ">>";
            getline(cin, input);

            // Insert new game to list
            game_list.push_back(input);
            cout << "Game has been added to the list. Recommend running 'sort' command.\n";

            // Clear the defualt message for empty list if still in list.
            auto iter = find(game_list.begin(), game_list.end(), default_message);
            if (iter != game_list.end()) {
                game_list.erase(iter);
            }
        } else if (input == "edit") {
            // Get title to edit
            cout << "What game title would you like to edit?\n";
            cout << ">>";
            getline(cin, input);

            // Create iterator to search for the title
            vector<string>::iterator iter = find(game_list.begin(), game_list.end(), input);

            // If found in list (( if search does NOT reach end of list)) ...
            if (iter != game_list.end()) {
                // Confirm found title to user
                cout << "Editing " << *iter <<":\n";
                cout << ">>";
                getline(cin, input);

                // replace item in list with new input
                *iter = input;
                cout << "Game title has been edited.\n";
            } else {
                // Else inform user of not finding the title.
                cout << "Could not find that game title.\n";
            }
        } else if (input == "remove") {
            // Get title to remove
            cout << "What game title would you like to remove?\n";
            cout << ">>";
            getline(cin, input);

            // Creat iterator to search for title
            auto iter = find(game_list.begin(), game_list.end(), input);

            // If found in list (( if search does NOT reach end of list)) ...
            if (iter != game_list.end()) {
                // Inform user of located title and removal
                cout << "We found the game in the list: " << *iter << "\n";
                cout << "Removing it from the list.";

                // Remove game from list
                game_list.erase(iter);
                cout << "Game has been removed.\n";

                // Add the default message if the list becomes empty.
                if (game_list.size() < 1) {
                    game_list.push_back(default_message);
                }
            } else {
                // Else inform user title was not found.
                cout << "Game could not be found.\n";
            }
        } else {
            // Inform player is input is not recongized.
            cout << "Command not recognized.\n";
        }

        // Request new input.
        cout << "What would you like to do? \n";
        cout << "Options: 'sort', 'read', 'add', 'remove', 'quit'\n";
        cout << ">>";
        getline (cin, input);
    }
    return 0;
}