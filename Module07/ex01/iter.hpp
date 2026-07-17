#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

template <typename T, typename F>
void iter(T *arr,const std::size_t length, F f)
{
	for (size_t i = 0; i < length; i++)
	{
		f(arr[i]);
	}
	
}

#endif