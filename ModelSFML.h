#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
 
class ModelSFML
{
	sf::RectangleShape* arr;
	sf::RectangleShape rectangle;
	sf::Font font;
	sf::Text text;
	int boxHeight;
	int boxWidth;
	int boxCoordX;
	int boxCoordY;
	int margin;
	int tileWidth;
	int tileCount;
	int playerScore;
	int computerScore;
	int drawCount;
public:
	ModelSFML();
	~ModelSFML();
	void initialize();
	sf::Text returnText(int x, int y, std::string z, int fontSize);
	void increaseScore(char x);
	int getScore(char x);
	int getTileWidth();
	int getTileCount();
	sf::RectangleShape getShape(int index);
	sf::Color getColor(int index);
	void setColor(int index, sf::Color color);
};

