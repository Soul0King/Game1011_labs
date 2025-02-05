#include <iostream>
#include <string>


struct Weapon {
    float damage = 0.0f;
    const char* names[3] 
        = { "Sword", "Gun", "Fists" };
    const char* specials[3]
        = { "Thousand Moon Slash", "Dodge this", "Fist of Flowing Water Crushing Rock" };
};

struct Armour {
    float armourValue = 0.0f;
    const char* names[3] 
        = { "Chain Armour", "Iron Armour", "Leather Armour" };
    const char* armourDescription[3]
        = {"Medium Armour. Good against slashing attacks", "Heavy Armour. Good against blunt attacks as well as slashes", "Light armour. Might soften a blow but good for running"};

};

struct Character {
    Weapon* weapons = nullptr;
    Armour* armours = nullptr;
    float health = 0.0f;
    std::string name;
    std::string species;
    std::string backstory;

};


//bool operator==(Armour armourValue, ) {
//
//}


int main()
{
    int characterCount = 0;
    printf("Enter the number of characters. maximum of 3.\n");
    std::cin >> characterCount;
    std::cin.ignore();
    printf("You will make %i characters.\n", characterCount);

    Character* characters = new Character[characterCount];
    for (int i = 0; i < characterCount; i++) {
        Character& character = characters[i];
    }
}

