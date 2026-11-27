// DnD-Build.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Class.h"
#include <iostream>
#include <random>
#include <string>

int main() {
    std::random_device rd;
    std::mt19937 rng(rd());

    std::string name;
    std::cout << "Enter character name: ";
    std::getline(std::cin, name);

    CharacterClass selectedClass = chooseClass();
    Character hero = createCharacter(name, selectedClass, rng);

    printSheet(hero);
    return 0;
}