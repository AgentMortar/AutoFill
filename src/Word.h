//
// Created by ukegi on 11/11/2024.
//

#ifndef WORD_H
#define WORD_H

#include <SFML/Graphics.hpp>
#include "Font.h"


class Word {

private:
	sf::Text _text;
	int _priority;


public:

	Word();
	explicit Word(std::string text);
	Word(std::string text, int priority);

	sf::Text& getText();

	std::string getTextString();


	void setText(std::string text);
	int getPriority() const;
	void setPriority(int priority);

	void draw(sf::RenderTarget &window, sf::RenderStates states) const;


};



#endif //WORD_H