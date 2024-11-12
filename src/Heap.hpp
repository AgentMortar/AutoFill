
#include "Heap.h"

template<typename T>
Heap<T>::Heap()
{
	heapArray = {};
	_size = 0;
}

template<typename T>
Heap<T>::Heap(std::vector<T> inputArray)
{
	heapArray = {};
	_size = 0;

	for (int i=0; i<inputArray.size(); i++)
	{
		push(inputArray.at(i));
	}
}



template<typename T>
Heap<T>::~Heap()
{
	erase();
}

template <typename T>
void Heap<T>::push(const T& data)
{
	heapArray.push_back(data);
	_size += 1;
	reheapifyUp(_size-1);
}

template <typename T>
void Heap<T>::pop()
{
	if (_size == 1)
	{
		heapArray.pop_back();
		_size -= 1;
	}
	else
	{
		heapArray.at(0) = heapArray.at(_size-1);
		heapArray.pop_back();
		_size -= 1;
		reheapifyDown(0);
	}

}

template <typename T>
void Heap<T>::erase()
{
	heapArray.clear();
	_size = 0;
}

template<typename T>
int Heap<T>::getSize() const
{
	return _size;
}

template<typename T>
bool Heap<T>::isEmpty()
{
	return _size == 0;
}

template<typename T>
T Heap<T>::getTop() const
{
	if (_size < 1)
	{
		throw std::out_of_range("Tree is empty, cannot get top value.");
	}
	return heapArray.at(0);
}

template<typename T>
void Heap<T>::print()
{
	for(int i=0; i < heapArray.size(); i++)
	{
		std::cout << heapArray.at(i) << " ";
	}
	std::cout << std::endl;
}

template <typename T>
void Heap<T>::reheapifyUp(int index) {
	if (index == 0) return;
	int parentIndex = (index - 1) / 2;
	if (hasHigherPriority(heapArray[index], heapArray[parentIndex])) {
		std::swap(heapArray[index], heapArray[parentIndex]);
		reheapifyUp(parentIndex);
	}
}


template <typename T>
void Heap<T>::reheapify() {
	// Perform a "heapify down" operation from the root downwards
	for (int i = (_size / 2) - 1; i >= 0; i--) {
		reheapifyDown(i);
	}
}

template <typename T>
void Heap<T>::reheapifyDown(int index) {
	int leftChild = 2 * index + 1;
	int rightChild = 2 * index + 2;
	int largest = index;

	if (leftChild < _size && hasHigherPriority(heapArray[leftChild], heapArray[largest])) {
		largest = leftChild;
	}
	if (rightChild < _size && hasHigherPriority(heapArray[rightChild], heapArray[largest])) {
		largest = rightChild;
	}
	if (largest != index) {
		std::swap(heapArray[index], heapArray[largest]);
		reheapifyDown(largest);
	}
}

template <typename T>
bool Heap<T>::largerThanParent(int index) const {
	if (index == 0) return false;
	int parentIndex = (index - 1) / 2;
	return hasHigherPriority(heapArray[index], heapArray[parentIndex]);
}

template<typename T>
Heap<T>& Heap<T>::operator+=(const T& data)
{
	push(data);
	return *this;
}

template <typename T>
bool Heap<T>::hasHigherPriority(const T& a, const T& b) const {
	return a.getPriority() > b.getPriority();
}