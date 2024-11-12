//
// Created by ukegi on 10/29/2024.
//

#ifndef HEAP_H
#define HEAP_H
#include <vector>
#include <iostream>
template <typename T>
class Heap
{
private:
	std::vector<T> heapArray;
	int _size;




	void reheapifyUp(int index);



	void reheapifyDown(int index);

	bool hasHigherPriority(const T& a, const T& b) const;

	bool largerThanParent(int index) const;

public:
	Heap();
	explicit Heap(std::vector<T> inputArray);
	~Heap();
	void reheapify();
	void push(const T& data);
	void pop();

	void erase();

	int getSize() const;
	bool isEmpty();
	T getTop() const;

	void print();

	Heap<T>& operator+=(const T& data);

};


#include "Heap.hpp"
#endif //HEAP_H

