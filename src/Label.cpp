//
// Created by ukegi on 11/5/2024.
//

#include "Label.h"

Label::Label()
{
	_size = 30;
	_text = "Enter Text:";
	_margin = { 0, 0, 0, 0 };
	_position = { 0, 0 };
	_font = Font::getFont("arial");
	_label.setFont(_font);
	_label.setString(_text);
	_label.setCharacterSize(_size);
	_label.setPosition(_position[0], _position[1]);


}

Label::Label(std::string text, int size, std::vector<int> margin, std::vector<int> position, std::string fontName)
{
	_size = size;
	_text = text;
	_margin = margin;
	_position = position;
	_font = Font::getFont(fontName);
	_label.setFont(_font);
	_label.setString(_text);
	_label.setCharacterSize(_size);
	_label.setPosition(_position[0], _position[1]);

}

void Label::setText(std::string text)
{
	_text = text;
	_label.setString(text);
}

void Label::setSize(int size)
{
	_size = size;
	_label.setCharacterSize(size);
}

void Label::setMargin(std::vector<int> margin)
{
	_margin = margin;


}

void Label::setPosition(std::vector<int> position)
{
	_position = position;
	_label.setPosition(position[0], position[1]);
}

void Label::setFont(std::string fontName)
{
	_font = Font::getFont(fontName);
	_label.setFont(_font);
}

void Label::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
	window.draw(_label);
}

std::string Label::getText() const
{
	return _text;
}

int Label::getSize() const
{
	return _size;
}

std::vector<int> Label::getMargin() const
{
	return _margin;
}

std::vector<int> Label::getPosition() const
{
	return _position;
}

sf::Font Label::getFont() const
{
	return _font;
}
