#include <vector.hpp>
#include <iostream>
#include <string>
#include <cmath>

//==========CONSTRUCTOR==========

template <class T> Vector<T>::Vector()
	:index(0), size(1), array(new T[size])
{
	//Do nothing
	//std::cout << "Call default constructor" << std::endl;
}
template <class T> Vector<T>::Vector(int num, int value)
	: index(num), size(num+1), array(new T[size])
{
	for (int i = 0; i < num; i++) {
		array[i] = value;
	}
	std::cout << "Call fill constructor" << std::endl;
}
template <class T> Vector<T>::Vector(const Vector& source)
	: index(source.index), size(source.size), array(new T[size])
{
	for (int i = 0; i < source.size; i++) {
		array[i] = source.array[i];
	}
	std::cout << "Call copy constructor" << std::endl;

}
template <class T> Vector<T>::Vector(const std::initializer_list<T>& list)
	: index(0), size(list.size()), array(new T[size])
{
	std::cout << list.size();
	for (int i:list) {
		push_back(i);
	}
}

//==========DESTRUCTOR==========

template <class T> Vector<T>::~Vector() {
	delete[] array;
	array = NULL;
}
//==========OPERATOR============
template <class T> Vector<T>& Vector<T>::operator=(Vector& source)
{
	if (size < source.index) {
		array = reSizeVector(array, (source.index));
	}
	for (int i = 0; i < source.index; i++) {
		array[i] = source.array[i];
	}
	return *this;
}

//==========CAPACITY==========
template <class T> bool Vector<T>::Empty() {
	return (index == 0);
}
template <class T> int Vector<T>::Size() {
	return index;
}
template <class T> double Vector<T>::Max_Size(Vector<T> v) {
	const char* x = typeid(v).name();
	char choose = '0';
	if (x == "class Vector<int>") { choose = '1'; }
	else if (x == "class Vector<float>") { choose = '2'; }
	else if (x == "class Vector<char>") { choose = '3'; }
	else { choose = '4'; }
	switch (choose) {
	case '1':
		return ((pow(2, 64) / sizeof(int)) - 1);
	case '2':
		return (pow(2, 64) / sizeof(float) - 1);
	case '3':
		return (pow(2, 64) / sizeof(char) - 1);
	case '4':
		return (pow(2, 64) / sizeof(double) - 1);
	}
}

//==========MEMEBER ACCESS==========

template <class T> T& Vector<T>::operator[](int index)
{
	return array[index];
}
template <class T> T Vector<T>::front() {
	return array[0];
}
template <class T> T Vector<T>::back() 
{
	return array[index - 1];
}

//==========MODIFIER==========

template <class T> void Vector<T>::clear() {
	delete[] array;
	array = nullptr;
	index = 0;
}
template <class T> void Vector<T>::insert(T value, int ind) 
{
	if (ind < 0 || ind >= this->index)
	{
		std::cout << "Invalid index";
		return;
	}
	if (index == size) {
		array = reSizeVector(array, size);
	}
	for (int i = index - 1; i >= ind; i--)
	{
		array[i + 1] = array[i];
	}
	array[ind] = value;
	index++;
}
template <class T> void Vector<T>::erase(int ind) {
	if (Empty()) 
	{
		std::cout << "Empty vector!" << std::endl;
	}
	else if (ind < 0 || ind >= this->index)
	{
		std::cout << "Invalid index";
		return;
	}
	else {
		for (int i = ind; i < index - 1; i++)
		{
			array[i] = array[i + 1];
		}
	}
	array[index].~T();   
	index--;
}
template <class T> void Vector<T>::erase(int firstIndex, int lastIndex) {
	if (Empty()) {
		std::cout << "Empty vector!" << std::endl;
	}
	else if (firstIndex < 0 || lastIndex >= this->index || lastIndex < 0 || firstIndex >= this->index)
	{
		std::cout << "Invalid index";
		return;
	}
	else {
		for (int i = firstIndex; i < index; i++) {
			array[i] = array[i + lastIndex];
		}
	}
	for (int i = lastIndex + 1; i < index; i++) {
		array[i].~T();
	}
	index -= (lastIndex - firstIndex + 1);
}
template <class T> void Vector<T>::push_back(T value) 
{
	if (index == size) {
		array = reSizeVector(array, size);
	}
	array[index] = value; 
	index++;
}
template <class T> void Vector<T>::pop_back() {
	if (Empty()) {
		std::cout << "Vector already empty";
	}
	else {
		index--;

		array[index].~T();
	}
}
template <class T> void Vector<T>::push_front(T value)
{
	insert(value, 0);
}
template <class T> void Vector<T>::pop_front()
{
	erase(0);
}


// Sub Function

template <class T> T* Vector<T>::reSizeVector(T* array, int &size) { //
	T* temp_arr = new T[size*2];
	for (int i = 0; i < size; i++)
	{
		temp_arr[i] = array[i];
	}
	size *= 2;
	delete[] array;
	return temp_arr;
}

template <class T> void Vector<T>::browseVector() {
	for (int i = 0; i < index; i++) 
	{
		std::cout << array[i] << " ";
	}
}