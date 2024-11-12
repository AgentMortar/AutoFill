//
// Created by ukegi on 10/29/2024.
//

#ifndef HEAP_H
#define HEAP_H
#include <vector>

template <typename T>
class Heap
{
private:
	std::vector<T> heapArray;
	int _size;




	void reheapifyUp(int index);
	void reheapifyDown(int index);

	bool largerThanParent(int index);


public:
	Heap();
	explicit Heap(std::vector<T> inputArray);
	~Heap();

	void push(const T& data);
	void pop();

	void erase();

	int getSize();
	bool isEmpty();
	T getTop();

	void print();

	Heap<T>& operator+=(const T& data);

};


#include "../Heap.hpp"
#endif //HEAP_H

