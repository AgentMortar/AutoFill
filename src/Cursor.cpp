//
// Created by Dave R. Smith on 11/4/24.
//

#include "Cursor.h"

Cursor::Cursor()
{
	sf::Text::setFont(Font::getFont("arial"));
	sf::Text::setString("|");
	sf::Text::setCharacterSize(30);
	sf::Text::setPosition(0, 0);

}
void Cursor::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
	sf::Text t = *this;
	if(!checkState(HIDDEN))
		window.draw(t);
}

void Cursor::update()
{
	if(checkState(BLINKING) && clock.getElapsedTime().asMilliseconds() > 250)
	{
		toggleState(HIDDEN);
		clock.restart();
	}
}

void Cursor::setPosition(std::vector<int> position)
{
	sf::Text::setPosition(position[0], position[1]);
}

bool Cursor::isBlinking()
{
	return checkState(BLINKING);
}

