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

    void isTie(int);

private:
    std::vector<std::vector<char>> board;
    char currentSymbol;
    const int maxMoves{ 9 };
    void winState();
};

std::ostream& operator<<(std::ostream& os, const std::vector<std::vector<char>>& board);
#endif // FIELD_H