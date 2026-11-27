#pragma once
#include <array>
#include <random>
#include <string>
#include <vector>

enum Ability { STR = 0, DEX, CON, INT, WIS, CHA, ABILITY_COUNT };

enum class CharacterClass {
    Barbarian = 1,
    Fighter,
    Rogue,
    Wizard
};

struct Character {
    std::string name;
    CharacterClass charClass = CharacterClass::Fighter;
    std::array<int, ABILITY_COUNT> scores{};
    int hp = 10;
    std::vector<std::string> inventory;
};

int roll4d6DropLowest(std::mt19937& rng);
int getModifier(int score);
std::string getClassName(CharacterClass cClass);
CharacterClass chooseClass();
void applyClassDetails(Character& c);
Character createCharacter(const std::string& name, CharacterClass chosenClass, std::mt19937& rng);
void printSheet(const Character& c);