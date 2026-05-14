// Marcus Pennington Coding 1
// Slime Tomagachi

// To Compile: 'cl /EHsc final.cpp'
// To Compile then Execute: 'cl /EHsc final.cpp && final'

#include <iostream>
#include <string>
#include <vector>
#include <ctime> // random numbers
#include <cstdlib> // random numbers
#include <algorithm> // for random_shuffle
#include <vector>
#include <fstream> // file stream

using namespace std;

//Global Variables
bool gettingInput;
string input;
vector<string> slimeNames;

void read(string path = "SlimeNames.txt") {
    // create a new var, and try to open a file
    string line;
    ifstream readFile(path);

    if (readFile.is_open()) {
        while(getline(readFile, line)) {
            cout << line << endl;
        }
    } else {
        cout << "Error loading SlimeNames file.\n";
    }

    // after we're done with the file, close it.
    readFile.close();
}

void read(vector<string>& vec, string path = "SlimeNames.txt") {
    string line;
    ifstream readFile(path);
    if (readFile.is_open()) {
        while(getline(readFile, line)) {
            vec.push_back(line);
        }
    } else {
        cout << "Error loading SlimeNames file.\n";
    }
    // after we're done with the file, close it.
    readFile.close();
}

// This is the basic default values of a Slime.
class baseSlime {
private:
    string name;
    int maxHealth;
    int health;
    int maxHunger;
    int hunger;
    int maxHappy;
    int happy;
    int attack;
    int defense;
    int speed;
    int victoryCount = 0;

public:
    bool isDefending = false;
    bool isAlive = true;
    bool isRunning = false;

    // Construct Default Slime
    baseSlime() {
        name = "Slime";
        maxHealth = 10;
        health = maxHealth;
        maxHunger = 15;
        hunger = 0;
        maxHappy = 100;
        happy = maxHappy;
        attack = 10;
        defense = 5;
        speed = 10;
    }

    /* Standard Slime Constructor
    Used to create slimes within normal thresholds for stats.
    Params: Name, MaxHealth, MaxHunger, Attack, Defense, Speed
    */
    baseSlime(string sName, int nMaxHealth, int nAttack, int nDefense, int nSpeed) {
        name = sName;
        maxHealth = nMaxHealth;
        health = maxHealth;
        maxHunger = 15;
        hunger = 0;
        maxHappy = 100;
        happy = maxHappy;
        attack = nAttack;
        defense = nDefense;
        speed = nSpeed;
    }

