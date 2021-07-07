#pragma once 
#ifndef ENTITY_H
#define ENTITY_H
#include <iostream>
#include <console.h>
#include <vector>
using std::cin;
using std::string;
using namespace cs;
namespace game {



	class Upgrade {
	public:
		int strUp;
		int magUp;
		int intUp;
		int hpUp;
		int physUp;
		int magrUp;
		int dexUp;
		const int luckUp = 3;
	};

	static string enterToContinue;
	class Entity { // base for class entity and player, do not use entity
	public:
		int dex = 0;
		int hp = 0;
		int maxhp = 0;
		string name = "";
		int gold = 0;
		int level = 0;
		double luck = 0;
		int strength = 0;
		int Int = 0;
		int magic = 0; // Int is just mana's var, but Magic is ability damage.

		bool poisoned = 0;
		int poisoned_for = 0;
		bool frozen = 0;
		int frozen_for = 0;
		bool wounded = 0; // Wounds introduce a damage penalty.
	};



	class Player : public Entity {
	public:
		int mana = 0;
		int maxMana = 0;
		int xp = 0;
		int points = 0;
		// Base points which are used to upgrade stats by 1.
		// Not the only way to upgrade stats, though.
		double armor = 0; // % damage reduction.
		double magArmor = 0; // Magic damage resist.
		string type;

		vector<int> heals_inv = { 1, 0, 0, 0, 10, 5, 0 }; // Lesser, Normal, Greater, Rez, Bandage, Antipoison
		/*
		  1: Lesser Healing. 50 restored + 10-25 rand.
		  2: Normal Healing. 120 restored + 10-30 rand.
		  3: Greater Healing. 250 restored + 25-100 rand.
		  4: Revive. Restores half of max hp and all mana.
		  5: Bandage. Used to fix up inflicted Wounds and stop Bleeds.
		  6: Antipoison. Heals from Poison and gives immunity for 3 rounds.
		  7: Full Restore. cs::clears all negative side effects.
		*/
		vector<int> harm_inv = { 0, 0, 0, 0 }; // Poison, Venom, Flashweed, Sap
		/*
		  Poison: Deals scaling damage for 3-6 turns.
		  Venom: Deals higher scaling damage for 5-9 turns.
		  Flashweed: Immediately inflicts Blind on your target.
		  Sap: Drains scaling health from your enemy.
		*/
		vector<int> mana_inv = { 3, 0, 0 };
		/*
		  Mana Restore: 10% of mana restored.
		  High Mana Restore: 25% of mana restored.
		  Grand Mana Restore: 60% of mana restored.
		*/



	};

	class Ally : public Entity {
		int mana = 0;
		int maxMana = 0;
		int xp = 0;
		int armor = 0;
		int magArmor = 0;
		string type; // Class but i'm not allowed to use class like that.

	};

	class Enemy : public Entity {
	public:
		int spareHp = 0;
		double xpMult = 0;
		bool trued = false; // If true, 5% of all damage will ignore all damage resist.
		// Will implement custom enemy attacks soon. For now, it'll just choose between magic/physical damage.
		int defense = 0;
	};

	class boss : public Entity {
	public:
		double trued = 0; // Percent of damage which ignores damage resist.
		int heals = 0; // Amount of heals given to the boss. Max possible is 3 for 150 damage healed.
		int armor = 0;
		int magArmor = 0;
		int mana = 0;
		int maxmana = 0;
		int levels = 0;
	};


