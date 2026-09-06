#ifndef EASYFIND_HPP 
#define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T& container, int target)
{
    typename T::iterator it = std::find(container.begin(), container.end(), target);
	if (it == container.end())
		throw std::runtime_error("easyfind: value not found in container");
	return (it); 
}

#endif
