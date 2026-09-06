#include "RPN.hpp"
#include <sstream>
#include <stdexcept>

RPN::RPN() : _stack()
{
}

RPN::RPN(const RPN &other)
{
	*this = other;
}

RPN	&RPN::operator=(const RPN &other)
{
	if (this != &other)
		_stack = other._stack;
	return (*this);
}

RPN::~RPN()
{
}

int	RPN::evaluate(const std::string &expression)
{
	std::istringstream	iss(expression);
	std::string		token;

	while (iss >> token)
	{
		if (token.size() != 1)
			throw std::runtime_error("Error");
		if (token[0] >= '0' && token[0] <= '9')
			_stack.push(token[0] - '0');
		else
		{
			if (_stack.size() < 2 || std::string("+-*/").find(token[0]) == std::string::npos)
				throw std::runtime_error("Error");

			int	b = _stack.top();
			_stack.pop();
			int	a = _stack.top();
			_stack.pop();
			if (token[0] == '+')
				_stack.push(a + b);
			else if (token[0] == '-')
				_stack.push(a - b);
			else if (token[0] == '*')
				_stack.push(a * b);
			else if (b == 0)
				throw std::runtime_error("Error");
			else
				_stack.push(a / b);
		}
	}
	if (_stack.size() != 1)
		throw std::runtime_error("Error");
	return (_stack.top());
}