    /* Full Slime Constructor
    Used to assign all values manually, can create non-standard or "broken" slimes.
    Params: Name, MaxHealth, Health, MaxHunger, Hunger, MaxHappy, Happy, Attack, Defense, Speed
    */
    baseSlime(string sName, int nMaxHealth, int nHealth, int nMaxHunger, int nHunger, int nMaxHappy, int nHappy, int nAttack, int nDefense, int nSpeed) {
        name = sName;
        maxHealth = nMaxHealth;
        health = nHealth;
        maxHunger = nMaxHunger;
        hunger = nHunger;
        maxHappy = nMaxHappy;
        happy = nHappy;
        attack = nAttack;
        defense = nDefense;
        speed = nSpeed;
    }
//Health
    /*
        GetHealth
    */
    int GetHealth() {
        return health;
    }
    /* SetHealth
    Params: Value to set to
    Clamps between 0 and maxHealth
    */
    void SetHealth(int nHealth) {
        // Alter health by amtHealth
        health += nHealth;
        //Clamp health between 0 and maxHealth;
        if (health > maxHealth) {
            health = maxHealth;
        } else if (health > 0) {
            health = 0;
        }
        if (health == 0) {
            isAlive = false;
        }
    }
    /* AddHealth
    Params: Amount of Health
    */
    void AddHealth(int amtHealth) {
        // Alter health by amtHealth
        health += amtHealth;
        //Clamp health between 0 and maxHealth;
        if (health > maxHealth) {
            health = maxHealth;
        } else if (health < 0) {
            health = 0;
        }
        if (health == 0) {
            isAlive = false;
        }
    }
    /*
        GetMaxHealth
    */
    int GetMaxHealth() {
        return maxHealth;
    }
    /* SetMaxHealth
    Params: Value to set maxHealth to.
    */
    void SetMaxHealth(int nMaxHealth) {
        maxHealth = nMaxHealth;
    }

// Hunger
    /*
        GetHunger
    */
    int GetHunger() {
        return hunger;
    }
    /* SetHunger
    Params: Value to set hunger to.
    Clamps between 0 and maxHunger
    */
    void SetHunger(int nHunger) {
        hunger = nHunger;
        //clamp hunger between 0 and maxHunger
        if (hunger > maxHunger) {
            hunger = maxHunger;
        } else if (hunger < 0) {
            hunger = 0;
        }
    }
    /* AddHunger
    Params: Amount of Food
    */
    void AddHunger(int amtFood = 0) {
        //Alter hunger by amtFood
        hunger += amtFood;
        //clamp hunger between 0 and maxHunger
        if (hunger > maxHunger) {
            hunger = maxHunger;
        } else if (hunger < 0) {
            hunger = 0;
        }
    }
    /*
        GetMaxHunger
    */
    int GetMaxHunger() {
        return maxHunger;
    }
    /*SetMaxHunger
    Parms: Value to set maxHunger to.
    */
    void SetMaxHunger(int nMaxHunger) {
        maxHunger = nMaxHunger;
    }


//Happy
    /*
        GetHappy
    */
    int GetHappy() {
        return happy;
    }
    /* SetHappy
    Params: Value to set happy to.
    Clamps between 0 and maxHappy
    */
    void SetHappy(int nHappy) {
        happy = nHappy;
        if (happy > maxHappy) {
            happy = maxHappy;
        } else if (happy < 0) {
            happy = 0;
        }
    }
    /* AddHappy
    Params: Amount of Fun
    */
    void AddHappy(int amtFun) {
        // Alter happy by amtFun
        happy += amtFun;
        //Clamp happy between 0 and maxHappy
        if (happy > maxHappy) {
            happy = maxHappy;
        } else if (happy < 0) {
            happy = 0;
        }
    }
    /*
        GetMaxHappy
    */
    int GetMaxHappy() {
        return maxHappy;
    }
    /* SetMaxHappy
    Params: Value to set maxHappy to.
    */
    void SetMaxHappy(int nMaxHappy) {
        maxHappy = nMaxHappy;
    }

//Name
    /*
        GetName
    */
    string GetName() {
        return name;
    }
    /* SetName
    Params: Name to change to.
    */
    void SetName(string sName) {
        name = sName;
    }

//Attack
    /*
        GetAttack
    */
    int GetAttack() {
        return attack;
    }
    /* SetAttack
    Params: Value to set Attack to.
    */
    void SetAttack(int nAttack) {
        attack = nAttack;
    }
//Defense
    /*
        GetDefense
    */
    int GetDefense() {
        return defense;
    }
    /* SetDefense
    Params: Value to set Defense to.
    */
    void SetDefense(int nDefense) {
        defense = nDefense;
    }
//Speed
    /*
        GetSpeed
    */
    int GetSpeed() {
        return speed;
    }
    /* SetSpeed
    Params: Value to set Speed to.
    */
    void SetSpeed(int nSpeed) {
        speed = nSpeed;
    }
//VictoryCount
    /*
        GetVictoryCount
    */
    int GetVictoryCount() {
        return victoryCount;
    }
    /* SetVictoryCount
    Params: Value to set victoryCount to.
    Clamps to 0 or above.
    */
    void SetVictoryCount(int nVictoryCount) {
        victoryCount = nVictoryCount;
        if (victoryCount < 0) {
            victoryCount = 0;
        }
    }
    /* AddVictoryCount
    Params: Value to add to victoryCount
    Clamps to 0 or above.
    */
    void AddVictoryCount(int amt) {
        victoryCount += amt;
        if (victoryCount < 0) {
            victoryCount = 0;
        }
    }

//Status
    /* Show Full Stats
    */
    void DisplayStatus() {
        cout << "\n";
        cout << name << "\n";
        cout << "Health: " << health << "/" << maxHealth << "\n";
        cout << "Attack: " << attack << "\n";
        cout << "Defense: " << defense << "\n";
        cout << "Speed: " << speed << "\n";
        cout << "Hunger: " << hunger << "/" << maxHunger << "\n";
        cout << "Happiness: " << happy << "/" << maxHappy << "\n";
        cout << "\n";
    }

//Battle Mechanics
    bool Attack(baseSlime& slime) {
        int damage = attack;
        //Check if defending.
        if (slime.isDefending) {
            damage = damage - slime.GetDefense();
            if (damage < 0) {
                damage = 0;
            }
            cout << name << " did " << damage << " damage!\n";
            slime.AddHealth(damage * -1);
            return true;
        } else {
            if (DodgeCheck(slime)) {
                cout << "The attack was avoided!\n";
                return true;
            } else {
                damage = damage - floor((slime.GetDefense() / 2));
                cout << name << " did " << damage << " damage!\n";
                slime.AddHealth(damage * -1);
                return true;
            }
        }
        return false;
    }
    /* DodgeCheck
    If defending slime's speed is higher than attacking slime's speed, roll a random chance to dodge attack.
    */
    bool DodgeCheck(baseSlime slime) {
        if (slime.GetSpeed() > speed) {
            int randChance = rand() % 10 + 1;
            if (randChance < 4) {
                return true;
            }
        }
        return false;
    }
    /* Heal
    Try to heal some HP
    */
    bool Heal() {
        int randHeal = rand() % 5 + 1;
        AddHealth(randHeal);
        cout << name << " Healed for " << randHeal << "!\n";
        return true;
    }
    /* RunCheck
    Params: Enemy Slime to check against
    Determines if faster, gives slime random 60% chance to escape battle.
    */
    bool RunCheck(baseSlime enemy) {
        if (speed > enemy.GetSpeed()) {
            int randChance = rand() % 10 + 1;
            if (randChance < 7) {
                cout << name << " escaped!\n";
                return true;
            }
        }
        cout << name << " can't escape!\n";
        return false;
    }
    /* RandomBattleTurn
    Params: Opponent Slime
    Determine what to do during turn and handle turn.
    */
    bool RandomBattleTurn(baseSlime& enemy) {
        int randChoice = rand() % 3 + 1;
        if (randChoice == 1) {
            cout << name << " attacks!\n";
            if (Attack(enemy)) {
                return true;
            } else {
                cout << "Error with Attack\n";
            }
        } else if (randChoice == 2) {
            cout << name << " is defending!\n";
            isDefending = true;
            return true;
        } else if (randChoice == 3) {
            cout << name << " is healing!\n";
            Heal();
            return true;
        } else {
            cout << "Error in RandomBattleTurn\n";
            return false;
        }
    }
    /* BattleTurn
    Params: Input for what choice to do.
    Handles the slime's battle turn.
    */
    bool BattleTurn(baseSlime& enemy) {
        gettingInput = true;
        while(gettingInput) {
            cout << "What would you like to do?\n";
            cout << "Attack, Defend, Heal, Run\n";
            cout << ">>";
            getline(cin, input);
            if (input == "Attack" || input == "attack" || input == "ATTACK") {
                cout << name << " attacks!\n";
                if (Attack(enemy)) {
                    gettingInput = false;
                    return true;
                } else {
                    cout << "Error with Attack\n";
                    gettingInput = false;
                    return true;
                }
            } else if (input == "Defend" || input == "defend" || input == "DEFEND") {
                cout << name << " is defending!\n";
                isDefending = true;
                gettingInput = false;
                return true;
            } else if (input == "Heal" || input == "heal" || input == "HEAL") {
                cout << name << " is healing!\n";
                Heal();
                gettingInput = false;
                return true;
            } else if (input == "Run" || input == "run" || input == "RUN") {
                gettingInput = false;
                isRunning = true;
                return true;
            } else {
                cout << "Your slime can't do that.\n";
            }
        }
        cout << "Error in BattleTurn";
        return false;
    }
}; // End of baseSlime

