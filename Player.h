#pragma once
#include <string>
#include <vector>
#include "Entity.h"
#include "Item.h"

class Player: public Entity  {
private:
	std::string m_name{};
	// current position?
	std::vector<PotionNamespace::Potions> m_inventory{PotionNamespace::health, PotionNamespace::strength};
	PotionNamespace::Potions m_effect{PotionNamespace::max_potions};
public:
	Player(std::string name)
		: Entity{name}
	{};

	bool hasWon() { // or move to game class
		return this->getLevel() >= 10; // or another condition
	}

	void addToInventory(PotionNamespace::Potions item) { m_inventory.push_back(item); }

	std::vector<PotionNamespace::Potions> getInventory() {
		return m_inventory;
	}

	void addEffect(PotionNamespace::Potions effect) { m_effect = effect; }

	PotionNamespace::Potions getEffect() { return m_effect; }

	void removeEffect() { m_effect = PotionNamespace::max_potions; }
	
	void addGold(int gold) { m_gold += gold; }

	void addXP(int XP) { m_xp += XP; }

	void removeGold(int gold) { m_gold -= gold; } // or it works with addGold() already when passing negative??

	/*
	void changeLocation(int y, int x) { // Moves across multidimensional array. Logic validated in game.
		m_location.m_y = y;
		m_location.m_x = x;
	};
	
	Location& getLocation() {
		return m_location;
	}

	int getCoordY() {
		return m_location.m_y;
	}

	int getCoordX() {
		return m_location.m_x;
	}
	*/
	

};