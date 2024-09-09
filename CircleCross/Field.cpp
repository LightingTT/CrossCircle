#include "Field.h"

Field::Field() : board(3, std::vector<char>(3, ' ')), currentSymbol('X') {}


void Field::handleEvent(const sf::Event& event)
{
    if (event.type == sf::Event::MouseButtonPressed)
    {
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            int col = event.mouseButton.x / 100;
            int row = event.mouseButton.y / 100;
            if (col >= 0 && col < 3 && row >= 0 && row < 3 && board[row][col] == ' ') {
                board[row][col] = currentSymbol;  // Set the current symbol ('X' or 'O')

                std::cout << "Clicked on row " << row << ", col " << col << " and placed: " << currentSymbol << std::endl;
                currentSymbol = (currentSymbol == 'X') ? 'O' : 'X';

            }
        }
    }
}

char Field::getSymbolAt(int row, int col)
{
    return board[row][col];
}