/* Train
Params: baseSlime
Will request type of training, and then increase relevant stats.
Returns: True if Training ends the day. Returns False to send back to daily task choice.
*/
bool Train(baseSlime& slime) {
    int randTrainingBonus = rand() % 3 + 1;
    cout << "Which stat would you like to train?\n";
    cout << "Health, Attack, Defense, Speed\n";
    cout << ">>";
    getline(cin, input);
    if (input == "Health" || input == "health" || input == "HEALTH") {
        slime.SetMaxHealth(slime.GetMaxHealth() + randTrainingBonus);
        cout << "Your slime's health increased by " << randTrainingBonus << "!\n";
        return true;
    } else if (input == "Attack" || input == "attack" || input == "ATTACK") {
        slime.SetAttack(slime.GetAttack() + randTrainingBonus);
        cout << "Your slime's attack increased by " << randTrainingBonus << "!\n";
        return true;
    } else if (input == "Defense" || input == "defense" || input == "DEFENSE") {
        slime.SetDefense(slime.GetDefense() + randTrainingBonus);
        cout << "Your slime's defense increased by " << randTrainingBonus << "!\n";
        return true;
    } else if (input == "Speed" || input == "speed" || input == "SPEED") {
        slime.SetSpeed(slime.GetSpeed() + randTrainingBonus);
        cout << "Your slime's speed increased by " << randTrainingBonus << "!\n";
        return true;
    } else {
        cout << "No idea what you're trying to train.\n";
        return false;
    }
}

