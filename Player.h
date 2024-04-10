#pragma once
#include "Entity.h"
#include <string>
#include <vector>

class Player: public Entity  {
private:
	std::string m_name{};

public:
	Player(std::string name)
		: m_name{ name }, Entity{}
	{};
};