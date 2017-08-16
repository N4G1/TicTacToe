#include "ViewSFML.h"
ModelSFML model;


ViewSFML::ViewSFML()
{
	window.create(sf::VideoMode(600, 600),"Tic-Tac-Toe"); //creating window
	window.setFramerateLimit(60); //caping framerate at 60
	tileCount = model.getTileCount();
}

ViewSFML::~ViewSFML()
{
}

sf::RenderWindow &ViewSFML::getWindow()
{
	return window;
}

void ViewSFML::update()
{
	if (window.isOpen())
	{
		sf::Event event;
		if (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		for (int i = 0; i < (tileCount); i++)
			window.draw(model.getShape(i));
		
		window.draw(model.returnText(model.getTileWidth()*50 + 200, 150, "Player Score: " + std::to_string(model.getScore('p')), 20));
		window.draw(model.returnText(model.getTileWidth() * 50 + 200, 180, "Computer Score: " + std::to_string(model.getScore('c')), 20));
		window.draw(model.returnText(model.getTileWidth() * 50 + 200, 210, "Draw Count: " + std::to_string(model.getScore('d')), 20));
		window.display();
	}
}