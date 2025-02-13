#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Weapon {
private:
    string name;
    int damage;
    vector<string> specialAbilities;

public:
    Weapon(string n, int d, vector<string> abilities)
        : name(n), damage(d), specialAbilities(abilities) {}

    
    friend ostream& operator<<(ostream& os, const Weapon& w) {
        os << "Weapon Name: " << w.name << "\nDamage: " << w.damage
            << "\nSpecial Abilities: ";
        for (const auto& ability : w.specialAbilities) {
            os << ability << " ";
        }
        os << endl;
        return os;
    }

    
    bool operator==(const Weapon& other) const {
        return name == other.name && damage == other.damage && specialAbilities == other.specialAbilities;
    }
};

class Armor {
private:
    string name;
    string description;
    int armorValue;

public:
    Armor(string n, string d, int av)
        : name(n), description(d), armorValue(av) {}

    
    friend ostream& operator<<(ostream& os, const Armor& a) {
        os << "Armor Name: " << a.name << "\nDescription: " << a.description
            << "\nArmor Value: " << a.armorValue << endl;
        return os;
    }

    
    bool operator==(const Armor& other) const {
        return name == other.name && description == other.description && armorValue == other.armorValue;
    }
};

class Character {
private:
    string name;
    string species;
    string backstory;
    int health;
    Weapon weapon;
    Armor armor;

public:
    Character(string n, string s, string b, int h, Weapon w, Armor a)
        : name(n), species(s), backstory(b), health(h), weapon(w), armor(a) {}

   
    void printCharacterInfo() const {
        cout << "Character Name: " << name << endl;
        cout << "Species: " << species << endl;
        cout << "Backstory: " << backstory << endl;
        cout << "Health: " << health << endl;
        cout << "Weapon Info:\n" << weapon;
        cout << "Armor Info:\n" << armor;
    }

    
    bool operator==(const Character& other) const {
        return name == other.name && species == other.species && backstory == other.backstory &&
            health == other.health && weapon == other.weapon && armor == other.armor;
    }
};

int main() {
    cout << "Welcome to the Character Customizer!\n";
    vector<Character> characters;

    
    Weapon sword("Dragonslayer Sword", 100, { "Lions Claw", "Struggler's Slash" });
    Weapon fist("Bare Hands", 80, { "Fist of Flowing Water Crushing Rock", "Gum-Gum Pistol" });
    Armor plateArmor("Berserker Armor", "Heavy armor gifted by the skull knight to fight the apostles", 200); 
    Armor strawHat("Straw Hat", "The symbol of a promise long kept", 50); 

    
    for (int i = 0; i < 3; ++i) {
        cout << "\nCreate character " << i + 1 << ":\n";
        string name, species, backstory;
        int health;

        
        cout << "Enter character name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter species: ";
        getline(cin, species);
        cout << "Enter epic backstory: ";
        getline(cin, backstory);
        cout << "Enter starting health (range 50 to 200): ";
        cin >> health;

        
        cout << "Select a starting weapon:\n1. Dragonlayer Sword\n2. Bare Hands\nEnter choice (1 or 2): ";
        int weaponChoice;
        cin >> weaponChoice;

        Weapon selectedWeapon = (weaponChoice == 1) ? sword : fist;

        
        cout << "Select a starting armor set:\n1. Berserker Armor\n2. Straw Hat\nEnter choice (1 or 2): ";
        int armorChoice;
        cin >> armorChoice;

        Armor selectedArmor = (armorChoice == 1) ? plateArmor : strawHat; 

        
        Character newCharacter(name, species, backstory, health, selectedWeapon, selectedArmor);
        characters.push_back(newCharacter);

        
        cout << "\nCharacter created successfully!\n";
        newCharacter.printCharacterInfo();
    }

    
    cout << "\nDo you want to compare two characters? (y/n): ";
    char compareChoice;
    cin >> compareChoice;

    if (compareChoice == 'y') {
        cout << "Enter the indices of the two characters to compare (1 to 3): ";
        int index1, index2;
        cin >> index1 >> index2;

        if (characters[index1 - 1] == characters[index2 - 1]) {
            cout << "The characters are identical.\n";
        }
        else {
            cout << "The characters are different.\n";
        }
    }

    return 0;
}
