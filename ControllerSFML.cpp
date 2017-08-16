#include "ControllerSFML.h"



ControllerSFML::ControllerSFML()
{
}

ControllerSFML::~ControllerSFML()
{
	delete[] pcMovementArray;
}

void ControllerSFML::initialize()
{
	srand(time(nullptr));
	tileCount = model.getTileCount();
	tileWidth = model.getTileWidth();
	pcMovementArray = new int[tileCount];

	for (int i = 0; i < tileCount; i++) //filling array with numbers
		pcMovementArray[i] = i;

	std::random_shuffle(&pcMovementArray[0], &pcMovementArray[tileCount]); //shuffles array at random
	
	/*for (int i = 0; i < tileCount; i++)
		std::cout << pcMovementArray[i] << " ";*/// prints computers movement pattern 

	gameOver = false;
	model.initialize();
}

void ControllerSFML::play()
{
	while (!gameOver)
	{
		playerTurn = false;
		while (!playerTurn)
		{
			playerMovement(view.getWindow());
			checkWinner(sf::Color::Red);
			view.update();
		}
		Sleep(1000);
		if (!gameOver)
		{
			computerMovement();
			checkWinner(sf::Color::Green);
			view.update();
		}
	}
}

void ControllerSFML::playerMovement(sf::RenderWindow &window)
{
	for (int i = 0; i < (tileCount); i++)
	{
		if (model.getShape(i).getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)
			&& sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && model.getColor(i) == sf::Color::Cyan)
		{
			model.setColor(i, sf::Color::Red);
			playerTurn = true;
		}
	}
}

void ControllerSFML::computerMovement()
{
	for (int i = 0; i < tileCount; i++)
	{
		if (model.getColor(pcMovementArray[i]) == sf::Color::Cyan)
		{
			model.setColor(pcMovementArray[i], sf::Color::Green);
			return;
		}
	}
}

void ControllerSFML::checkWinner(sf::Color color)
{
	if (checkVerticalStreak(color) == color || checkHorizontalStreak(color) == color
		|| checkDiagonalStreak(color) == color || checkDiagonalStreak2(color) == color)
	{
		if (color == sf::Color::Red)
			model.increaseScore('p');
		else
			model.increaseScore('c');

		gameOver = true;
	}
	else
	{
		bool draw = true;
		for (int i = 0; i < tileCount; i++)
		{
			if (model.getShape(i).getFillColor() == sf::Color::Cyan)
				draw = false;
		}
		if (draw)
		{
			model.increaseScore('d');
			gameOver = true;
		}
	}
}

sf::Color ControllerSFML::checkVerticalStreak(sf::Color color)
{
	bool checkTiles;
	for (int i = 0; i < tileWidth;/*vertical*/ i++)
	{
		checkTiles = true;
		for (int j = 0; j < tileWidth;/*horizontal*/ j++)
		{
			if (model.getColor(tileWidth*j + i) != color)
				checkTiles = false;
		}
		if (checkTiles == true)
			return color;
	}
	return sf::Color::White;
}

sf::Color ControllerSFML::checkHorizontalStreak(sf::Color color)
{
	bool checkTiles;
	for (int i = 0; i < tileWidth;/*vertical*/ i++)
	{
		checkTiles = true;
		for (int j = 0; j < tileWidth;/*horizontal*/ j++)
		{
			if (model.getColor(tileWidth*i + j) != color)
				checkTiles = false;
		}
		if (checkTiles == true)
			return color;
	}
	return sf::Color::White;
}

sf::Color ControllerSFML::checkDiagonalStreak(sf::Color color)
{
	bool checkTiles;
	checkTiles = true;
	for (int i = 0; i < tileWidth; i++)
	{
		if (model.getColor(tileWidth*i + i) != color)
			checkTiles = false;
	}
	if (checkTiles == true)
		return color;
	return sf::Color::White;
}

sf::Color ControllerSFML::checkDiagonalStreak2(sf::Color color)
{
	bool checkTiles;
	checkTiles = true;
	for (int i = 1; i <= tileWidth; i++)
	{
		if (model.getColor(tileWidth*i - i) != color)
			checkTiles = false;
	}
	if (checkTiles == true)
		return color;
	return sf::Color::White;
}