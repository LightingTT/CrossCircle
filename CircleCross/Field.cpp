#include "Field.h"


Field::Field() : window(sf::VideoMode(600, 600), "Tic-Tac-Toe")
{

}

void Field::run()
{
    initializeCells();
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        drawCells();
        window.display();

    }
}

void Field::initializeCells()
{
    cell = sf::RectangleShape(sf::Vector2f(200, 200));
    cell.setFillColor(sf::Color::White);
    cell.setOutlineColor(sf::Color::Black);
    cell.setOutlineThickness(3);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            Field::field[i][j] = cell;
            field[i][j].setPosition(i * 200, j * 200);
        }

    }
}

void Field::drawCells()
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            window.draw(field[i][j]);
        }
    }
}
