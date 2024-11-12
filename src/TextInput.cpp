//
// Created by ukegi on 11/5/2024.
//

#include "TextInput.h"

TextInput::TextInput()
{
	label.setFont("arial");
	label.setSize(30);
	label.setText("Enter first and last name:");
	label.setMargin({ 10, 10, 10, 10 });

	box.setSize({500,45});


	cursor.enableState(HIDDEN);

	inputText.setSize(30);
	inputText.setFont("arial");
	inputText.setText("");



	setPosition({0,0});

}

TextInput::TextInput(std::string labelText, int labelSize, std::vector<int> labelMargin, std::vector<int> labelPosition,
	std::string fontName, int boxWidth, int boxHeight, std::vector<int> boxPosition)
{
	label.setFont(fontName);
	label.setSize(labelSize);
	label.setText(labelText);
	label.setPosition(labelPosition);
	label.setMargin(labelMargin);

	box.setSize({boxWidth, boxHeight});
	box.setPosition({ 0, 0 });

	cursor.enableState(HIDDEN);
	cursor.enableState(BLINKING);

	cursor.setPosition({box.getPosition()[0]+5, box.getPosition()[1]+box.getHeight()});

}


void TextInput::setBoxSize(std::vector<int> size)
{
	box.setSize(size);
}

void TextInput::setBoxPosition(std::vector<int> position)
{
	box.setPosition(position);
}

void TextInput::setLabelText(std::string text)
{
	label.setText(text);
}

void TextInput::setLabelSize(int size)
{
	label.setSize(size);
}

void TextInput::setLabelMargin(std::vector<int> margin)
{
	label.setMargin(margin);
}

void TextInput::setLabelPosition(std::vector<int> position)
{
	label.setPosition(position);
}

void TextInput::setLabelFont(std::string fontName)
{
	label.setFont(fontName);
}

void TextInput::setInputTextText(std::string text)
{
	inputText.setText(text);
}

void TextInput::setInputTextSize(int size)
{
	inputText.setSize(size);
}

void TextInput::setInputTextMargin(std::vector<int> margin)
{
	inputText.setMargin(margin);
}

void TextInput::setInputTextPosition(std::vector<int> position)
{
	inputText.setPosition(position);
}

void TextInput::setInputTextFont(std::string fontName)
{
	inputText.setFont(fontName);
}



void TextInput::setPosition(std::vector<int> position)
{
	label.setPosition(position);
	std::vector<int> boxPosition = { position[0]+label.getMargin()[3], position[1] + label.getSize() + label.getMargin()[1] };
	box.setPosition(boxPosition);
	std::vector<int> cursorPosition = {box.getPosition()[0]+5, box.getPosition()[1]};
	cursor.setPosition(cursorPosition);
	inputText.setPosition(cursorPosition);
}

void TextInput::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
	box.draw(window, states);
	label.draw(window, states);
	cursor.draw(window, states);
	inputText.draw(window, states);
	wordSort.draw(window, states);




}

void TextInput::update()
{
	cursor.update();

	for (auto &text : fallingTextVector)
	{
		text.setPosition({text.getPosition()[0], text.getPosition()[1]+1});
	}

}

void TextInput::handleLeftClick(const sf::Event &event)
{
	if (event.mouseButton.button == sf::Mouse::Left)
	{
		if (box.getBox().getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
		{
			cursor.enableState(BLINKING);
			cursor.disableState(HIDDEN);
		}
		else
		{
			cursor.disableState(BLINKING);
			cursor.enableState(HIDDEN);
		}
	}


}

void TextInput::handleTextInput(const sf::Event &event)
{
	if (cursor.isBlinking())
	{
		if(event.text.unicode == 8)
		{
			inputText.deleteCharacter();
		}
		else if (event.text.unicode < 128)
		{
			if (inputText.getWidth() < box.getWidth() - 15)
			{
				inputText.addCharacter(event.text.unicode);
			}


		}
		//The +2 is just to give a little space between the text and the cursor
		cursor.setPosition({static_cast<int>(inputText.getPosition()[0]+inputText.getWidth())+2, inputText.getPosition()[1]});
		wordSort.setUserInputText(inputText);

	}
}
