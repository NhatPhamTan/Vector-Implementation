#pragma once
#include <iostream>

template <class T> class Vector
{
private:
	int index;	// current index of element in vector
	int size;	// capacity of vector 
	T* array;	// an array use to stored vector element address
public:

				//CONSTRUCTOR

	Vector();
	Vector(int num, int value = 0);
	Vector(const Vector& source);
	Vector(const std::initializer_list<T>& list);

				//DESTRUCTOR

	~Vector();

	Vector& operator=(Vector& source);

				//MEMBER ACCESS

	T& operator[](int index);
	T front();
	T back();

				//CAPACITY

	bool Empty();
	int Size();
	double Max_Size(Vector<T> v);

				//MODIFIER

	void clear();
	void insert(T value, int ind);
	void erase(int ind);
	void erase(int firstIndex, int lastIndex);
	void push_back(T value);
	void pop_back();
	void push_front(T value);
	void pop_front();
	T* reSizeVector(T* array, int &size);
	void browseVector();
};

template class Vector<int>;
template class Vector<char>;
template class Vector<float>;
template class Vector<double>;




