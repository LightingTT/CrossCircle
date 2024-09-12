#pragma once
#include <SFML/Graphics.hpp>
#include "Field.h"
class Renderer
{
public:
    sf::RenderWindow& window;
    Renderer(sf::RenderWindow& window);
    void render(Field& field);

    void drawX(int row, int col);

    void drawO(int row, int col);
    void drawWinningLine(WinType, int);
    std::string winTypeToString(WinType winType);
};

std::ostream& operator<<(std::ostream& os, const std::vector<std::vector<char>>& board);