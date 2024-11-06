#include <SFML/Graphics.hpp>

#include <iostream>
#include "Cursor.h"
int main()
{
    sf::RenderWindow window({420, 720, 32}, "Cursor", (sf::Style::Close| sf::Style::Resize ) );
    window.setFramerateLimit(60);
    Cursor c;
    c.enableState(BLINKING);
    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(sf::Event::Closed == event.type)
                window.close();
        }
        c.update();
        window.clear();
        window.draw(c);
        window.display();
    }

    return 0;
}