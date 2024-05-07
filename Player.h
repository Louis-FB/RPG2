#pragma once
#include "Entity.h"
#include <string>
#include <vector>

struct Location {
	int m_x{};
	int m_y{};

	//Location(int x, int y) : m_x{ x }, m_y{ y } {};
};

class Player: public Entity  {
private:
	std::string m_name{};
	Location m_location;
	// current position?

public:
	Player(std::string name)
		: m_name{ name }, m_location({1, 1}), Entity{}
	{};

	void changeLocation(int x, int y) { // Moves across multidimensional array. Logic validated in game.
		m_location.m_x = x;
		m_location.m_y = y;
	};
	
	Location& getLocation() {
		return m_location;
	}

	int getCoordX() {
		return m_location.m_x;
	}

	int getCoordY() {
		return m_location.m_y;
	}
};