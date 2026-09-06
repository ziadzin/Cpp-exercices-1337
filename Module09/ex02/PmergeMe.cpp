#include "PmergeMe.hpp"
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <stdexcept>
#include <string>
#include <ctime>

PmergeMe::PmergeMe() : _vec(), _deq()
{
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	*this = other;
}

PmergeMe	&PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		_vec = other._vec;
		_deq = other._deq;
	}
	return (*this);
}

PmergeMe::~PmergeMe()
{
}

void	PmergeMe::parse(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
	{
		std::string		arg(argv[i]);
		std::istringstream	iss(arg);
		long			value;

		if (arg.find_first_not_of("0123456789") != std::string::npos)
			throw std::runtime_error("Error");
		iss >> value;
		if (iss.fail() || value > 2147483647L)
			throw std::runtime_error("Error");
		_vec.push_back(static_cast<int>(value));
		_deq.push_back(static_cast<int>(value));
	}
}

void	PmergeMe::sortVector(std::vector<int> &v)
{
	if (v.size() < 2)
		return ;

	std::vector<int>	chain;
	std::vector<int>	pend;
	size_t			prev = 1;
	size_t			curr = 3;

	for (size_t i = 0; i < v.size(); i += 2)
	{
		if (i + 1 == v.size())
			pend.push_back(v[i]);
		else if (v[i] < v[i + 1])
		{
			chain.push_back(v[i + 1]);
			pend.push_back(v[i]);
		}
		else
		{
			chain.push_back(v[i]);
			pend.push_back(v[i + 1]);
		}
	}
	sortVector(chain);
	chain.insert(std::upper_bound(chain.begin(), chain.end(), pend[0]), pend[0]);
	while (prev < pend.size())
	{
		size_t	k = std::min(curr, pend.size());

		while (k > prev)
		{
			chain.insert(std::upper_bound(chain.begin(), chain.end(), pend[k - 1]), pend[k - 1]);
			k--;
		}
		curr = curr + 2 * prev;
		prev = curr - 2 * prev;
	}
	v = chain;
}

void	PmergeMe::sortDeque(std::deque<int> &d)
{
	if (d.size() < 2)
		return ;

	std::deque<int>	chain;
	std::deque<int>	pend;
	size_t		prev = 1;
	size_t		curr = 3;

	for (size_t i = 0; i < d.size(); i += 2)
	{
		if (i + 1 == d.size())
			pend.push_back(d[i]);
		else if (d[i] < d[i + 1])
		{
			chain.push_back(d[i + 1]);
			pend.push_back(d[i]);
		}
		else
		{
			chain.push_back(d[i]);
			pend.push_back(d[i + 1]);
		}
	}
	sortDeque(chain);
	chain.insert(std::upper_bound(chain.begin(), chain.end(), pend[0]), pend[0]);
	while (prev < pend.size())
	{
		size_t	k = std::min(curr, pend.size());

		while (k > prev)
		{
			chain.insert(std::upper_bound(chain.begin(), chain.end(), pend[k - 1]), pend[k - 1]);
			k--;
		}
		curr = curr + 2 * prev;
		prev = curr - 2 * prev;
	}
	d = chain;
}

void	PmergeMe::run()
{
	std::clock_t	start;
	double		vecTime;
	double		deqTime;

	std::cout << "Before:";
	for (size_t i = 0; i < _vec.size(); i++)
		std::cout << " " << _vec[i];
	std::cout << std::endl;

	start = std::clock();
	sortVector(_vec);
	vecTime = static_cast<double>(std::clock() - start) * 1000000.0 / CLOCKS_PER_SEC;

	start = std::clock();
	sortDeque(_deq);
	deqTime = static_cast<double>(std::clock() - start) * 1000000.0 / CLOCKS_PER_SEC;

	std::cout << "After:";
	for (size_t i = 0; i < _vec.size(); i++)
		std::cout << " " << _vec[i];
	std::cout << std::endl;

	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Time to process a range of " << _vec.size()
		<< " elements with std::vector : " << vecTime << " us" << std::endl;
	std::cout << "Time to process a range of " << _deq.size()
		<< " elements with std::deque : " << deqTime << " us" << std::endl;
}
