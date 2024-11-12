//
// Created by ukegi on 11/5/2024.
//

#ifndef FALLINGTEXT_H
#define FALLINGTEXT_H

#include <SFML/Graphics.hpp>
#include "Font.h"
#include <iostream>




class fallingText {
private:
	sf::Text _inputText;
	std::string _text;
	int _size;
	std::vector<int> _margin;
	std::vector<int> _position;
	sf::Font _font;

public:
	fallingText();
	fallingText(std::string text, int size, std::vector<int> margin, std::vector<int> position, std::string fontName);

	void setText(std::string text);
	void setSize(int size);
	void setMargin(std::vector<int> margin);
	void setPosition(std::vector<int> position);
	void setFont(std::string fontName);

	void draw(sf::RenderTarget &window, sf::RenderStates states) const;

	std::string getText() const;
	int getSize() const;
	std::vector<int> getMargin() const;
	std::vector<int> getPosition() const;
	sf::Font getFont() const;
	float getWidth() const;

	void addCharacter(sf::Uint32 uint32);

	void deleteCharacter();
};



#endif //FALLINGTEXT_H
