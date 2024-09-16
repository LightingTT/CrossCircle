#include "Field.h"
#include "Renderer.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(300, 300), "Tic-Tac-Toe");
    bool gameOver = false;
    Field field;
    Renderer renderer(window);

    while (window.isOpen()) 
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if(!gameOver)
            {
                field.handleEvent(event);
            }
            // Check for win condition
            if (field.winType != WinType::None && field.winType != WinType::Draw && !gameOver)
            {
                gameOver = true;
                std::string message = (field.getSymbol() == 'X') ? "Player O Wins!" : "Player X Wins!";
                renderer.render(field);
                renderer.displayWinPopup(message);
                window.display();
            }
            // Check for draw
            if (field.winType == WinType::Draw && !gameOver)
            {
                gameOver = true;
                std::string message = "YOU BOTH LOSE";
                renderer.render(field);
                renderer.displayWinPopup(message);
                window.display();
            }
            
        }
        
        if (!gameOver)
        {
            renderer.render(field);
            window.display();
        }
        
    }
}

