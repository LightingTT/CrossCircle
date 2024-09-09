#ifndef FIELD_H
#define FIELD_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

class Field {
public:

    Field();
    void handleEvent(const sf::Event& event);
    char getSymbolAt(int row, int col);

private:
    std::vector<std::vector<char>> board;
    char currentSymbol;
};
#endif // FIELD_H