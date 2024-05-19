#pragma once
#include "Monster.h"
#include <vector>

struct Location {
	int m_y{};
	int m_x{};

public:
	friend bool operator== (const Location& l1, const Location& l2);
};

bool operator==(const Location& l1, const Location& l2) {
	return (l1.m_x == l2.m_x && l1.m_y == l2.m_y);
}

struct MonsterInfo {
	int m_id{};
	Location m_location{};
	Monster m_monster;

	MonsterInfo(int id, Location location, Monster monster) : m_id{ id }, m_location{ location }, m_monster{ monster } {};
	Location getLocation() { return m_location; }
	Monster getMonster() { return m_monster; }
	int getID() { return m_id; }
	void updateMonster(Monster& m) { m_monster = m; }
};

std::vector<MonsterInfo> monsterHistory{};

class Game {
private:
	int m_round{0};
	Location m_playerLocation;
	// map?
	// defeated monsters
	// Location array of location history
public:
	Game() : m_playerLocation({ 5, 5 }) {};

	Location getLocation() {
		return m_playerLocation;
	}

	int getRounds() { return m_round; }

	void incrementRounds() { ++m_round; }

	int getCoordY() { return m_playerLocation.m_y; }

	int getCoordX() { return m_playerLocation.m_x; }
	
	void changeLocation(int y, int x) { 
		m_playerLocation.m_y = y;
		m_playerLocation.m_x = x;
	};
};