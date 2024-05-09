#pragma once
#include "Entity.h"
#include <string>
#include <vector>

class Player: public Entity  {
private:
	std::string m_name{};
	// current position?

public:
	Player(std::string name)
		: Entity{name}
	{};

	bool hasWon() { // or move to game class
		return this->getLevel() >= 10; // or another condition
	}

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