#include "ModelSFML.h"


ModelSFML::ModelSFML()
{
	tileWidth = 3;
	playerScore = 0;
	computerScore = 0;
	drawCount = 0;
	tileCount = tileWidth*tileWidth;
	arr = new sf::RectangleShape[tileCount];
}

ModelSFML::~ModelSFML()
{
	delete[] arr;
}

void ModelSFML::initialize()
{
	boxCoordX = 0;
	boxCoordY = 50;
	boxHeight = 50;
	boxWidth = 50;
	margin = 10;

	for (int i = 0; i < (tileCount); i++)
	{
		arr[i] = rectangle;
		arr[i].setSize(sf::Vector2f(boxWidth, boxHeight));
		arr[i].setFillColor(sf::Color::Cyan);
		arr[i].setPosition(sf::Vector2f(i % tileWidth == 0 ? boxCoordX = 150 : boxCoordX += boxWidth + margin
			, i % tileWidth == 0 ? boxCoordY += boxHeight + margin : boxCoordY ));		//optimised for any size you want
	}
	
	if (!font.loadFromFile("T:\\Code\\TicTacToe\\Fonts\\neon.ttf"))
		std::cout << "Error loading font\n";
	
	text.setFont(font);
	text.setFillColor(sf::Color::White);
}

sf::Text ModelSFML::returnText(int x, int y, std::string z, int fontSize)
{
	text.setCharacterSize(fontSize);
	text.setPosition(x, y);
	text.setString(z);
	return text;
}

void ModelSFML::increaseScore(char x)
{
	switch (x)
	{
		case 'p': playerScore++; break;
		case 'c': computerScore++; break;
		case 'd': drawCount++; break;
	}
}

int ModelSFML::getScore(char x)
{
	switch (x)
	{
		case 'p': return playerScore; break;
		case 'c': return computerScore; break;
		case 'd': return drawCount; break;
	}
}

int ModelSFML::getTileWidth()
{
	return tileWidth;
}

int ModelSFML::getTileCount()
{
	return tileCount;
}

sf::RectangleShape ModelSFML::getShape(int index)
{
	return arr[index];
}

sf::Color ModelSFML::getColor(int index)
{
	return arr[index].getFillColor();
}

void ModelSFML::setColor(int index, sf::Color color)
{
	arr[index].setFillColor(color);
}