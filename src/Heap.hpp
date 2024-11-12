
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
int Heap<T>::getSize()
{
	return _size;
}

template<typename T>
bool Heap<T>::isEmpty()
{
	return _size == 0;
}

template<typename T>
T Heap<T>::getTop()
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
void Heap<T>::reheapifyUp(int index)
{
	if (largerThanParent(index))
	{
		T temp = heapArray.at((index-1)/2);
		heapArray.at((index-1)/2) = heapArray.at(index);
		heapArray.at(index) = temp;
		reheapifyUp((index-1)/2);
	}

}

template <typename T>
void Heap<T>::reheapifyDown(int index)
{

	T nodeValue = heapArray.at(index);
	if (((2 * index) + 1) > (_size-1))
	{
		return;
	}
	if (((2 * index) + 2) > (_size-1))
	{
		T ChildValue = heapArray.at((2 * index) + 1);
		if(ChildValue > nodeValue)
		{
			heapArray.at(index) = ChildValue;
			heapArray.at((2 * index) + 1) = nodeValue;
			return;
		}
		return;
	}

	T leftChildValue = heapArray.at((2 * index) + 1);
	T rightChildValue = heapArray.at((2 * index) + 2);

	if (leftChildValue >= rightChildValue && leftChildValue > nodeValue )
	{
		heapArray.at(index) = leftChildValue;
		heapArray.at((2 * index) + 1) = nodeValue;
		reheapifyDown((2 * index) + 1);
	}
	else if (rightChildValue > leftChildValue  && rightChildValue > nodeValue)
	{
		heapArray.at(index) = rightChildValue;
		heapArray.at((2 * index) + 2) = nodeValue;
		reheapifyDown((2 * index) + 2);
	}

}

template<typename T>
bool largerThanParent(int index) const {
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

template<typename T>
bool hasHigherPriority(const T& a, const T& b) const {
	return a.getPriority() > b.getPriority();
}