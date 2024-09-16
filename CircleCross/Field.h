#ifndef FIELD_H
#define FIELD_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

enum class WinType {
    None, Row, Column, DiagonalMain, DiagonalAnti, Draw
};

class Field {
public:

    Field();
    void handleEvent(const sf::Event& event);
    char getSymbolAt(int row, int col);
    char getSymbol();
    void isTie(int);
    void winState();
    int winPosition;
    WinType winType;

private:
    std::vector<std::vector<char>> board;
    char currentSymbol;
    const int maxMoves{ 9 };
    int endStateCounter{ 0 };
};
#endif // FIELD_H