#include "Class.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>

int roll4d6DropLowest(std::mt19937& rng) {
    std::uniform_int_distribution<int> d6(1, 6);
    std::array<int, 4> rolls = { d6(rng), d6(rng), d6(rng), d6(rng) };
    std::sort(rolls.begin(), rolls.end());
    return rolls + rolls + rolls;
}

int getModifier(int score) {
    return (int)std::floor((score - 10) / 2.0);
}

std::string getClassName(CharacterClass cClass) {
    switch (cClass) {
    case CharacterClass::Barbarian: return "Barbarian";
    case CharacterClass::Fighter:   return "Fighter";
    case CharacterClass::Rogue:     return "Rogue";
    case CharacterClass::Wizard:    return "Wizard";
    default:                        return "Adventurer";
    }
}

CharacterClass chooseClass() {
    int choice = 0;

    while (true) {
        std::cout << "\nChoose a Class:\n";
        std::cout << "1. Barbarian (d12 Hit Die)\n";
        std::cout << "2. Fighter   (d10 Hit Die)\n";
        std::cout << "3. Rogue     (d8 Hit Die)\n";
        std::cout << "4. Wizard    (d6 Hit Die)\n";
        std::cout << "Enter choice (1-4): ";

        if (std::cin >> choice && choice >= 1 && choice <= 4) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return (CharacterClass)choice;
        }

        std::cout << "Invalid selection. Please enter a number from 1 to 4.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void applyClassDetails(Character& c) {
    int conMod = getModifier(c.scores[CON]);
    int hitDie = 10;

    switch (c.charClass) {
    case CharacterClass::Barbarian:
        hitDie = 12;
        c.inventory = { "Greataxe", "Handaxe (2)", "Explorer's Pack" };
        break;
    case CharacterClass::Fighter:
        hitDie = 10;
        c.inventory = { "Chain Mail", "Longsword", "Shield", "Dungeoneer's Pack" };
        break;
    case CharacterClass::Rogue:
        hitDie = 8;
        c.inventory = { "Leather Armor", "Rapier", "Shortbow", "Thieves' Tools" };
        break;
    case CharacterClass::Wizard:
        hitDie = 6;
        c.inventory = { "Quarterstaff", "Spellbook", "Component Pouch", "Scholar's Pack" };
        break;
    }

    c.hp = std::max(1, hitDie + conMod);
}

Character createCharacter(const std::string& name, CharacterClass chosenClass, std::mt19937& rng) {
    Character c;
    c.name = name.empty() ? "Adventurer" : name;
    c.charClass = chosenClass;

    for (int i = 0; i < ABILITY_COUNT; ++i) {
        c.scores[i] = roll4d6DropLowest(rng);
    }

    applyClassDetails(c);
    return c;
}

void printSheet(const Character& c) {
    const std::array<std::string, 6> labels = { "STR", "DEX", "CON", "INT", "WIS", "CHA" };
    std::cout << "\n=== " << c.name << " (" << getClassName(c.charClass) << ") ===\n";
    std::cout << "HP: " << c.hp << "\n";

    for (int i = 0; i < ABILITY_COUNT; ++i) {
        int mod = getModifier(c.scores[i]);
        std::cout << labels[i] << ": " << c.scores[i]
            << " (" << (mod >= 0 ? "+" : "") << mod << ")\n";
    }

    std::cout << "Inventory: ";
    int invSize = (int)c.inventory.size();
    for (int i = 0; i < invSize; ++i) {
        std::cout << c.inventory[i] << (i + 1 < invSize ? ", " : "\n");
    }
}