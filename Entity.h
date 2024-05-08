#pragma once
#include <string>

class Entity {
private:
	std::string m_name{};
	int m_maxHP{};
	int m_hp{};
	int m_attack{};
	int m_xp{};
	int m_gold{};
	int m_level{};

public:
	Entity(std::string name = "anonymous", int maxHP = 10, int attack = 2, int xp = 0, int gold = 0, int level = 0)
		: m_name{ name }
		, m_maxHP{ maxHP }
		, m_hp{ maxHP }
		, m_attack{ attack }
		, m_xp{ xp }
		, m_gold{ gold }
		, m_level{ level }
		{};

		int getHP() { return m_hp; };
		int getLevel() { return m_level; }
		bool checkAlive() { return m_hp > 0; }
		std::string& getName() { return m_name; }

};