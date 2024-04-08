#pragma once

class Entity {
private:
	int m_maxHP{};
	int m_hp{};
	int m_attack{};
	int m_xp{};

public:
	Entity(int maxHP, int attack, int xp) 
		: m_maxHP{ maxHP }
		, m_hp{ maxHP }
		, m_attack{ attack }
		, m_xp{ xp } {};
};