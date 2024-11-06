//
// Created by ukegi on 11/5/2024.
//

#ifndef TEXTINPUT_H
#define TEXTINPUT_H

#include "TextBox.h"
#include "Cursor.h"
#include "Label.h"
#include "UserInputText.h"

#include <string>
#include <vector>


class TextInput {

private:
	TextBox box;
	Label label;
	Cursor cursor;
	UserInputText inputText;


	void setCursorPosition(std::vector<int> position);
public:
	TextInput();
	TextInput(std::string labelText, int labelSize, std::vector<int> labelMargin, std::vector<int> labelPosition, std::string fontName, int boxWidth, int boxHeight, std::vector<int> boxPosition);

	void setBoxSize(std::vector<int> size);
	void setBoxPosition(std::vector<int> position);


	void setLabelText(std::string text);
	void setLabelSize(int size);
	void setLabelMargin(std::vector<int> margin);
	void setLabelPosition(std::vector<int> position);
	void setLabelFont(std::string fontName);

	void setInputTextText(std::string text);
	void setInputTextSize(int size);
	void setInputTextMargin(std::vector<int> margin);
	void setInputTextPosition(std::vector<int> position);
	void setInputTextFont(std::string fontName);


	void setPosition(std::vector<int> position);
	void draw(sf::RenderTarget &window, sf::RenderStates states) const;
	void update();

	void handleLeftClick(const sf::Event & event);
	void handleTextInput(const sf::Event & event);
};



#endif //TEXTINPUT_H
