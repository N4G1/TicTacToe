#pragma once
#include "ModelSFML.h"

class ViewSFML
{
	sf::RenderWindow window;
	int tileCount;
public:
	ViewSFML();
	~ViewSFML();
	sf::RenderWindow &getWindow();
	void update();
};

