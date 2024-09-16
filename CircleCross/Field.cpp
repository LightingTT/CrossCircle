#include "Field.h"

Field::Field() : board(3, std::vector<char>(3, ' ')), currentSymbol('X'), winType(WinType::None), winPosition{ 0 } {}


void Field::handleEvent(const sf::Event& event)
{
    if (event.type == sf::Event::MouseButtonPressed)
    {
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            // Determine which grid user is clicking on. If the user clicks on the first 100 pixels horizontally (x value between 0-99), 
            // the division by 100 will result in 0, indicating column 0. Same for vertical values.
            int col = event.mouseButton.x / 100;
            int row = event.mouseButton.y / 100;
            
            if (col >= 0 && col < 3 && row >= 0 && row < 3 && board[row][col] == ' ') {
                board[row][col] = currentSymbol;  // Set the current symbol ('X' or 'O')
                endStateCounter++;
                isTie(endStateCounter);
                winState();
                std::cout << endStateCounter << std::endl;
                // Change the player
                if (currentSymbol == 'X') 
                {
                    currentSymbol = 'O';
                }
                else
                {
                    currentSymbol = 'X';
                }
            }
        }
    }
}

char Field::getSymbolAt(int row, int col)
{
    return board[row][col];
}

char Field::getSymbol()
{
    return currentSymbol;
}

void Field::isTie(int endStateCounter)
{
    if (endStateCounter == maxMoves)
    {
        winType = WinType::Draw;
    }
}

void Field::winState()
{
    // 'X' Win conditions
    // Column win conditions
    int winColCounter_X_1{0};
    for (int i = 0; i < 3; i++)
    {
            if (board[i][0] == 'X')
            {
                winColCounter_X_1++;
            }
    }
    if (winColCounter_X_1 == 3)
    {
        winType = WinType::Column;
        winPosition = 0;
    }
    int winColCounter_X_2{ 0 };
    for (int i = 0; i < 3; i++)
    {
        if (board[i][1] == 'X')
        {
            winColCounter_X_2++;
        }

    }
    if (winColCounter_X_2 == 3)
    {
        winType = WinType::Column;
        winPosition = 1;
    }

    int winColCounter_X_3{ 0 };
    for (int i = 0; i < 3; i++)
    {
        if (board[i][2] == 'X')
        {
            winColCounter_X_3++;
        }
    }
    if (winColCounter_X_3 == 3)
    {
        winType = WinType::Column;
        winPosition = 2;
    }

    // Row win conditions
    int winRowCounter_X_1{ 0 };
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == 'X')
        {
            winRowCounter_X_1++;
        }
    }
    if (winRowCounter_X_1 == 3)
    {
        winType = WinType::Row;
        winPosition = 0;
    }

    int winRowCounter_X_2{ 0 };
    for (int i = 0; i < 3; i++)
    {
        if (board[1][i] == 'X')
        {
            winRowCounter_X_2++;
        }
    }
    if (winRowCounter_X_2 == 3)
    {
        winType = WinType::Row;
        winPosition = 1;
    }

    int winRowCounter_X_3{ 0 };
    for (int i = 0; i < 3; i++)
    {
        if (board[2][i] == 'X')
        {
            winRowCounter_X_3++;
        }
    }
    if (winRowCounter_X_3 == 3)
    {
        winType = WinType::Row;
        winPosition = 2;
    }

    // Diagonal win conditions
    int winDiagCounter_X_1{ 0 };
    for (int i = 0, j = 0; i < 3 && j < 3; i++, j++)
    {
        if (board[i][j] == 'X')
        {
            winDiagCounter_X_1++;
        }
    }
    if (winDiagCounter_X_1 == 3)
    {
        winType = WinType::DiagonalMain;
        winPosition = -1;
    }

    int winDiagCounter_X_2{ 0 };
    for (int i = 0, j = 2; i < 3 && j >= 0; i++, j--)
    {
        if (board[i][j] == 'X')
        {
            winDiagCounter_X_2++;
        }
    }

    if (winDiagCounter_X_2 == 3)
    {
        winType = WinType::DiagonalAnti;
        winPosition = -2;
    }
  
    // 'O' Win conditions
    // Column win conditions
    int winColCounter_O_1{ 0 };
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == 'O')
        {
            winColCounter_O_1++;
        }
    }

    if (winColCounter_O_1 == 3)
    {
        winType = WinType::Column;
        winPosition = 0;
    }

    int winColCounter_O_2{ 0 };
    for (int i = 0; i < 3; i++)
    {
        if (board[i][1] == 'O')
        {
            winColCounter_O_2++;
        }
    }

    if (winColCounter_O_2 == 3)
    {
        winType = WinType::Column;
        winPosition = 1;
    }

    int winColCounter_O_3{ 0 };
    for (int i = 0; i < 3; i++)
    {
        if (board[i][2] == 'O')
        {
            winColCounter_O_3++;
        }
    }

    if (winColCounter_O_3 == 3)
    {
        winType = WinType::Column;
        winPosition = 2;
    }

    // Row win conditions
    int winRowCounter_O_1{ 0 };
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == 'O')
        {
            winRowCounter_O_1++;
        }
    }

    if (winRowCounter_O_1 == 3)
    {
        winType = WinType::Row;
        winPosition = 0;
    }

    int winRowCounter_O_2{ 0 };
    for (int i = 0; i < 3; i++)
    {
        if (board[1][i] == 'O')
        {
            winRowCounter_O_2++;
        }
    }

    if (winRowCounter_O_2 == 3)
    {
        winType = WinType::Row;
        winPosition = 1;
    }

    int winRowCounter_O_3{ 0 };
    for (int i = 0; i < 3; i++)
    {
        if (board[2][i] == 'O')
        {
            winRowCounter_O_3++;
        }
    }

    if (winRowCounter_O_3 == 3)
    {
        winType = WinType::Row;
        winPosition = 2;
    }

    // Diagonal win conditions
    int winDiagCounter_O_1{ 0 };
    for (int i = 0, j = 0; i < 3 && j < 0; i++, j++)
    {
        if (board[i][j] == 'O')
        {
            winDiagCounter_O_1++;
        }
    }

    if (winDiagCounter_O_1 == 3)
    {
        winType = WinType::DiagonalMain;
        winPosition = -1;
    }

    int winDiagCounter_O_2{ 0 };
    for (int i = 0, j = 2; i < 3 && j >= 0; i++, j--)
    {
        if (board[i][j] == 'O')
        {
            winDiagCounter_O_2++;
        }
    }

    if (winDiagCounter_O_2 == 3)
    {
        winType = WinType::DiagonalAnti;
        winPosition = -2;
    }
}


