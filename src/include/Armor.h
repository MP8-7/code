#pragma once
#ifndef ARMOR_H
#define ARMOR_H
#include <string>
#include <Entity.h>
#include <vector>
using std::vector;
using std::string;
namespace game {

	class Armor {
	public:
		string name;
		int hp;
		string prefix;
		int defense;
		int magicdefense;
		int strength;
		int magic;
		int luck;
		int dex;
		// Both of these will add to armor and magic resist of the player.
		string element;
		double fire_resist; // Resistance to fire, as it deals true damage.
		// Frost armor gains automatic 70% resist.
		vector<int> boost;

		void apply_enchant(Armor &current) {
			current.strength = current.strength + current.boost[1];
			current.magic = current.magic + current.boost[2];
			current.hp = current.hp + current.boost[3];
			current.defense = current.defense + current.boost[4];
			current.magicdefense = current.magicdefense + current.boost[5];
			current.dex = current.dex + current.boost[6];
			current.luck = current.luck + current.boost[7];
			
		}
	};
}

#endif
