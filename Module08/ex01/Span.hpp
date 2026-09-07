#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <iterator>

class Span
{
	private:
		unsigned int		_N;
		std::vector<int>	_veci;

	public:
		Span();
		Span(unsigned int N);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();

		void	addNumber(int number);
		void	addAll(const std::vector<int>& nums);
		int		shortestSpan() const;
		int		longestSpan() const;
};

#endif
