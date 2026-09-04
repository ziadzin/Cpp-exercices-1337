# CPP Module 07 — Evaluation Requirements

## Prerequisites (20 pts)
- Compiles with `c++` and flags `-Wall -Wextra -Werror`
- Must follow C++98 standard (no C++11+ features or containers)
- Auto-fail (do not grade) if:
  - A function is implemented in a header file (except template functions)
  - Makefile doesn't compile with required flags/compiler
- Flag as "Forbidden Function" if:
  - Uses a C function (`*alloc`, `*printf`, `free`)
  - Uses a function not allowed by the exercise guidelines
  - Uses `using namespace <ns>` or `friend`
  - Uses an external library or non-C++98 features

## Exercise 00: Start with a few functions
Write 3 function templates: `swap()`, `min()`, `max()`.

- **Simple types (15 pts):** check output against subject for types like `int`
- **Complex types (15 pts):** check with `ex00.cpp`

## Exercise 01: Iter (30 pts)
Generic function to iterate through arrays. Test with `ex01.cpp`.

Expected output:
```
0
1
2
3
4
42
42
42
42
42
```

## Exercise 02: Array
Class template that behaves like an array.

- Skip grading if the internal allocation doesn't use `new[]`
- Have the student prove it works with both simple and complex types before grading

- **Constructors (10 pts):** can create an empty array and an array of a specific size
- **Access (10 pts):** elements accessible via `operator[]` (read/write, or read-only if const); out-of-range access must throw `std::exception`

## Defense rules
- Any segfault or unexpected/premature termination → grade is 0
- Check for memory leaks (all heap allocations must be freed) using `leaks`, `valgrind`, or `e_fence`

## Attachments

### ex00.cpp
```cpp
class Awesome
{
  public:
    Awesome(void) : _n(0) {}
    Awesome( int n ) : _n( n ) {}
    Awesome & operator= (Awesome & a) { _n = a._n; return *this; }
    bool operator==( Awesome const & rhs ) const { return (this->_n == rhs._n); }
    bool operator!=( Awesome const & rhs ) const{ return (this->_n != rhs._n); }
    bool operator>( Awesome const & rhs ) const { return (this->_n > rhs._n); }
    bool operator<( Awesome const & rhs ) const { return (this->_n < rhs._n); }
    bool operator>=( Awesome const & rhs ) const { return (this->_n >= rhs._n); }
    bool operator<=( Awesome const & rhs ) const { return (this->_n <= rhs._n); }
    int get_n() const { return _n; }
  private:
    int _n;
};
std::ostream & operator<<(std::ostream & o, const Awesome &a) { o << a.get_n(); return o; }

int main(void)
{
	Awesome a(2), b(4);

        swap(a, b);
        std::cout << a << " " << b << std::endl;
        std::cout << max(a, b) << std::endl;
        std::cout << min(a, b) << std::endl;
        return (0);
}
```

### ex01.cpp
```cpp
class Awesome
{
  public:
    Awesome( void ) : _n( 42 ) { return; }
    int get( void ) const { return this->_n; }
  private:
    int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
{
  o << rhs.get();
  return o;
}

template< typename T >
void print( T& x )
{
  std::cout << x << std::endl;
  return;
}

int main() {
  int tab[] = { 0, 1, 2, 3, 4 };
  Awesome tab2[5];

  iter( tab, 5, print<const int> );
  iter( tab2, 5, print<Awesome> );

  return 0;
}
```
