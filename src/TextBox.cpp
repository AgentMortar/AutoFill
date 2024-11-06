//
// Created by ukegi on 11/5/2024.
//

#include "TextBox.h"

TextBox::TextBox()
{
	_width = 200;
	_height = 50;
	_position = { 0, 0 };
	_box = sf::RectangleShape(sf::Vector2f(_width, _height));
	_box.setPosition(0, 0);
	_box.setFillColor(sf::Color::Black);
	_box.setOutlineColor(sf::Color::White);
	_box.setOutlineThickness(5);
}

TextBox::TextBox(int width, int height, std::vector<int> position)
{
	_width = width;
	_height = height;
	_position = position;
	_box = sf::RectangleShape(sf::Vector2f(_width, _height));
	_box.setPosition(position[0], position[1]);
	_box.setFillColor(sf::Color::Black);
	_box.setOutlineColor(sf::Color::White);
	_box.setOutlineThickness(5);
}


void TextBox::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
	window.draw(_box);
}

void TextBox::setSize(std::vector<int> size)
{
	_width = size[0];
	_height = size[1];
	_box.setSize(sf::Vector2f(_width, _height));
}


void TextBox::setPosition(std::vector<int> position)
{

	_box.setPosition(position[0], position[1]);
	_position = position;
}

int TextBox::getWidth() const
{
	return _width;
}

int TextBox::getHeight() const
{
	return _height;
}



std::vector<int> TextBox::getPosition() const
{
	return _position;
}

sf::RectangleShape TextBox::getBox() const
{
	return _box;
}
