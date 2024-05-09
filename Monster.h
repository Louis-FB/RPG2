#pragma once

#include "Entity.h"
#include <string>
#include <array>
#include <cassert>

namespace MonsterNamespace {
	// generate function
	enum Monsters {
		ogre,
		centaur,
		goblin,
		dragon, // boss (not within scope of random function)
		max_monsters
	};

	std::array<std::string, max_monsters> names{"ogre", "centaur", "goblin", "dragon"};
	std::array<int, max_monsters> HP{ 10, 20, 30, 60 };
	std::array<int, max_monsters> attack{ 10, 20, 30, 50 };
	std::array<int, max_monsters> XP{ 10, 20, 30, 10 };
	std::array<int, max_monsters> gold{ 10, 20, 30, 10 };
	std::array<int, max_monsters> level{ 1, 2, 3, 4 };
	std::array<std::string, max_monsters> sound{"ooga", "neigh", "hehe", "roar"};

	/*
	Entity getRandomMonster() { // remove or modify
		// random number generator that maps to enum
		Monsters testName = goblin;

		return Entity{names[testName], HP[testName], attack[testName], XP[testName], gold[testName], 1};
	}
	*/
	

	Monsters getRandomMonster() { // change to be randomised // accept boss or mob as parameter?? (or make it manual)
		return dragon;
	}
}

using namespace MonsterNamespace;

class Monster: public Entity {
private:
	std::string m_sound{};
public:

	// Monster(randomNumber/enum) : Entity{} {HP[enum], attack[enum]}
	Monster(Monsters monster) 
		: m_sound{sound[monster]}
		, Entity{ names[monster]
		, HP[monster]
		, attack[monster]
		, XP[monster]
		, gold[monster]
		, level[monster]} 
	{} // input array stuff here
};