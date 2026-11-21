# C++ Module 08

> Templated containers, iterators, algorithms.
>
> Subject version 8 · eval sheet from evals-99cf9.web.app

**To pass: ex00 → ex02** (all 3).

---

## General rules (same in every module)

- Compile with `c++ -Wall -Wextra -Werror`. It must still compile with `-std=c++98`.
- Folders `ex00`, `ex01`, ...; classes in UpperCamelCase; class `Foo` lives in `Foo.hpp` / `Foo.cpp`.
- Every output message ends with a newline and goes to stdout (unless the subject says otherwise).
- Forbidden: `*printf`, `*alloc`, `free` → **0** · C++11 / Boost / external libs → **0** · `using namespace`, `friend` → **-42**.
- No memory leaks. Orthodox Canonical Form for every class.
- A function body written in a header = 0 for the exercise (**templates excepted**).
- Every header includes what it needs and has include guards.
- Makefile: `$(NAME)`, `all`, `clean`, `fclean`, `re`, no relinking.

## Module rules

- **The STL is allowed and expected**: containers (`vector`, `list`, `map`...) and algorithms (`<algorithm>`). Use them as much as you can, **otherwise very bad grade even if it works**.
- Templates go in the headers, or declarations in the headers and code in `.tpp` files (headers mandatory, `.tpp` optional).

---

## ex00: Easy find

| | |
|---|---|
| **Files** | `Makefile`, `main.cpp`, `easyfind.{h,hpp}` (+ optional `easyfind.tpp`) |
| **Forbidden** | None |

- Function template `easyfind` on a type `T`, with 2 parameters: a `T` and an `int`.
- `T` is a container of ints: find the **first occurrence** of the int in it.
- Not found → throw an exception or return an error value of your choice.
- Turn in tests. Associative containers don't need handling.

## ex01: Span

| | |
|---|---|
| **Files** | `Makefile`, `main.cpp`, `Span.{h,hpp}`, `Span.cpp` |
| **Forbidden** | None |

- `Span` stores **at most N ints**; `unsigned int N` is the only constructor parameter.
- `addNumber()` adds one number; adding when N are already stored → **exception**.
- `shortestSpan()` and `longestSpan()` return the smallest / largest distance between stored numbers. 0 or 1 number → **exception**.
- Write your own, more thorough tests. **Test with at least 10 000 numbers.**
- Add a member function that adds **many numbers in one call** (e.g. from a range of iterators).

Subject's test: `Span sp(5)` with `6 3 17 9 11` → shortest `2`, longest `14`.

## ex02: Mutated abomination

| | |
|---|---|
| **Files** | `Makefile`, `main.cpp`, `MutantStack.{h,hpp}` (+ optional `MutantStack.tpp`) |
| **Forbidden** | None |

- `std::stack` is not iterable. Write `MutantStack`, **implemented in terms of a `std::stack`**, offering all its member functions **plus iterators**.
- Turn in your own tests.
- The subject's main run once with `MutantStack` and once with `std::list` (`push` → `push_back`...) must give the **same output**.

---

## Evaluation checklist

### Preliminary (any failure stops the grading)
- [ ] Compiles with `c++ -Wall -Wextra -Werror` (C++98)
- [ ] No non-template function body in a header → otherwise the exercise isn't graded
- [ ] The Makefile uses `c++` and the required flags
- [ ] No `*alloc`, `*printf`, `free`, `using namespace`, `friend`, C++11, external lib → **Forbidden function** flag
- [ ] Each exercise has a main with enough tests and canonical-form classes, **otherwise it isn't graded**

### ex00
- [ ] A template function `easyfind(T, int)` that does what the subject asks
- [ ] It **uses an STL algorithm** (a hand-written loop with iterators = wrong)

### ex01
- [ ] A class that follows the subject's constraints
- [ ] Member functions use STL algorithms as much as possible; the shortest span is not just "the two lowest numbers"
- [ ] A better way to add numbers than calling `addNumber()` repeatedly

### ex02
- [ ] `MutantStack` inherits from `std::stack` and offers all its member functions
- [ ] It has an iterator; at least the subject's operations work with it
- [ ] **A main with more tests than the subject's**
