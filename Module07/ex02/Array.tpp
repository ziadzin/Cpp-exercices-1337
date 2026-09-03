template <typename T> T *newcopy(T *data, unsigned int size)
{
	T *copy = new T[size];
	for (unsigned int i = 0; i < size; i++)
		copy[i] = data[i];
	return copy;
}

template <typename T> Array<T>::Array() : _data(new T[0]), _size(0)
{
}

template <typename T> Array<T>::Array(unsigned int n) : _data(new T[n]), _size(n)
{
}

template <typename T> Array<T>::Array(const Array &other)
{
	_data = newcopy(other._data, other._size);
	_size = other._size;
}

template <typename T> Array<T> &Array<T>::operator=(const Array &other)
{
	if (this != &other)
	{
		_data = newcopy(other._data, other._size);
		_size = other._size;
	}
	return ;
}

template <typename T> Array<T>::~Array()
{
	delete[] _data;
}
