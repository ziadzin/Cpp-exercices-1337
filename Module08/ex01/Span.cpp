#include "Span.hpp"
#include <algorithm>

static int	gap(int high, int low)
{
	return high - low;
}

Span::Span() : _N(0), _veci()
{
}

Span::Span(unsigned int size) : _N(size), _veci()
{
}

Span::Span(const Span &other)
{
	*this = other;
}

Span	&Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_N = other._N;
		_veci = other._veci;
	}
	return (*this);
}

Span::~Span()
{
}

void	Span::addNumber(int number)
{
	if (_veci.size() >= _N)
		throw std::out_of_range("Span: no space left");
	_veci.push_back(number);
}

int	Span::shortestSpan() const
{
	if (_veci.size() < 2)
		throw std::logic_error("Span: needs at least two numbers");

	std::vector<int>	sorted(_veci);
	std::vector<int>	gaps(_veci.size() - 1);

	std::sort(sorted.begin(), sorted.end());
	std::transform(sorted.begin() + 1, sorted.end(), sorted.begin(), gaps.begin(), gap);
	return (*std::min_element(gaps.begin(), gaps.end()));
}

int	Span::longestSpan() const
{
	if (_veci.size() < 2)
		throw std::logic_error("Span: needs at least two numbers");

	return (gap(*std::max_element(_veci.begin(), _veci.end()), *std::min_element(_veci.begin(), _veci.end())));
}