/* Feed
Params: baseSlime
Attempts to feed the slime food.
Returns true if Feed ends the day. Returns false to send back to daily choice.
*/
bool Feed(baseSlime& slime) {
    //Get Random food value between 1 and 5, and then multiply by 1 to remove from hunger stat.
    int randFood = (rand() % 5 + 1) * -1;
    cout << slime.GetName() << " eats " << randFood * -1 << " food.\n";
    slime.AddHunger(randFood);
    cout << "You feed your slime and they look ";
    if (slime.GetHunger() < 1) {
        cout << "full.\n";
    } else if (slime.GetHunger() < 2) {
        cout << "satisfied.\n";
    } else if (slime.GetHunger() < 5) {
        cout << "a little hungry, but good to go.\n";
    } else if (slime.GetHunger() < 10) {
        cout << "ready to work, but still hungry.\n";
    } else {
        cout << "very hungry still...\n";
    }
    return true;
}

/* Play
Params: baseSlime
Plays with Slime to increase Happiness
Returns true if Playing ends the day. Returns false to send back to daily choice.
*/
bool Play(baseSlime& slime) {
    //Get Random fun value between 1 and 5
    int randFun = rand() % 5 + 1;
    slime.AddHappy(randFun);
    cout << "You played with your slime.\n";
    return true;
}

