// Marcus Pennington Coding 1
// 

// To Compile: 'cl /EHsc slime.cpp'
// To Compile then Execute: 'cl /EHsc slime.cpp && slime'

#include <iostream>
#include <string>
#include <vector>
#include <ctime> // random numbers
#include <cstdlib> // random numbers
#include <algorithm> // for random_shuffle

using namespace std;

// global vector
vector<string> names = {"Sloop", "Gloop", "Droop", "Slip", "Slide", "Shlorp", "Glorp", "Blorp", "Bloop", "Blop", "Splat"};

class baseSlime {
public:
    string name;
    int health;
    int maxHealth;
    int damage;
    int winCount = 0;
    bool isBoss = false;

    // default constructor
    baseSlime() {
        cout << "A new slime has been formed.\n";
        name = names[rand() % names.size()];
        health = rand() % 4 + 4;
        maxHealth = health;
        damage = rand() % 3 + 3;
    }

    baseSlime(string sName, int nHealth, int nDamage) {
        cout << "A new slime has been formed.\n";
        name = sName;
        health = nHealth;
        maxHealth = nHealth;
        damage = nDamage;
    }

    void hello() {
        cout << "I'm " << name << ", with " << health << " health ";
        cout << "and " << damage << " damage.\n";
    }

    bool attack(baseSlime& target) {
        //attempt an attack on the other slime.
        if (target.health > 0) {
            target.health = target.health - damage;
            cout << name << " did " << damage << " damage to ";
            cout << target.name << "!\n";
            cout << target.name << ": " << target.health << "/" << target.maxHealth << "\n";
        } else {
            cout << "Stop stop, he's already dead!\n";
        }
        if (target.health <= 0) {
            return true;
        } else {
            return false;
        }
    }
};

class bossSlime : public baseSlime {
public:
    int damageMultiplier = 3;

    bossSlime() {
        name = "boss";
        damage = damage * damageMultiplier;
        isBoss = true;
    }

    bossSlime(string sName, int nHealth, int nDamage) {
        name = sName;
        health = nHealth;
        maxHealth = nHealth;
        damage = nDamage;
        isBoss = true;
    }

    bossSlime(baseSlime slime) {
        health = slime.health;
        maxHealth = slime.maxHealth;
        damage = slime.damage * damageMultiplier;
        name = slime.name;
        cout << slime.name << " has become a boss slime!\n";
        isBoss = true;
    }

    bool attack(baseSlime& target) {
        cout << "Boss Attack!\n";
        if (target.health > 0) {
            target.health = target.health - damage;
            cout << name << " did " << damage << " damage to ";
            cout << target.name << "!\n";
            cout << target.name << ": " << target.health << "/" << target.maxHealth << "\n";
        } else {
            cout << "Stop stop, he's already dead!\n";
        }
        if (target.health <= 0) {
            return true;
        } else {
            return false;
        }
    }

    void taunt() {
        cout << "I will crush your bones with my slime!\n";
    }
};

int main() {
    srand(time(0)); // Seed Random Number
    cout << "Slime Battles\n";

    // create a slime.
    baseSlime gerald;
    gerald.hello();

    bossSlime destroyer;
    destroyer.hello();
    destroyer.taunt();

    bool fight = true;
    while (fight) {
        gerald.attack(destroyer);
        if (destroyer.health <= 0) {
            cout << destroyer.name << " was defeated!\n";
            fight = false;
            break;
        }
        destroyer.attack(gerald);
        if (gerald.health <= 0) {
            cout << gerald.name << " was defeated!\n";
            fight = false;
            break;
        }
    }

    // Create a vector of slimes
    // then pick two to fight.
    // global variables.

    // create a new vecotr of slimes with a size of 6.
    vector<baseSlime> pudding(6);

    cout << "Here's our pudding of slimes:\n\n";
    for (auto slime: pudding) {
        cout << slime.name << "\n";
    }

    bool battleRoyal = true;
    string input = "";

    while (battleRoyal && pudding.size() > 0) {
        random_shuffle(pudding.begin(), pudding.end());

        auto& a = pudding[0];
        baseSlime& b = pudding[1];

        while (a.health > 0 && b.health > 0) {
            if (a.attack(b)) {
                cout << b.name << " has been defeated by " << a.name << "!\n";
                pudding.erase(find(pudding.begin(), pudding.end(), pudding[1]));
                a.winCount++;
            }
            if (b.attack(a)) {
                cout << a.name << " has been defeated aby " << b.name << "!\n";
                pudding.erase(find(pudding.begin(), pudding.end(), pudding[0]));
                b.winCount++;
            }
        }
        cout << "Do next battle? Yes or No\n>>";
        getline(cin,input);
        if (input == "Yes") {
            battleRoyal = true;
        } else {
            battleRoyal = false;
        }
    }

    return 0;
}