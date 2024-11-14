
#include <SFML/Graphics.hpp>

#include <iostream>
#include "Cursor.h"
#include "TextInput.h"
int main()
{
    sf::RenderWindow window({1000, 1000, 32}, "Cursor", (sf::Style::Close| sf::Style::Resize ) );
    window.setFramerateLimit(60);

    TextInput text_input;


    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(sf::Event::Closed == event.type)
                window.close();

            if(sf::Event::TextEntered == event.type)
            {

                text_input.handleTextInput(event);
            }


            if(sf::Event::MouseButtonPressed == event.type)
            {
                text_input.handleLeftClick(event);
            }

        }

        window.clear();
        text_input.draw(window , sf::RenderStates::Default);
        text_input.update();
        window.display();
    }

    return 0;
}
