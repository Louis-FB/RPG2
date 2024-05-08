#pragma once

#include "Entity.h"
#include <string>
#include <array>
#include <cassert>

namespace MonsterNamespace {
	// generate function
	enum Monsters {
		ogre,
		dragon,
		centaur,
		goblin,
		max_monsters
	};

	std::array<std::string, max_monsters> names{"ogre", "dragon", "centaur", "goblin"};
	std::array<int, max_monsters> HP{ 10, 20, 30, 20 };
	std::array<int, max_monsters> attack{ 10, 20, 30, 10 };
	std::array<int, max_monsters> XP{ 10, 20, 30, 10 };
	std::array<int, max_monsters> gold{ 10, 20, 30, 10 };
	std::array<int, max_monsters> level{ 1, 2, 3, 4 };

	Entity getRandomMonster() {
		// random number generator that maps to enum

		return Entity{names[goblin], HP[goblin], attack[goblin], XP[goblin], gold[goblin], 1};
	}
}


class Monster: public Entity {
	
public:
	// Monster(randomNumber/enum) : Entity{} {HP[enum], attack[enum]}
	Monster() : Entity{ MonsterNamespace::getRandomMonster() } {}
};