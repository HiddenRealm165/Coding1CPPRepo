// Marcus Pennington Coding 1 Week 4
// Writing to and reading from files.

// To Compile: 'cl /EHsc file.cpp'
// To Compile then Execute: 'cl /EHsc file.cpp && file'

#include <iostream>
#include <string>
#include <vector>
#include <fstream> // file stream

using namespace std;

void read(string path = "save.txt") {
    // create a new var, and try to open a file
    string line;
    ifstream readFile(path);

    if (readFile.is_open()) {
        cout << "The file is open.\n";
        while(getline(readFile, line)) {
            cout << line << endl;
        }
    } else {
        cout << "Couldn't open that file.\n";
    }

    // after we're done with the file, close it.
    readFile.close();
}

void read(vector<string>& vec, string path = "save.txt") {
    string line;
    ifstream readFile(path);

    if (readFile.is_open()) {
        cout << "The file is open.\n";
        while(getline(readFile, line)) {
            vec.push_back(line);
        }
    } else {
        cout << "Couldn't open that file.\n";
    }

    // after we're done with the file, close it.
    readFile.close();

}

void write(vector<string>& vec, string path = "save.txt") {
    ofstream writeFile(path);

    if (writeFile.is_open()) {
        for (int i = 0; i < vec.size(); i++) {
            writeFile << vec[i] << endl;
        }
    } else {
        cout << "Could not write to file.";
    }
    writeFile.close();
}

int main() {
    cout << "Let's write to a file.\n";
    vector<string> content;
    string input = "AAAAAAAAAAAHHHHHHHHHHHH";

    string path = "save.txt";

    cout << "What file would you like to open?\nLeave blank to use default.\n";
    getline(cin, input);
    if (input != "") {
        path = input;
    }

    // open or "load" the file (read)
    // make some changes
    // save the file
    // close the file
    read(path); // Show existing list
    read(content, path); // Load list into vector

    //-----------------------------
    cout << "What names would you like to add?\n";
    cout << "Enter an empty line to stop.\n";

    while (input != "") {
        cout << ">>";
        getline(cin, input);
        if (input != "") {
            content.push_back(input);
        }
    }

    // Call write function and send it our names vector.
    write(content, path);

    return 0;
}