# Module 08 · quick review

Compiles, no leaks, STL used everywhere it should be. Two tests are missing.

## 🔴 Fix before pushing
1. **ex02 `main.cpp`**: it's only the subject's main. The sheet has a line **"a main with more tests than the subject's"**. Add a second block: the same pushes on a `std::list<int>` with `push_back` (show the output is identical), plus a copy (`MutantStack<int> copy(mstack);`) that you iterate.
2. **ex01 `main.cpp`**: the subject says **test with at least 10 000 numbers**. Add a block: fill a `std::vector<int>` with 10 000 `rand()` values, `addAll()` them into a `Span(10000)`, print both spans. Also show the exceptions (adding to a full Span, a span on 1 number).

## 🟡 Small risk
- ex01: with `INT_MIN` and `INT_MAX` stored, `longestSpan()` overflows `int` and prints a negative number. Only matters if the evaluator tries it. Fix: compute in `long` and return `long`.

## What your code does
| ex | Remember this |
|---|---|
| ex00 | `template <typename T> typename T::iterator easyfind(T& container, int target)`: `std::find(begin, end, target)`, throws `std::runtime_error` if it returns `end()`. `typename` is needed because `T::iterator` depends on T. |
| ex01 | `unsigned int _N` (max) + `std::vector<int> _veci`. `addNumber` throws `out_of_range` when full. `addAll(vector)` inserts many at once with `insert()`. `shortestSpan`: copy, `std::sort`, `std::transform` computes each neighbour gap, `std::min_element` picks the smallest. `longestSpan`: `max_element - min_element`. Fewer than 2 numbers → `logic_error`. |
| ex02 | `MutantStack<T> : public std::stack<T>`. `std::stack` keeps its real container in a **protected** member `c` (a `std::deque` by default). The class just exposes it: `typedef container_type::iterator iterator;`, `begin()` → `this->c.begin()`, `end()` → `this->c.end()`. Everything is in the header (it's a template). |

## The sheet will ask you
- Why can't you iterate a `std::stack`, and how does inheriting give access to `c`?
- Why sort before finding the shortest span?
