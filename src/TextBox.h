//
// Created by ukegi on 11/5/2024.
//

#ifndef TEXTBOX_H
#define TEXTBOX_H

#include <SFML/Graphics.hpp>



class TextBox {
private:
	sf::RectangleShape _box;
	int _width;
	int _height;
	std::vector<int> _position;


public:
	TextBox();

	TextBox(int width, int height, std::vector<int> position);

	void draw(sf::RenderTarget &window, sf::RenderStates states) const;

	void setSize(std::vector<int> size);

	void setWidth(int width);

	void setHeight(int height);


	void setPosition(std::vector<int> position);

	int getWidth() const;

	int getHeight() const;

	std::vector<int> getPosition() const;

	int getX() const;

	int getY() const;

	sf::RectangleShape getBox() const;

};



#endif //TEXTBOX_H
