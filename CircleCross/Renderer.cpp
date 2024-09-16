#include "Renderer.h"

Renderer::Renderer(sf::RenderWindow& window) : window(window) {}

// Render the board. Game state handled in Field class
void Renderer::render(Field& field)
{
    window.clear();

    sf::RectangleShape square(sf::Vector2f(100, 100));
    square.setFillColor(sf::Color::White);
    square.setOutlineThickness(2);                 
    square.setOutlineColor(sf::Color::Black);

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
        }
    }

    if (field.winType != WinType::None)
    {
        drawWinningLine(field.winType, field.winPosition);
    }

}

void Renderer::drawX(int row, int col)
{
    // First diagonal line (from top-left to bottom-right)
    sf::Vertex line1[] = {
        sf::Vertex(sf::Vector2f(col * 100 + 10, row * 100 + 10), sf::Color::Black),  // Starting point
        sf::Vertex(sf::Vector2f((col + 1) * 100 - 10, (row + 1) * 100 - 10), sf::Color::Black)  // Ending point
    };

    // Second diagonal line (from top-right to bottom-left)
    sf::Vertex line2[] = {
        sf::Vertex(sf::Vector2f((col + 1) * 100 - 10, row * 100 + 10), sf::Color::Black),  
        sf::Vertex(sf::Vector2f(col * 100 + 10, (row + 1) * 100 - 10), sf::Color::Black)  
    };

    window.draw(line1, 2, sf::Lines);  
    window.draw(line2, 2, sf::Lines);  
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
        if (position == 0)
        {
            sf::Vertex line[] = {
                sf::Vertex(sf::Vector2f(0, ((position + 1) * 100) - 50), sf::Color::Black),
                sf::Vertex(sf::Vector2f(300, ((position + 1) * 100) - 50), sf::Color::Black),
            };

            window.draw(line, 2, sf::Lines);
        }
        if (position == 1)
        {
            sf::Vertex line[] = {
                sf::Vertex(sf::Vector2f(0, ((position + 1) * 100) - 50), sf::Color::Black),
                sf::Vertex(sf::Vector2f(300, ((position + 1) * 100) - 50), sf::Color::Black),
            };

            window.draw(line, 2, sf::Lines);
        }
        if (position == 2)
        {
            sf::Vertex line[] = {
                sf::Vertex(sf::Vector2f(0, ((position + 1) * 100) - 50), sf::Color::Black),
                sf::Vertex(sf::Vector2f(300, ((position + 1) * 100) - 50), sf::Color::Black),
            };

            window.draw(line, 2, sf::Lines);
        }
    }
    else if (winType == WinType::Column) 
    {
        if (position == 0)
        {
            sf::Vertex line[] = {
                sf::Vertex(sf::Vector2f(((position + 1) * 100) - 50, 0), sf::Color::Black),  
                sf::Vertex(sf::Vector2f(((position + 1) * 100) - 50, 300), sf::Color::Black),  
            };

            window.draw(line, 2, sf::Lines);
        }
        if (position == 1)
        {
            sf::Vertex line[] = {
                sf::Vertex(sf::Vector2f(((position + 1) * 100) - 50, 0), sf::Color::Black),  
                sf::Vertex(sf::Vector2f(((position + 1) * 100) - 50, 300), sf::Color::Black),  
            };

            window.draw(line, 2, sf::Lines);
        }
        if (position == 2)
        {
            sf::Vertex line[] = {
                sf::Vertex(sf::Vector2f(((position + 1) * 100) - 50, 0), sf::Color::Black),  
                sf::Vertex(sf::Vector2f(((position + 1) * 100) - 50, 300), sf::Color::Black),  
            };

            window.draw(line, 2, sf::Lines);
        }
    }
    else if (winType == WinType::DiagonalMain) 
    {
            sf::Vertex line[] = {
                sf::Vertex(sf::Vector2f(0, 0), sf::Color::Black),  
                sf::Vertex(sf::Vector2f(300, 300), sf::Color::Black),  
            }; 

            window.draw(line, 2, sf::Lines);
    }
    else if (winType == WinType::DiagonalAnti) 
    {
            sf::Vertex line[] = {
                sf::Vertex(sf::Vector2f(300, 0), sf::Color::Black),  
                sf::Vertex(sf::Vector2f(0, 300), sf::Color::Black),  
            };

        window.draw(line, 2, sf::Lines);
    }
  
}

void Renderer::displayWinPopup(const std::string& message)
{
    sf::RectangleShape popupBackground(sf::Vector2f(200, 100));
    popupBackground.setFillColor(sf::Color(0, 0, 0, 150));
    popupBackground.setPosition(50, 100);

    sf::Font font;
    font.loadFromFile("E.otf"); 

    sf::Text text;
    text.setFont(font);
    text.setString(message);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setPosition(70, 120);

    window.draw(popupBackground);
    window.draw(text);
}

