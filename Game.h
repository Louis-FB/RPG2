#pragma once

struct Location {
	int m_y{};
	int m_x{};
};

class Game {
private:
	int m_round{0};
	Location m_playerLocation;
	// map?
	// defeated monsters
	// Location array of location history
public:
	Game() : m_playerLocation({ 5, 5 }) {};

	/*Location& getLocation() {
		return m_playerLocation;
	}*/

	int getRounds() { return m_round; }

	void incrementRounds() { ++m_round; }

	int getCoordY() { return m_playerLocation.m_y; }

	int getCoordX() { return m_playerLocation.m_x; }
	
	void changeLocation(int y, int x) { 
		m_playerLocation.m_y = y;
		m_playerLocation.m_x = x;
	};
};