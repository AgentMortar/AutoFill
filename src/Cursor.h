//
// Created by Dave R. Smith on 11/4/24.
//

#ifndef CURSOR_H
#define CURSOR_H

#include <SFML/Graphics.hpp>
#include "Font.h"
#include "States.h"
class Cursor : public sf::Text, public States
{
private:
	sf::Clock clock;
public:
	Cursor();
	virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
	void update();
	void setPosition(std::vector<int> position);

	bool isBlinking();
};



#endif //CURSOR_H