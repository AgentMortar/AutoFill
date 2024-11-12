//
// Created by ukegi on 11/11/2024.
//

#ifndef WORD_H
#define WORD_H

#include <SFML/Graphics.hpp>

//Class for word objects that have a text and a priority value

class Word {

private:
	sf::Text _text;
	int _priority;


public:

	Word();
	explicit Word(std::string text);
	Word(std::string text, int priority);

	sf::Text getText();
	void setText(std::string text);
	int getPriority();
	void setPriority(int priority);


};



#endif //WORD_H
