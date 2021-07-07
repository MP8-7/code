#pragma once
#ifndef MAGIC_H
#define MAGIC_H
#include <string>
using std::string;

namespace game {
    class magic {
    public:
        string name;
        string spellbook;
        string spellbook_name;
        int manacost;
        string targets; // Self, allies, fullteam, or enemies.
        // Only two things that all spells will have.
    };
    class standard : public magic { // Default spellbook. Generally weaker than later options.
    public:
        int mindmg;
        int maxdmg;
        int healing;
        bool lifesteal; // If true, 15% of damage dealt will go to heal user.
        double freeze; // Chance to freeze attacker.

    };

    class frost : public magic {
    public:
        int mindmg;
        int maxdmg;
        double freeze;
        bool trued; // Damage which ignores all damage resist if true.
    };

    class fire : public magic {
    public:
        int mindmg;
        int maxdmg;
        double burn;
        // Fire spells inflict Fire damage, which is similar to True damage but
        // can be resisted with Frost armor or special enchantments.
    };

    class poison : public magic {
    public:
        int mindmg;
        int maxdmg;
        double poison; // Chance to inflict Poisoned.
        bool trued;
    };
    class support : public magic {
        int healing;
        bool endpoison;
        bool endbleed;
        bool endfreeze;
        bool healwound;
        bool healburn;
        bool revive;
    };
}
#endif
