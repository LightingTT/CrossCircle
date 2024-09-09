#include "Field.h"
#include "Renderer.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(300, 300), "Tic-Tac-Toe");

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
            else
            {
                field.handleEvent(event);
            }
        }
        renderer.render(field);
    }
}

