//
// Created by ukegi on 11/11/2024.
//

#ifndef WORDSORT_H
#define WORDSORT_H
#include <string>
#include <vector>
#include <fstream>
#include "Word.h"
#include "Heap.h"
#include "UserInputText.h"


class WordSort {

  private:
	std::vector<std::string> _strWordVector;
	std::vector<Word> _wordObjectVector;
	Heap<Word> _wordHeap;
	UserInputText _userInputText;

  public:
	WordSort();


	~WordSort();

	void setUserInputText(UserInputText userInputText);

	void fileToVector(std::string fileName);
	void vectorToHeap();

	void setPriority();

	void displayHeap();




};



#endif //WORDSORT_H
