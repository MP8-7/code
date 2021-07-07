#include <Enchants.h>
using namespace game;

namespace game {
	inline void defEnchants() {
		// Strength, Magic, HP, PhysResist, Magic Resist, Agility, Luck
		Enchant strong, wise, large, reinforced, blessed, agile, lucky, heroic;
		strong.name = "Strong"; strong.stats = { 3, 0, 1, 2, 1, 0, 2 };
		wise.name = "Wise"; wise.stats = { 0, 3, 2, 1, 3, 1, 0 };
		large.name = "Large"; large.stats = { 0, 0, 4, 2, 2, 0, 2 };
		reinforced.name = "Reinforced"; reinforced.stats = { 1, 1, 2, 5, 2, 1, 2 };
		blessed.name = "Blessed"; blessed.stats = { 1, 1, 1, 2, 5, 2, 1, 2 };
		agile.name = "Agile"; agile.stats = { 2, 1, 3, 1, 2, 5, 1 };
		lucky.name = "Lucky"; lucky.stats = { 1, 1, 1, 1, 1, 1, 6};
		heroic.name = "Heroic"; heroic.stats = { 2, 2, 2, 2, 2, 2, 2 };

		Ultimate war, mage;
		war.name = "Warrior's Brand"; war.stats = { 10, 6, 6, 6, 6, 6, 6 };
		mage.name = "Mage's Brand"; mage.stats = { 6, 10, 6, 6, 6, 6, 6 };
	}
}
