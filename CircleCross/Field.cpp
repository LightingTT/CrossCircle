#include "Field.h"

Field::Field() : board(3, std::vector<char>(3, ' ')), currentSymbol('X'), winType(WinType::None), winPosition{ 0 } {}


void Field::handleEvent(const sf::Event& event)
{
    if (event.type == sf::Event::MouseButtonPressed)
    {
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            int col = event.mouseButton.x / 100;
            int row = event.mouseButton.y / 100;
            int endStateCounter{ 0 };
            if (col >= 0 && col < 3 && row >= 0 && row < 3 && board[row][col] == ' ') {
                board[row][col] = currentSymbol;  // Set the current symbol ('X' or 'O')
                endStateCounter++;
                winState();
                isTie(endStateCounter);
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

void Field::isTie(int endStateCounter)
{
    if (endStateCounter == maxMoves)
    {
        //render tie or something
    }
}

void Field::winState()
{
    winType = WinType::None;
    // X Win conditions
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
            // send draw function to render and draw a line
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
            // send draw function to render and draw a line
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
            // send draw function to render and draw a line
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
            // send draw function to render and draw a line
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
            // send draw function to render and draw a line
            winDiagCounter_X_2++;
        }
    }

    if (winDiagCounter_X_2 == 3)
    {
        winType = WinType::DiagonalAnti;
        winPosition = -2;
    }
  
     /*
     ===========================================================================
     O Win conditions
     Column win conditions
     */

    int winColCounter_O_1{ 0 };
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == 'O')
        {
            // send draw function to render and draw a line
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
            // send draw function to render and draw a line
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
            // send draw function to render and draw a line
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
            // send draw function to render and draw a line
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
            // send draw function to render and draw a line
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
            // send draw function to render and draw a line
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
            // send draw function to render and draw a line
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
            // send draw function to render and draw a line
            winDiagCounter_O_2++;
        }
    }

    if (winDiagCounter_O_2 == 3)
    {
        winType = WinType::DiagonalAnti;
        winPosition = -2;
    }


}


