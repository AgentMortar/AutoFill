//
// Created by ukegi on 11/5/2024.
//

#include "UserInputText.h"

UserInputText::UserInputText()
{
	_size = 30;
	_text = "Enter Text:";
	_margin = { 0, 0, 0, 0 };
	_position = { 0, 0 };
	_font = Font::getFont("arial");
	_userInput.setFont(_font);
	_userInput.setString(_text);
	_userInput.setCharacterSize(_size);
	_userInput.setPosition(_position[0], _position[1]);


}

UserInputText::UserInputText(std::string text, int size, std::vector<int> margin, std::vector<int> position, std::string fontName)
{
	_size = size;
	_text = text;
	_margin = margin;
	_position = position;
	_font = Font::getFont(fontName);
	_userInput.setFont(_font);
	_userInput.setString(_text);
	_userInput.setCharacterSize(_size);
	_userInput.setPosition(_position[0], _position[1]);

}

void UserInputText::setText(std::string text)
{
	_text = text;
	_userInput.setString(text);
}

void UserInputText::setSize(int size)
{
	_size = size;
	_userInput.setCharacterSize(size);
}

void UserInputText::setMargin(std::vector<int> margin)
{
	_margin = margin;
}

void UserInputText::setPosition(std::vector<int> position)
{
	_position = position;
	_userInput.setPosition(position[0], position[1]);
}

void UserInputText::setFont(std::string fontName)
{
	_font = Font::getFont(fontName);
	_userInput.setFont(_font);
}

void UserInputText::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
	window.draw(_userInput);
}

std::string UserInputText::getText() const
{
	return _text;
}

int UserInputText::getSize() const
{
	return _size;
}

std::vector<int> UserInputText::getMargin() const
{
	return _margin;
}

std::vector<int> UserInputText::getPosition() const
{
	return _position;
}

sf::Font UserInputText::getFont() const
{
	return _font;
}

float UserInputText::getWidth() const
{
	return _userInput.getLocalBounds().width;
}

void UserInputText::addCharacter(sf::Uint32 uint32)
{

	_text += uint32;
	_userInput.setString(_text);

}

void UserInputText::deleteCharacter()
{
	if (_text.size() > 0)
	{
		_text.pop_back();
		_userInput.setString(_text);
	}
}

