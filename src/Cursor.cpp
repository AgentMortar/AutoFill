//
// Created by Dave R. Smith on 11/4/24.
//

#include "Cursor.h"

Cursor::Cursor()
{
	sf::Text::setFont(Font::getFont("arial"));
	sf::Text::setString("|");
	sf::Text::setCharacterSize(24);
}
void Cursor::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
	sf::Text t = *this;
	if(!checkState(HIDDEN))
		window.draw(t);
}

void Cursor::update()
{
	if(checkState(BLINKING))
	{
		if(clock.getElapsedTime().asMilliseconds() > 250)
		{
			toggleState(HIDDEN);
			clock.restart();
		}

	}
}