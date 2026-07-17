#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <exception>

template <typename T>
class Array
{
  public:
	Array();
	Array(unsigned int n);
	Array(const Array &other);
	Array &operator=(const Array &other);
	~Array();

	// --- Element access ---
	T &operator[](unsigned int index);             // read/write
	const T &operator[](unsigned int index) const; // read-only

	// --- Capacity ---
	unsigned int size() const;            // element count, does not modify

	// --- Exception thrown on out-of-bounds access ---
	class OutOfBounds : public std::exception
	{
	  public:
		const char *what() const throw();
	};

  private:
	T           *_data;
	unsigned int _size;
};

#include "Array.tpp"  // template definitions live here

#endif
