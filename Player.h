#pragma once
#include <string>
#include <vector>
#include "Entity.h"
#include "Item.h"

class Player : public Entity {
private:
	std::string m_name{};
	// current position?
	std::vector<PotionNamespace::Potions> m_inventory{ PotionNamespace::health, PotionNamespace::strength };
	PotionNamespace::Potions m_effect{ PotionNamespace::max_potions };
	bool m_defeatedBoss{};
public:
	Player(std::string name)
		: Entity{ name }
	{};

	bool hasWon() { // or move to game class
		return this->getLevel() >= 10 || this->m_defeatedBoss; // or another condition
	}

	void addToInventory(PotionNamespace::Potions item) { m_inventory.push_back(item); }

	void setAttack(int attack) { m_attack = attack; }

	std::vector<PotionNamespace::Potions> getInventory() {
		return m_inventory;
	}

	void addEffect(PotionNamespace::Potions effect) { m_effect = effect; }

	PotionNamespace::Potions getEffect() { return m_effect; }

	void removeEffect() { m_effect = PotionNamespace::max_potions; }

	void addGold(int gold) { m_gold += gold; }

	void addXP(int XP) { m_xp += XP; this->levelUp(); }

	void levelUp() {
		int newLevel{ m_xp / 100 };
		if (newLevel > m_level) {
			m_level = newLevel;
			std::cout << "You are now level " << m_level << '\n';
			setAttack(m_level * 1.2);
		}
	}

	void removeGold(int gold) { m_gold -= gold; } // or it works with addGold() already when passing negative??

	void setVictory() { m_defeatedBoss = true; }

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