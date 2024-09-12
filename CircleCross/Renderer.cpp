#include "Renderer.h"

Renderer::Renderer(sf::RenderWindow& window) : window(window) {}

void Renderer::render(Field& field)
{
    window.clear();

    sf::RectangleShape square(sf::Vector2f(100, 100));
    square.setFillColor(sf::Color::White);
    square.setOutlineThickness(2);                 
    square.setOutlineColor(sf::Color::Black);

    int position = field.winPosition;
    std::cout << "Current WinType: " << winTypeToString(field.winType) << std::endl;

    for (int row = 0; row < 3; ++row) 
    {
        for (int col = 0; col < 3; ++col)
        {
            // Position and draw the grid square 
            square.setPosition(col * 100, row * 100);
            window.draw(square);

            // Get the symbol ('X' or 'O') at this cell from the field
            char symbol = field.getSymbolAt(row, col);

            
            if (symbol == 'X')
            {
                drawX(row, col);
            }
            else if (symbol == 'O')
            {
                drawO(row, col);
            }

            if (field.winType != WinType::None)
            {
                drawWinningLine(field.winType, field.winPosition);
            }
           
        }
    }
    window.display();
}

void Renderer::drawX(int row, int col)
{
    sf::Vertex line1[] = {
        sf::Vertex(sf::Vector2f(col * 100 + 10, row * 100 + 10), sf::Color::Black),  // Starting point
        sf::Vertex(sf::Vector2f((col + 1) * 100 - 10, (row + 1) * 100 - 10), sf::Color::Black)  // Ending point
    };

    // Second diagonal line (from top-right to bottom-left)
    sf::Vertex line2[] = {
        sf::Vertex(sf::Vector2f((col + 1) * 100 - 10, row * 100 + 10), sf::Color::Black),  // Starting point
        sf::Vertex(sf::Vector2f(col * 100 + 10, (row + 1) * 100 - 10), sf::Color::Black)  // Ending point
    };

    // Draw the two lines on the window
    window.draw(line1, 2, sf::Lines);  // Draw first diagonal line
    window.draw(line2, 2, sf::Lines);  // Draw second diagonal line
}

void Renderer::drawO(int row, int col) 
{
    sf::CircleShape circle(40);  
    circle.setPosition(col * 100 + 10, row * 100 + 10);  
    circle.setOutlineColor(sf::Color::Black); 
    circle.setOutlineThickness(2);
    circle.setFillColor(sf::Color::Transparent);  
    window.draw(circle);
}

void Renderer::drawWinningLine(const WinType winType, int position)
{
    if (winType == WinType::Row) 
    {
       
    }
    else if (winType == WinType::Column) 
    {
        if (position == 0)
        {
            sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(((position + 1) * 100) - 50, 0), sf::Color::Black),  // Starting point
            sf::Vertex(sf::Vector2f(((position + 1) * 100) - 50, 300), sf::Color::Black),  // Ending point
            };

            window.draw(line, 2, sf::Lines);
        }
        if (position == 1)
        {
            sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(((position + 1) * 100) - 50, 0), sf::Color::Black),  // Starting point
            sf::Vertex(sf::Vector2f(((position + 1) * 100) - 50, 300), sf::Color::Black),  // Ending point
            };

            window.draw(line, 2, sf::Lines);
        }
        if (position == 2)
        {
            sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(((position + 1) * 100) - 50, 0), sf::Color::Black),  // Starting point
            sf::Vertex(sf::Vector2f(((position + 1) * 100) - 50, 300), sf::Color::Black),  // Ending point
            };

            window.draw(line, 2, sf::Lines);
        }
        
    }
    else if (winType == WinType::DiagonalMain) 
    {
        
    }
    else if (winType == WinType::DiagonalAnti) 
    {
        
    }
}

std::string Renderer::winTypeToString(WinType winType)
{
    switch (winType)
    {
    case WinType::None:
        return "None";
    case WinType::Row:
        return "Row";
    case WinType::Column:
        return "Column";
    case WinType::DiagonalMain:
        return "Diagonal Main";
    case WinType::DiagonalAnti:
        return "Diagonal Anti";
    default:
        return "Unknown";
    }
}

std::ostream& operator<<(std::ostream& os, const std::vector<std::vector<char>>& board)
{
    for (const auto& row : board) 
    {
        for (const auto& cell : row) 
        {
            os << cell << ' ';  
        }
        os << '\n';  
    }
    return os;
}
