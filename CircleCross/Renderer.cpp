#include "Renderer.h"

Renderer::Renderer(sf::RenderWindow& window) : window(window) {}

void Renderer::render(Field& field)
{
    window.clear();

    sf::RectangleShape square(sf::Vector2f(100, 100));
    square.setFillColor(sf::Color::White);
    square.setOutlineThickness(2);                 
    square.setOutlineColor(sf::Color::Black);    
    //square.setFillColor(sf::Color::Transparent);
    

    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            // Position and draw the grid square
            square.setPosition(col * 100, row * 100);
            window.draw(square);

            // Get the symbol ('X' or 'O') at this cell from the field
            char symbol = field.getSymbolAt(row, col);

            // Render the appropriate symbol
            if (symbol == 'X') { 
                drawX(row, col);  // Draw an 'X' in this cell
            }
            else if (symbol == 'O') {
                drawO(row, col);  // Draw an 'O' in this cell
            }
      
        }
        
    }
    
    window.display();

}

void Renderer::drawX(int row, int col) {
    sf::Vertex line1[] = {
        sf::Vertex(sf::Vector2f(col * 100 + 10, (row * 100) + 10)),
        sf::Vertex(sf::Vector2f((col + 1 * 100) - 10, (row + 1) * 100 - 10))
    };
    
    sf::Vertex line2[] = {
        sf::Vertex(sf::Vector2f((col + 1) * 100 - 10, row * 100 + 10)),
        sf::Vertex(sf::Vector2f(col * 100 + 10, (row + 1) * 100 - 10))
    };

    window.draw(line1, 2, sf::Lines);
    window.draw(line2, 2, sf::Lines);

 
}

void Renderer::drawO(int row, int col) {
    
    sf::CircleShape circle(40);  
    circle.setPosition(col * 100 + 10, row * 100 + 10);  
    circle.setOutlineColor(sf::Color::Black); 
    circle.setOutlineThickness(5);
    circle.setFillColor(sf::Color::Transparent);  
    window.draw(circle);
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
