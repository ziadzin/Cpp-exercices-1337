# Module 08 — evaluation check

**Result: the evaluation does not pass as it stands.** 3 problems.

## Blocking

1. **ex02 does not build.** `main.cpp` is empty (0 bytes), so `make` fails at link:
   `undefined reference to 'main'`.
   Per the guidelines this is the "non-functioning program" flag, which ends the
   evaluation with a final grade of 0 — not just a 0 on ex02.

## Loses points

2. **ex01 — "Improved addNumber function" (15 pts) scores No.**
   The graded item is: *"There's a way to add numbers that's more practical than
   calling the addNumber() function repeatedly."*
   `Span` currently exposes only `addNumber()`, one integer per call.

3. **Not enough tests to grade ex01 and ex02.**
   Every exercise is gated by: *"there has to be enough tests to prove the program
   works as expected. If there isn't, do not grade this exercise."*
   - `ex01/main.cpp` — one normal case only. No throw on full span, no throw on
     fewer than 2 numbers, no 10 000-number test (required by the subject).
   - `ex02/main.cpp` — empty.
   - ex02 additionally has its own 10-pt item: *"a main() that has more tests than
     the ones from the subject."*

## Risk, not a listed criterion

4. **ex01 signed overflow.** `gap()` returns `int` and computes `high - low`.
   `longestSpan()` on `INT_MIN`/`INT_MAX` overflows a signed int — undefined
   behaviour, and the true answer (4 294 967 295) does not fit in the return type.
   A peer who tests the extremes gets a wrong number.

## Verified OK

- Compiles with `c++ -Wall -Wextra -Werror -std=c++98` — ex00, ex01. (ex02 blocked by 1.)
- No `*printf` / `*alloc` / `free`, no `using namespace`, no `friend`, no external
  library, no post-C++98 features.
- No function defined in a header except templates.
- ex00 `easyfind(T, int)` is templated and uses `std::find` — not a manual loop.
- ex01 `shortestSpan()` sorts and takes the minimum adjacent gap — not the two
  lowest numbers. Uses `std::sort`, `std::transform`, `std::min_element`,
  `std::max_element`.
- ex02 `MutantStack` inherits `std::stack`, exposes `iterator`, and the subject's
  example operations compile and run correctly (verified with a scratch main;
  `ex02/main.cpp` untouched).
- No heap allocation anywhere; valgrind on ex01: 0 errors, no leaks.