	static Player player;
	inline bool checkResist() {
		if (player.armor > .8) {
			player.armor = .8;
			return true;
		}
		if (player.magArmor > .8) {
			player.magArmor = .8;
			return true;
		}
		else {
			return false;
		}
	}
	inline void defEntity() {

	}
	static inline void Upgrade() {
		static class Upgrade fighter;
		static class Upgrade barbarian;
		static class Upgrade paladin;
		static class Upgrade wizard;
		static class Upgrade cleric;
		static class Upgrade druid;
		fighter.strUp = 1; fighter.magUp = 2; fighter.intUp = 2; fighter.hpUp = 1; fighter.physUp = 1; fighter.magrUp = 2; fighter.dexUp = 1;
		barbarian.strUp = 1; barbarian.magUp = 3; barbarian.intUp = 3; barbarian.hpUp = 1; barbarian.physUp = 2; barbarian.magrUp = 2; barbarian.dexUp = 2;
		paladin.strUp = 1; paladin.magUp = 1; paladin.intUp = 1; paladin.hpUp = 2; paladin.physUp = 1; paladin.magrUp = 1; paladin.dexUp = 3;
		wizard.strUp = 2; wizard.magUp = 1; wizard.intUp = 1; wizard.hpUp = 1; wizard.physUp = 2; wizard.magrUp = 1; wizard.dexUp = 2;
		cleric.strUp = 3; cleric.magUp = 2; cleric.magUp = 1; cleric.hpUp = 1; cleric.physUp = 1; cleric.magrUp = 1; cleric.dexUp = 2;
		druid.strUp = 2; druid.magUp = 1; druid.intUp = 1; druid.hpUp = 2; druid.physUp = 1; druid.magrUp = 2; druid.dexUp = 1;

		static class Upgrade& refer = paladin;
		if (player.points < 0) {
			std::cout << "You don't have enough points to upgrade anything. Come back once you've obtained points.";
		}
		else {
			while (player.points > 0) {
				if (player.type == "Fighter") {
					static class Upgrade refer = fighter;
				}
				else if (player.type == "Barbarian") {
					static class Upgrade refer = barbarian;
				}
				else if (player.type == "Paladin") {
					static class Upgrade refer = paladin;
				}
				else if (player.type == "Wizard") {
					static class Upgrade& refer = wizard;
				}
				else if (player.type == "Cleric") {
					static class Upgrade& refer = cleric;
				}
				else if (player.type == "Druid") {
					static class Upgrade& refer = cleric;
				}
				else {
					exit(15000);
				}
				std::cout << "Which stat will be upgraded?" << endl << "You have " << player.points << " points." << endl << endl
					<< "1. +5 Max Health | Cost: " << refer.hpUp << endl
					<< "2. +1 Strength | Cost: " << refer.strUp << endl
					<< "3. +1 Magic | Cost: " << refer.magUp << endl
					<< "4. +5 Intelligence | Cost: " << refer.intUp << endl
					<< "5. +1 Physical Resist | Cost: " << refer.physUp << endl
					<< "6. +1 Magical Resist | Cost: " << refer.magrUp << endl
					<< "7. +1 Dexterity | Cost: " << refer.dexUp << endl
					<< "8. +1 Luck | Cost:" << refer.luckUp << endl
					<< endl

					<< "9. Exit" << endl;
				string choice;
				std::getline(cin, choice);
				int bruh = stoi(choice);
				switch (bruh) {
				case 1:
					std::cout << endl << endl;
					player.maxhp = player.maxhp + 5;
					std::cout << "You gained 5 Max Health!" << endl;

					player.points = player.points - refer.hpUp;
					cout << "Press Enter to continue" << endl; getline(cin, enterToContinue);
					break;
				case 2:
					std::cout << endl << endl;
					player.strength = player.strength + 1;
					std::cout << "You gained 1 Strength!" << endl;
					player.points = player.points - refer.strUp;
					cout << "Press Enter to continue" << endl; getline(cin, enterToContinue);
					break;
				case 3:
					std::cout << endl << endl;
					player.magic = player.magic + 1;
					std::cout << "You gained 1 Magic!" << endl;
					player.points = player.points - refer.magUp;
					cout << "Press Enter to continue" << endl; getline(cin, enterToContinue);
					break;
				case 4:
					std::cout << endl << endl;
					player.Int = player.Int + 5;
					std::cout << "You gained 5 Intelligence!" << endl;
					player.points = player.points - refer.intUp;
					cout << "Press Enter to continue" << endl; getline(cin, enterToContinue);
					break;
				case 5:
					std::cout << endl << endl;
					player.armor = player.armor + .01;
					std::cout << "You gained 1 Physical Resist!" << endl;
					player.points = player.points - refer.physUp;
					cout << "Press Enter to continue" << endl; getline(cin, enterToContinue);
					break;
				case 6:
					std::cout << endl << endl;
					player.magArmor = player.magArmor + .01;
					std::cout << "You gained 1 Magical Resist!" << endl;
					player.points = player.points - refer.magrUp;
					cout << "Press Enter to continue" << endl; getline(cin, enterToContinue);
					break;
				case 7:
					std::cout << endl << endl;
					player.dex = player.dex + 5;
					std::cout << "You gained 1 Dexterity!" << endl;
					player.points = player.points - refer.dexUp;
					cout << "Press Enter to continue" << endl; getline(cin, enterToContinue);
					break;
				case 8:
					std::cout << endl << endl;
					player.luck = player.luck + 5;
					std::cout << "You gained 1 Luck!" << endl;
					player.points = player.points - refer.luckUp;
					cout << "Press Enter to continue" << endl; getline(cin, enterToContinue);
					break;
				case 9:
					break;
				}


			}
			if (player.points == 0) {
				cout << "You have run out of points.";
			}
		}
	}
	static string idk;
	inline void createPlayer()
	{

		player.hp = 100;
		player.maxhp = 100;
		player.gold = 50;
		player.level = 1;
		player.luck = 5;
		player.strength = 5;
		player.Int = 5;
		player.armor = 0;
		player.magArmor = 0;
		player.points = 0;
		std::cout << "What is your name?" << endl << "> ";

		std::getline(cin, player.name);
		sleep(800);
		std::cout << endl
			<< player.name << ". Is that correct?";
		bool nameCorrect = false;
		while (nameCorrect == false)
		{
			std::cout << endl;
			std::cout << "Yes or No (Y/N) " << endl
				<< "> ";
			char yn = getchar();
			if (yn == 'y') {
				std::cout << "Perfect. Let us continue." << endl;
				nameCorrect = true;
				sleep(1500);
			}
			else if (yn == 'Y') {
				std::cout << "Perfect. Let us continue." << endl;
				nameCorrect = true;
				sleep(1500);
			}
			else {
				cs::clear();
			}

		}
		cs::clear();
		std::cout << "Pick a class."
			<< endl << endl
			<< "1: Fighter" << endl
			<< "2: Barbarian" << endl
			<< "3: Paladin" << endl
			<< "4: Wizard" << endl
			<< "5: Cleric" << endl
			<< "6: Druid" << endl;

		cout << endl << "To learn about each class, use L." << endl
			<< "To select, use S." << endl;
		string classinfo;
		std::cin >> classinfo;
		std::cout << endl;
		bool done = true;
		if (classinfo != "S") {
			while (done) {
				clear();
				cout << "Learn about which class?" << endl << endl
					<< "1: Fighter" << endl
					<< "2: Barbarian" << endl
					<< "3: Paladin" << endl
					<< "4: Wizard" << endl
					<< "5: Cleric" << endl
					<< "6: Druid" << endl
					<< "Enter 7 to exit and select." << endl;

				cout << endl;
				cin >> classinfo;
				if (classinfo == "1") {
					std::cout << endl
						<< "Fighters are melee-focused warriors capable of dealing high melee damage." << endl
						<< "Base stats: +25 Strength, +6 Physical Resist, +1 Magical Resist, +10 Luck, +5 Health";
					cout << endl;

					cout << "Press Enter to continue." << endl; getline(cin, enterToContinue);
					
				}
				else if (classinfo == "2") {
					std::cout << endl
						<< "Barbarians are extremely strong, but cannot tank magic damage or use magic."
						<< endl
						<< "Base stats: +40 Strength, +10 Physical Resist, -6 Magical Resist, +4 Luck, +7 Health" << endl;

					cout << "Press Enter to continue." << endl; getline(cin, enterToContinue);
				}
				else if (classinfo == "3") {
					std::cout << endl
						<< "Paladins are a mix between melee and magic, but are more of a supporting role." << endl
						<< "Base stats: +15 Strength, +20 Intelligence, +4 Physical Resist, +5 Magical Resist, +10 Health"
					<< endl;

					cout << "Press Enter to continue." << endl; getline(cin, enterToContinue);
				}
				else if (classinfo == "4") {
					std::cout << endl
						<< "Wizards are your generic spellcasters, and can fill any role."
						<< "Base stats: +30 Intelligence, +5 Magic, -1 Physical Resist, +10 Magical Resist" << endl;

					std::cout << "Press Enter to continue." << endl;
					cout << "Press Enter to continue" << endl; getline(cin, enterToContinue);
				}
				else if (classinfo == "5") {

					std::cout << endl
						<< "Clerics are pure support characters, and can't deal much damage." << endl
						<< "However, their later abilities will be essential in battle."
						<< endl
						<< "Base stats: +18 Intelligence, +2 Magic, +10 Health, +5 Dexterity" << endl;

					std::cout << "Press Enter to continue." << endl;
					cout << "Press Enter to continue" << endl; getline(cin, enterToContinue);
				}
				else if (classinfo == "6") {
					std::cout << endl
						<< "Druids are offensive casters, using magic and nature to eliminate enemies." << endl
						<< "Base stats: +18 Intelligence, +4 Magic, +25 Health, +10 Magical Resist";

					std::cout << "Press Enter to continue." << endl;
					cout << "Press Enter to continue" << endl; getline(cin, enterToContinue);
				}
				else if (classinfo == "7") {
					std::cout << endl;
					done = false;
				}
			}
		}
		else {
			std::cout << endl << endl
				<< "Which one will you pick?" << endl << "> ";
			string hello;

			std::getline(cin, hello);
			if (hello == "1") {
				std::cout << endl
					<< "You are now a Fighter." << endl;
				player.type = "Fighter";
				player.strength = player.strength + 25;
				player.armor = player.armor + 6;
				player.magArmor = player.magArmor + 1;
				player.luck = player.luck + 10;
				player.hp = player.hp + 10;

			}
			else if (hello == "2") {
				std::cout << endl
					<< "You are now a Barbarian." << endl;
				player.type = "Barbarian";
				player.strength = player.strength + 40;
				player.armor = player.armor + 10;
				player.magArmor = player.magArmor - 6;
				player.luck = player.luck + 4;
				player.hp = player.hp + 7; player.maxhp = player.hp;

			}
			else if (hello == "3") {
				std::cout << endl
					<< "You are now a Paladin." << endl;
				player.type = "Paladin";
				player.strength = player.strength + 15;
				player.Int = player.Int + 20;
				player.armor = player.armor + 4;
				player.magArmor = player.magArmor + 5;
				player.hp = player.hp + 10; player.maxhp = player.hp;

			}
			else if (hello == "4") {
				std::cout << endl
					<< "You are now a Wizard." << endl;
				player.type = "Wizard";
				player.Int = player.Int + 30;
				player.magic = player.magic + 5;
				player.armor = player.armor - 1;
				player.magArmor = player.magArmor + 10;

			}
			else if (hello == "5") {
				std::cout << endl
					<< "You are now a Cleric." << endl;
				player.type = "Cleric";
				player.Int = player.Int + 18;
				player.magic = player.magic + 2;
				player.hp = player.hp + 10; player.maxhp = player.hp;
				player.dex = player.dex + 5;

			}
			else if (hello == "6") {
				std::cout << endl
					<< "You are now a Druid." << endl;
				player.type = "Druid";
				player.Int = player.Int + 18;
				player.magic = player.magic + 4;
				player.hp = player.hp + 25;
				player.magArmor + player.magArmor + 10;
			}
		}



			std::cout << endl << endl << endl;
			std::cout << "Press Enter to continue." << endl;
			std::getline(cin, idk);

			cs::clear();
			Sleep(1000);
			std::cout << "Now, please upgrade your base stats." << endl
				<< "You have been gifted with 20 Character Points." << endl
				<< "Use them wisely, as it will cost you to reset them." << endl
				<< endl << endl;
			player.points = 20;
			std::cout << "Press Enter to continue.";
			std::getline(cin, idk);
			cs::clear();
			Upgrade();
			if (player.points > 0) {
				std::cout << "You have " << player.points << " remaining points." << endl
					<< "Are you sure you want to continue?" << endl << "(Y/N) > ";
				string bruh;
				std::getline(cin, bruh);
				string f = upper(bruh);
				if (f == "Y") {
					Upgrade();
				}
				else {
					std::cout << "Very well, then." << endl;
				}
			}
			Sleep(5000);
			cs::clear();
			std::cout << "You're ready to begin your adventure.";
			std::cout << "Press Enter to begin.";
		}

	}

#endif