#pragma once
#ifndef ENCHANTS_H
#define ENCHANTS_H
#include <string>
#include <vector>
#include "rand.h"
using namespace std;
namespace game {
	class Enchant
	{
		// .
	public:
		string name;
		int rarity; // 1 for Common, 2 for Uncommon, 3 for Rare, 4 for Epic, 5 for Legendary.
		// Each Rarity multiplies it by x1 (common), x2.5 (uncommon), x4 (rare), x6 (epic), and x8 (legendary).
		vector<int> stats; // Strength, Magic, HP, PhysResist, Magic Resist, Agility, Luck
	};
	
	class Ultimate : public Enchant {
		bool obtained;

	};

}
#endif