bool Battle(baseSlime& slime) {
    cout << "You encounter a random slime to battle!\n";
    // Create random stat variables.
    int randAttack = rand() % 10 + 1;
    int randDefense = rand() % 5 + 1;
    int randSpeed = rand() % 10 + 1;
    int randHealth = rand() % 100 + 1;
    random_shuffle(slimeNames.begin(), slimeNames.end());
    string randName = slimeNames[0];
    // Create a random slime with random stats.
    baseSlime oSlime = baseSlime(randName, randHealth, randAttack, randDefense, randSpeed);
    oSlime.DisplayStatus();
    if (randAttack + randDefense + randSpeed > slime.GetAttack() + slime.GetDefense() + slime.GetSpeed() + 3) {
        cout << "The opponent slime looks pretty strong...\n";
    } else if (randAttack + randDefense + randSpeed < slime.GetAttack() + slime.GetDefense() + slime.GetSpeed() - 3) {
        cout << "The opponent slime looks weaker than you.\n";
    } else {
        cout << "You're evenly matched!\n";
    }

    bool battleLoop = true;
    while (battleLoop) {
        bool turnLoop = true;
        bool oppTurn = false;
        bool playerTurn = false;
        while (turnLoop) {
            cout << oSlime.GetName() << "'s Health: " << oSlime.GetHealth() << "/" << oSlime.GetMaxHealth() << "\n";
            cout << slime.GetName() << "'s Health: " << slime.GetHealth() << "/" << slime.GetMaxHealth() << "\n";
                cout << "\n\n";
            if (oSlime.GetSpeed() > slime.GetSpeed()) {
                cout << "The opponent's turn is first!\n";
                oSlime.isDefending = false;
                oppTurn = oSlime.RandomBattleTurn(slime);
                cout << "\n\n";

                if (slime.isAlive) {
                    slime.isDefending = false;
                    playerTurn = slime.BattleTurn(oSlime);
                    cout << "\n\n"; 
                } else {
                    playerTurn = true;
                }
            } else {
                cout << "Your turn is first!\n";
                slime.isDefending = false;
                playerTurn = slime.BattleTurn(oSlime);
                cout << "\n\n";
                
                if (oSlime.isAlive) {
                    oSlime.isDefending = false;
                    oppTurn = oSlime.RandomBattleTurn(slime);
                    cout << "\n\n";
                } else {
                    oppTurn = true;
                }
            }
            if (oppTurn && playerTurn) {
                turnLoop = false;
            } else {
                cout << "Turn Loop Error";
                break;
            }
        }
        if (oSlime.isAlive == false) {
            cout << oSlime.GetName() << " has been defeated!\n";
            slime.AddVictoryCount(1);
            battleLoop = false;
        }
        if (slime.isAlive == false) {
            cout << slime.GetName() << " has fallen...\n";
            battleLoop = false;
        }
        if (slime.isRunning) {
            if (slime.RunCheck(oSlime)) {
                battleLoop = false;
            } else {
                slime.isRunning = false;
            }
        }
    }
    return true;
}

