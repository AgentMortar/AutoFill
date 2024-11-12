//
// Created by ukegi on 11/5/2024.
//

#include "fallingText.h"

fallingText::fallingText()
{
	_size = 30;
	_text = "Enter Text:";
	_margin = { 0, 0, 0, 0 };
	_position = { 0, 0 };
	_font = Font::getFont("arial");
	_inputText.setFont(_font);
	_inputText.setString(_text);
	_inputText.setCharacterSize(_size);
	_inputText.setPosition(_position[0], _position[1]);


}

fallingText::fallingText(std::string text, int size, std::vector<int> margin, std::vector<int> position, std::string fontName)
{
	_size = size;
	_text = text;
	_margin = margin;
	_position = position;
	_font = Font::getFont(fontName);
	_inputText.setFont(_font);
	_inputText.setString(_text);
	_inputText.setCharacterSize(_size);
	_inputText.setPosition(_position[0], _position[1]);

}

void fallingText::setText(std::string text)
{
	_text = text;
	_inputText.setString(text);
}

void fallingText::setSize(int size)
{
	_size = size;
	_inputText.setCharacterSize(size);
}

void fallingText::setMargin(std::vector<int> margin)
{
	_margin = margin;
}

void fallingText::setPosition(std::vector<int> position)
{
	_position = position;
	_inputText.setPosition(position[0], position[1]);
}

void fallingText::setFont(std::string fontName)
{
	_font = Font::getFont(fontName);
	_inputText.setFont(_font);
}

void fallingText::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
	window.draw(_inputText);
}

std::string fallingText::getText() const
{
	return _text;
}

int fallingText::getSize() const
{
	return _size;
}

std::vector<int> fallingText::getMargin() const
{
	return _margin;
}

std::vector<int> fallingText::getPosition() const
{
	return _position;
}

sf::Font fallingText::getFont() const
{
	return _font;
}

float fallingText::getWidth() const
{
	return _inputText.getLocalBounds().width;
}

void fallingText::addCharacter(sf::Uint32 uint32)
{

	_text += uint32;
	_inputText.setString(_text);

}

void fallingText::deleteCharacter()
{
	if (_text.size() > 0)
	{
		_text.pop_back();
		_inputText.setString(_text);
	}
}

