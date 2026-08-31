#include "Span.hpp"
#include <algorithm>
#include <stdexcept>

Span::Span(unsigned int N) : _maxSize(N), _numbers()
{
}

Span::Span(const Span &other) : _maxSize(other._maxSize), _numbers(other._numbers)
{
}

Span	&Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_maxSize = other._maxSize;
		_numbers = other._numbers;
	}
	return (*this);
}

Span::~Span()
{
}

void	Span::addNumber(int number)
{
	if (_numbers.size() >= _maxSize)
		throw std::out_of_range("Span: no space left");
	_numbers.push_back(number);
}

int	Span::shortestSpan() const
{
	if (_numbers.size() < 2)
		throw std::logic_error("Span: not enough numbers stored");

	std::vector<int>			sorted(_numbers);
	std::vector<int>::iterator	it;
	int							shortest;

	std::sort(sorted.begin(), sorted.end());
	shortest = sorted[1] - sorted[0];
	for (it = sorted.begin() + 1; it + 1 != sorted.end(); ++it)
		shortest = std::min(shortest, *(it + 1) - *it);
	return (shortest);
}

int	Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw std::logic_error("Span: not enough numbers stored");

	return (*std::max_element(_numbers.begin(), _numbers.end())
		- *std::min_element(_numbers.begin(), _numbers.end()));
}