int main() {
    srand(time(0)); // Seed Random Number
    bool quitGame = false;
    read(slimeNames, "SlimeNames.txt");

    baseSlime pSlime = baseSlime(); // The player's slime.
    //Intro
    cout << "Hello, welcome to your new Slime journey!" << "\n";
    cout << "First thing is first, are you a boy or a girl?\n";
    cout << ">>";
    getline(cin, input);
    cout << "Just kidding, it doesn't matter for this. Instead...\n";
    gettingInput = true;
    while (gettingInput) {
        cout << "What kind of focus do you want for your slime?\n";
        cout << "Options: Attack, Defense, Speed\n";
        cout << ">>";
        getline(cin, input);
        if (input == "Attack" || input == "attack" || input == "ATTACK") {
            // Name, MaxHealth, Attack, Defense, Speed
            pSlime = baseSlime("Slime", 100, 10, 3, 4);
            cout << "Oh, you have anger management issues? Great!\n";
            gettingInput = false;
        } else if (input == "Defense" || input == "defense" || input == "DEFENSE") {
            // Name, MaxHealth, Attack, Defense, Speed
            pSlime = baseSlime("Slime", 100, 5, 8, 2);
            cout << "Ah, so you prefer to just sit there and take it. Gotcha!\n";
            gettingInput = false;
        } else if (input == "Speed" || input == "speed" || input == "SPEED") {
            // Name, MaxHealth, Attack, Defense, Speed
            pSlime = baseSlime("Slime", 100, 5, 3, 8);
            cout << "So you just want to run away from your problems then? That's good!\n";
            gettingInput = false;
        } else {
            cout << "We don't know of any slimes of that type.\n";
        }
    }
    cout << "Now, what do you want to name your slime?\n";
    cout << ">>";
    getline(cin, input);
    pSlime.SetName(input);
    cout << "I hope the slime likes that name. It's kinda hard to tell.\n";
    cout << "Anyway, here are your slimes current stats. I hope this is okay with you, because the programmer didn't feel like making this whole thing into a loop so that we can go back to make changes without just rerunning the whole program... That's life.\n";
    cout << "Anyway, the stats.\n";
    pSlime.DisplayStatus();

    cout << "\n";
    cout << "Okay, now that you have your slime, you have officially become a Slimer-\n";
    cout << "No. That's a horrible term for it... Lets just stick with Trainer.\n";
    cout << "You are ready to begin your slime adventure. Now get out, I have like 3 more of these to do.\n";
    cout << "\n\n";
    cout << "WELCOME TO YOUR SLIME ADVENTURE.\n";
    cout << "Here are your options for what you would like to do each day:\n";
    bool dayloop = true;
    int dayCounter = 1;
    while (dayloop) {
    // Daily Task
        gettingInput = true;
        while (gettingInput) {
            cout << "What would you like to do?\n";
            cout << "Train. Feed. Play. Battle. Nothing. Status. Quit.\n";
            cout << ">>";
            getline(cin, input);
            if (input == "Train" || input == "train" || input == "TRAIN") {
                if (pSlime.GetHunger() > 10) {
                    cout << "Too hungry to train...\n";
                } else if (pSlime.GetHunger() > 5) {
                    cout << "Your slime begrudgingly gets to work while hungry.\n";
                    pSlime.AddHappy(-10);
                    if (Train(pSlime)) {
                        pSlime.AddHunger(1);
                        gettingInput = false;
                    }
                } else {
                    if (Train(pSlime)) {
                        pSlime.AddHunger(1);
                        gettingInput = false;
                    }
                }
            } else if (input == "Feed" || input == "feed" || input == "FEED") {
                if (Feed(pSlime)) {
                    gettingInput = false;
                }
            } else if (input == "Play" || input == "PLAY" || input == "play") {
                if (pSlime.GetHunger() > 10) {
                    cout << "Too hungry to play...\n";
                } else {
                    if (Play(pSlime)) {
                        gettingInput = false;
                    }
                }
            } else if (input == "Battle" || input == "battle" || input == "BATTLE") {
                if (pSlime.GetHunger() > 9) {
                    cout << "Too hungry to battle...\n";
                } else if (pSlime.GetHunger() > 5) {
                    cout << "Your slime begrudgingly gets to work while hungry.\n";
                    pSlime.AddHappy(-10);
                    if (Battle(pSlime)) {
                        pSlime.AddHunger(1);
                        gettingInput = false;
                    }
                } else {
                    if (Battle(pSlime)) {
                        pSlime.AddHunger(1);
                        gettingInput = false;
                    }
                }
            } else if (input == "Status" || input == "status" || input == "STATUS") {
                pSlime.DisplayStatus();
            } else if (input == "Quit" || input == "quit" || input == "QUIT") {
                cout << "You've abandoned your slime to the wild... How could you?\n";
                quitGame = true;
            } else if (input == "Nothing" || input == "nothing" || input == "NOTHING") {
                cout << "You laze around all day, probably doom-scrolling on your phone and watching stuff on your computer.\n";
                gettingInput = false;
            } else {
                cout << "Are you crazy? You can't do that!\n";
            }
            if (quitGame) {
                break;
            }
        }
        if (quitGame) {
            break;
        }
    //End of Daily Task
        cout << "\n\n\n";
        cout << "The sun sets, and you get some rest with your slime.\n";
        pSlime.AddHunger(1);
        // Slime will start to starve each day if too hungry, otherwise will heal slowly each day.
        if (pSlime.GetHunger() == pSlime.GetMaxHunger()) {
            pSlime.AddHealth(-25);
            pSlime.AddHappy(-50);
            if (pSlime.GetHealth() < pSlime.GetMaxHealth() / 2 && pSlime.GetHappy() < 50) {
                cout << "You wake up in the middle of the night being engulfed by your starving slime.\n";
                cout << "Later your slime is discovered 'abandoned' without an owner, and is given the another trainer who actually feeds their slimes.\n";
                cout << "Nobody remembers your name. Nobody cares. You were better food than a trainer.\n";
                cout << "BAD END.\n";
                break;
            }
        } else if (pSlime.GetHunger() < 3) {
            pSlime.AddHappy(5);
            pSlime.Heal();
        } else {
            pSlime.Heal();
        }
        if (pSlime.isAlive == false) {
            cout << "Due to the death of your slime, your liscense to train slimes is being revoked.\n";
            cout << "Wait... What do you mean you never got a liscense?\n";
            cout << "Uh oh...\n";
            cout << "BAD END\n";
            break;
        }
        dayCounter += 1;
        cout << "\n";
        cout << "It's day " << dayCounter << ".\n";
        cout << "You've defeated " << pSlime.GetVictoryCount() << " other slimes.\n";
    }

    return 0;
}