#include "Race.h"
#include <iostream>
#include <limits>

std::string getRaceName(CharacterRace race) {
    switch (race) {
    case CharacterRace::Dwarf:    return "Dwarf";
    case CharacterRace::Elf:      return "Elf";
    case CharacterRace::Halfling: return "Halfling";
    case CharacterRace::Human:    return "Human";
    default:                      return "Unknown";
    }
}

CharacterRace chooseRace() {
    int choice = 0;

    while (true) {
        std::cout << "\nChoose a Race:\n";
        std::cout << "1. Dwarf    (+2 CON, +1 WIS)\n";
        std::cout << "2. Elf      (+2 DEX, +1 INT)\n";
        std::cout << "3. Halfling (+2 DEX, +1 CHA)\n";
        std::cout << "4. Human    (+1 to all stats)\n";
        std::cout << "Enter choice (1-4): ";

        if (std::cin >> choice && choice >= 1 && choice <= 4) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return (CharacterRace)choice;
        }

        std::cout << "Invalid selection. Please enter a number from 1 to 4.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void applyRaceBonuses(CharacterRace race, std::array<int, ABILITY_COUNT>& scores) {
    switch (race) {
    case CharacterRace::Dwarf:
        scores[CON] += 2;
        scores[WIS] += 1;
        break;
    case CharacterRace::Elf:
        scores[DEX] += 2;
        scores[INT] += 1;
        break;
    case CharacterRace::Halfling:
        scores[DEX] += 2;
        scores[CHA] += 1;
        break;
    case CharacterRace::Human:
        for (int i = 0; i < ABILITY_COUNT; ++i) {
            scores[i] += 1;
        }
        break;
    }
}