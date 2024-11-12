//
// Created by ukegi on 11/11/2024.
//

#include "Word.h"

Word::Word()
{
	_text = sf::Text();
	_text.setFont(Font::getFont("arial"));
	_priority = 0;
}

Word::Word(std::string text)
{
	_text.setString(text);
	_priority = 0;
	_text.setFont(Font::getFont("arial"));
}


Word::Word(std::string text, int priority)
{
	_text.setString( text);
	_priority = priority;
}

sf::Text& Word::getText()
{
	return _text;
}

std::string Word::getTextString()
{
	return _text.getString();
}

void Word::setText(std::string text)
{
	_text.setString(text);
}

int Word::getPriority() const
{
	return _priority;
}

void Word::setPriority(int priority)
{
	_priority = priority;
}

void Word::draw(sf::RenderTarget &window, sf::RenderStates states) const
{

}
