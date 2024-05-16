#pragma once
#include <array>
#include <string>

namespace PotionNamespace {
	enum Potions {
		health,
		invisibility,
		strength,
		max_potions
	};

	std::array<std::string, Potions::max_potions> potionName{ "health potion", "invisibility potion", "strength potion" };
	std::array<int, Potions::max_potions> potionCost{ 2, 20, 30 };

}