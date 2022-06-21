#include <iostream>
#include <string>
#include <map>
#include <iterator>
using namespace std;

//////// PROTOTYPES ////////
void bossInstances();
void introConditional();

//////// BOSS PARENT CLASS ////////
class Boss {
    public:
        string name;
        string type;
        int hp;
        bool parriable;
        bool breakPoise;
        string damageTypeDealt;
        map< string, int > absorptions;
        map< string, int > resistances;
        int difficulty;
        int ugliness;
        int beauty;
        int annoying;

    // Default constructor
    Boss() {};

    // constructor
    Boss(string bossName, string bossType, int bossHP, bool isParriable, bool canBreakPoise, string bossDamageTypeDealt) {
        name = bossName;
        type = bossType;
        hp = bossHP;
        parriable = isParriable;
        breakPoise = canBreakPoise;
        damageTypeDealt = bossDamageTypeDealt;
    }

    // Method for printing boss attributes
    void printAttributes() {
        cout << name << endl;
        cout << "Boss Type: " << type << endl;
        cout << "HP: " << hp << endl;
        cout << "Parriable: " << parriable << endl;
        cout << "Break Poise: " << breakPoise << endl;
        cout << "Damage Type: " << damageTypeDealt << endl;
        
        // print absorptions
        for (auto const& x : absorptions) {
        cout << '\t' << x.first << '\t' << x.second
             << '\n';
        }

        // print resistances
        for (auto const& x : resistances) {
        cout << '\t' << x.first << '\t' << x.second
             << '\n';
        }
    }

    //////// METHOD FOR RATING BOSSES ////////
    void rateBoss() {
        // SURVEY RESULTS WILL UPDATE BOSS INSTANCES BASED ON CATEGORY, SUCH AS EASE, DIFFICULTY, UGLINESS, ETC.
        cout << "1. " << name << endl;
        cout << "Difficulty: ";
        cin >> difficulty;
        cout << "Ugliness: ";
        cin >> ugliness;
        cout << "Beauty: ";
        cin >> beauty;
        cout << "Annoying: ";
        cin >> annoying;
        cout << endl;
    }

    //////// METHOD FOR PRINTING RATINGS ////////
    void printRatings() {
        // DISPLAY TO USER SURVEY RESULTS BASED ON EVERYONE'S CHOICES
        cout << "Boss ratings are determined by overall user ratings. \n";
        cout << name << ": \n";
        cout << "Difficulty: " << difficulty << endl;
        cout << "Ugliness: " << ugliness << endl;
        cout << "Beauty: " << beauty << endl;
        cout << "Annoying: " << annoying << endl;
        cout << endl;
    }
};


//////// INTRODUCTION ////////
void introConditional() {
    // Variable for determining if user wants to participate or not
    char userChoice;

    cout << "Welcome! This is a rating survey for Elden Ring bosses. Would you like to participate? Y/N";
    cin >> userChoice;

    // Condition for participating or exiting
    if (userChoice == 'Y')
        bossInstances();
    else 
        exit(1);
    
    cout << "You will be presented with various attributes of bosses in Elden Ring. On a scale of 1 - 10, please rate each boss according to the designated category.\n";
}



// PROMPT USER FOR CHOICE DEPENDING ON SURVEY DETAILS
// STORE SURVEYS
// DISPLAY TO USER SURVEY RESULTS BASED ON EVERYONE'S CHOICES
void promptDisplay(Boss* boss) {
    boss->rateBoss();
    boss->printRatings();
}





//////// MAIN ////////
int main() 
{

    // Introduction
    introConditional();

    return 0;
}


// HOW PROGROM INTERACTS WITH USER //

// PROMPT USER FOR CHOICE OF SURVEY, DIRECT TO SURVEY
void bossInstances() {
    // BOSS OBJECTS
    Boss bosses[2];

    // GODRICK THE GRAFTED OBJECT
    Boss godrickTheGrafted
    (
        "Godrick the Grafted", 
        "Legend(main) Boss", 
        6080, 
        false, 
        true,
        "Standard Damage, Fire Damage"
    );

    // INSERT ABSORPTIONS
    godrickTheGrafted.absorptions.insert(pair<string, int>("Phy (Standard)", 0));
    godrickTheGrafted.absorptions.insert(pair<string, int>("Phy (Slash)", 0));
    godrickTheGrafted.absorptions.insert(pair<string, int>("Phy (Strike)", 0));
    godrickTheGrafted.absorptions.insert(pair<string, int>("Phy (Pierce)", 0));
    godrickTheGrafted.absorptions.insert(pair<string, int>("Magic", 20));
    godrickTheGrafted.absorptions.insert(pair<string, int>("Fire", 20));
    godrickTheGrafted.absorptions.insert(pair<string, int>("Lightning", 20));
    godrickTheGrafted.absorptions.insert(pair<string, int>("Holy", 40));

    // INSERT RESISTANCES
    godrickTheGrafted.resistances.insert(pair<string, int>("Poison", 318));
    godrickTheGrafted.resistances.insert(pair<string, int>("Scarlet Rot", 318));
    godrickTheGrafted.resistances.insert(pair<string, int>("Hemorrhage", 318));
    godrickTheGrafted.resistances.insert(pair<string, int>("Frostbite", 318));
    godrickTheGrafted.resistances.insert(pair<string, int>("Sleep", 318));
    godrickTheGrafted.resistances.insert(pair<string, int>("Madness", 0));
    godrickTheGrafted.resistances.insert(pair<string, int>("DeathBlight", 0));


    // RENNALA QUEEN OF THE FULL MOON
    Boss rennala
    (
        "Rennala Queen of the Full Moon",
        "Legend(main) Boss",
        7590,
        false,
        true,
        "Standard Damage, Magic Damage"
    );

    // INSERT ABSORPTIONS
    rennala.absorptions.insert(pair<string, int>("Phy (Standard)", -10));
    rennala.absorptions.insert(pair<string, int>("Phy (Slash)", -10));
    rennala.absorptions.insert(pair<string, int>("Phy (Strike)", 0));
    rennala.absorptions.insert(pair<string, int>("Phy (Pierce)", -10));
    rennala.absorptions.insert(pair<string, int>("Magic", 80));
    rennala.absorptions.insert(pair<string, int>("Fire", 40));
    rennala.absorptions.insert(pair<string, int>("Lightning", 40));
    rennala.absorptions.insert(pair<string, int>("Phy (Standard)", 40));

     // INSERT RESISTANCES
    rennala.resistances.insert(pair<string, int>("Poison", 318));
    rennala.resistances.insert(pair<string, int>("Poison", 318));
    rennala.resistances.insert(pair<string, int>("Poison", 318));
    rennala.resistances.insert(pair<string, int>("Poison", 318));
    rennala.resistances.insert(pair<string, int>("Poison", 318));
    rennala.resistances.insert(pair<string, int>("Poison", 318));
    rennala.resistances.insert(pair<string, int>("Poison", 318));

    // Rate and Display
    promptDisplay(&godrickTheGrafted);
    promptDisplay(&rennala);
}