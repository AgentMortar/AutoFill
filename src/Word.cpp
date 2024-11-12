//
// Created by ukegi on 11/11/2024.
//

#include "Word.h"

Word::Word()
{
	_text = sf::Text();
	_priority = 0;
}

Word::Word(std::string text)
{
	_text.setString(text);
	_priority = 0;
}


Word::Word(std::string text, int priority)
{
	_text.setString( text);
	_priority = priority;
}

sf::Text Word::getText()
{
	return _text;
}

void Word::setText(std::string text)
{
	_text.setString(text);
}

int Word::getPriority()
{
	return _priority;
}

void Word::setPriority(int priority)
{
	_priority = priority;
}
