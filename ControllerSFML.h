#pragma once
#include "ModelSFML.h"
#include "ViewSFML.h"
#include <Windows.h> //Sleep()

extern ModelSFML model;

class ControllerSFML
{
	ViewSFML view;
	bool gameOver;
	bool playerTurn;
	int* pcMovementArray;
	int tileCount;
	int tileWidth;
public:
	ControllerSFML();
	~ControllerSFML();
	void initialize();
	void play();
	void playerMovement(sf::RenderWindow &window);
	void computerMovement();
	void checkWinner(sf::Color color);
	sf::Color checkVerticalStreak(sf::Color color);
	sf::Color checkHorizontalStreak(sf::Color color);
	sf::Color checkDiagonalStreak(sf::Color color);
	sf::Color checkDiagonalStreak2(sf::Color color);
};

