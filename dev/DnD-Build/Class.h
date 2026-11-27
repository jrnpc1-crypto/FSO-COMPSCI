#pragma once
#include "Race.h"
#include "Stats.h"
#include <array>
#include <random>
#include <string>
#include <vector>

enum class CharacterClass {
    Barbarian = 1,
    Fighter,
    Rogue,
    Wizard
};

struct Character {
    std::string name;
    CharacterRace race = CharacterRace::Human;
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
Character createCharacter(const std::string& name, CharacterRace chosenRace, CharacterClass chosenClass, std::mt19937& rng);
void printSheet(const Character& c);