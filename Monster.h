#pragma once

#include "Entity.h"
#include <string>
#include <array>
#include <cassert>
#include "Random.h"

namespace MonsterNamespace {
	// generate function
	enum Monsters {
		ogre,
		centaur,
		goblin,
		peasant,
		dragon, // boss (not within scope of random function)
		max_monsters
	};

	std::array<std::string, max_monsters> names{"ogre", "centaur", "goblin", "peasant", "dragon" };
	std::array<int, max_monsters> HP{ 10, 20, 30, 3, 4 };
	std::array<int, max_monsters> damage{ 10, 20, 1, 5 };
	std::array<int, max_monsters> XP{ 10, 20, 30, 10, 10 };
	std::array<int, max_monsters> gold{ 10, 20, 30, 10, 6 };
	std::array<int, max_monsters> level{ 1, 2, 3, 4, 1 };
	std::array<std::string, max_monsters> sound{"ooga", "neigh", "hehe", "roar", "aahh"};

	/*
	Entity getRandomMonster() { // remove or modify
		// random number generator that maps to enum
		Monsters testName = goblin;

		return Entity{names[testName], HP[testName], attack[testName], XP[testName], gold[testName], 1};
	}
	*/
	

	Monsters getRandomMonster() { // change to be randomised // accept boss or mob as parameter?? (or make it manual)
		return static_cast<Monsters>(Random::get(0, max_monsters - 1));
	}
}

using namespace MonsterNamespace;

class Monster: public Entity {
private:
	std::string m_sound{};
	bool m_boss{};
public:

	// Monster(randomNumber/enum) : Entity{} {HP[enum], attack[enum]}
	Monster(Monsters monster) 
		: m_boss{monster == dragon ? true : false}
		, m_sound{sound[monster]}
		, Entity{ names[monster]
		, HP[monster]
		, damage[monster]
		, XP[monster]
		, gold[monster]
		, level[monster]} 
	{} // input array stuff here
	bool isBoss() { return m_boss; }
};