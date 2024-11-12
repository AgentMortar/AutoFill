//
// Created by ukegi on 11/11/2024.
//

#include "WordSort.h"

WordSort::WordSort()
{
	fileToVector("Names.txt");
	vectorToHeap();
}

WordSort::~WordSort()
{

}

void WordSort::setUserInputText(UserInputText userInputText)
{
	_userInputText = userInputText;
}

void WordSort::fileToVector(std::string fileName)
{
	std::string str ;

	std::fstream file;
	file.open(fileName,std::ios::in);

	while(getline(file, str))
	{
		auto word = Word(str);
		_wordObjectVector.push_back(word);
	}
}

void WordSort::vectorToHeap()
{

	for (auto &word : _wordObjectVector)
	{
		_wordHeap.push(word);
	}

}

void WordSort::setPriority()
{
	std::string baseWord = _userInputText.getText();
	//for each word in the vector
	for (auto &word : _wordObjectVector)
	{
		int count = 0;
		//for each character in the word
		for (auto &c : word.getText().getString())
		{
			//if the character is in the base word
			if(baseWord.find(c) != std::string::npos)
			{
				count++;
			}
		}
		word.setPriority(count);
	}

}

void WordSort::displayHeap()
{
}
