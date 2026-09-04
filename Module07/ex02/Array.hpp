#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <stdexcept>

template <typename T>
class Array
{
	private:
		T           *_data;
		unsigned int _size;

	public:
		Array();
		Array(unsigned int n);
		Array(const Array &other);
		Array &operator=(const Array &other);
		~Array();

		T &operator[](unsigned int index);
		const T &operator[](unsigned int index) const;
		unsigned int size() const;

};

template <typename T> T *newcopy(T *data, unsigned int size)
{
	if(size > 0)
	{
		T *copy = new T[size];
		for (unsigned int i = 0; i < size; i++)
			copy[i] = data[i];
		return copy;
	}
	return NULL;
}

template <typename T> Array<T>::Array() : _data(NULL), _size(0)
{
}

template <typename T> Array<T>::Array(unsigned int n) : _data(new T[n]()), _size(n)
{
}

template <typename T> Array<T>::Array(const Array &other) : _data(NULL), _size(0)
{
	*this = other;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
	if (this != &other)
	{
		delete[] _data;
		_data = newcopy(other._data, other._size);
		_size = other._size;
	}
	return (*this);
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw std::out_of_range("Index out of bounds");
	return _data[index];
}

template <typename T>
const T &Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
		throw std::out_of_range("Index out of bounds");
	return _data[index];
}

template <typename T>
unsigned int Array<T>::size() const
{
	return _size;
}

template <typename T> Array<T>::~Array()
{
	delete[] _data;
}

#endif
