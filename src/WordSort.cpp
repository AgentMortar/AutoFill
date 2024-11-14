




#include "WordSort.h"

WordSort::WordSort()
{
	fileToVector("C:/Users/ukegi/CLionProjects/AutoFill/resources/Names.txt");

}

void WordSort::setUserInputText(UserInputText userInputText)
{
	_userInputText = userInputText;
	setPriority();
	_wordHeap.erase();
	vectorToHeap();
}

void WordSort::fileToVector(std::string fileName)
{
	std::string str ;

	std::fstream file;
	file.open(fileName,std::ios::in);

	if (!file)
	{
		std::cout << "Error opening file" << std::endl;
	}
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

#include <algorithm>

void WordSort::setPriority()
{
	std::string baseWord = _userInputText.getText();
	size_t baseWordLength = baseWord.size();


	std::transform(baseWord.begin(), baseWord.end(), baseWord.begin(), ::tolower);

	for (auto &word : _wordObjectVector)
	{
		int count = 0;
		int bonus = 0;

		std::string wordString = word.getText().getString().toAnsiString();


		std::transform(wordString.begin(), wordString.end(), wordString.begin(), ::tolower);

		size_t wordLength = wordString.size();


		for (size_t i = 0; i < wordLength && i < baseWordLength; ++i)
		{
			if (wordString[i] == baseWord[i])
			{
				count++;
				if (i == 0) bonus += 5;  
				else if (i < 3) bonus += 2;
			}
		}


		word.setPriority(count + bonus);
	}
}





void WordSort::draw(sf::RenderTarget &window, sf::RenderStates states) const
{



	auto tempHeap = _wordHeap;
	if (tempHeap.isEmpty() || _userInputText.getText().empty())
	{
		return;
	}



	int i = 0;

	while (i < 20 && !tempHeap.isEmpty())
	{

		auto topWord = tempHeap.getTop();
		tempHeap.pop();


		topWord.getText().setPosition(100.f, 100.f + i * 50.f);





		window.draw(topWord.getText(), states);

		++i;
	}
}
