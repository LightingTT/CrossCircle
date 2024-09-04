#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
class Field
{
	int width;
	int height;
	sf::RectangleShape cell;
	sf::RectangleShape field[3][3];
	sf::RenderWindow window;
public:
	Field();
	void run();
	void initializeCells();
	void drawCells();

};

