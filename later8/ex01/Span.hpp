#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>

class Span
{
	private:
		unsigned int		_maxSize;
		std::vector<int>	_numbers;

	public:
		Span(unsigned int N);
		Span(const Span &other);
		Span	&operator=(const Span &other);
		~Span();

		void	addNumber(int number);
		int		shortestSpan() const;
		int		longestSpan() const;

		template <typename InputIterator>
		void	addNumber(InputIterator first, InputIterator last)
		{
			for (InputIterator it = first; it != last; ++it)
				addNumber(*it);
		}
};

#endif
