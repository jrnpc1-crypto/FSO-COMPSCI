#pragma once
#include "Stats.h"
#include <array>
#include <string>

enum class CharacterRace {
    Dwarf = 1,
    Elf,
    Halfling,
    Human
};

std::string getRaceName(CharacterRace race);
CharacterRace chooseRace();
void applyRaceBonuses(CharacterRace race, std::array<int, ABILITY_COUNT>& scores);