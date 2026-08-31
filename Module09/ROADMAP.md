# C++ Module 09 — STL — Roadmap

Scope is exactly what `en.subject.pdf` asks for. Nothing extra.

## 0. The one constraint that drives everything

> "Once a container is used you cannot use it for the rest of the module."
> ex00 and ex01 need **≥1** container each. ex02 needs **≥2 different** ones.

Decide the budget **before** writing a line, because a wrong pick in ex00 forces a rewrite in ex02.

| Exercise | Container(s) | Why |
| --- | --- | --- |
| ex00 | `std::map<std::string, double>` | Ordered by date, `lower_bound` gives the "closest lower date" for free |
| ex01 | `std::stack<int, std::list<int> >` | RPN is a stack, literally |
| ex02 | `std::vector<int>` + `std::deque<int>` | Both random-access → the Ford-Johnson code is near-identical twice |

Note on ex01: plain `std::stack<int>` defaults to a `std::deque` underneath, which a picky evaluator can call "deque already used" once ex02 uses deque. Passing `std::list` as the underlying container costs one template argument and removes the argument entirely.

Alternative if you'd rather write `std::stack<int>`: ex02 becomes `vector` + `list`. Costs more work — binary insertion on a list has no random access.

## 1. Global rules (apply to all three)

- C++98, compiled with `c++ -Wall -Wextra -Werror`. Makefile must not relink. Rules: `$(NAME) all clean fclean re`. ✅ already written.
- Every class in **Orthodox Canonical Form**: default ctor, copy ctor, `operator=`, destructor. Yes, even for `RPN` and `PmergeMe` where they are useless. Declare all four, define all four.
- **No function bodies in headers** (templates excepted) → instant 0.
- Include guards in every `.hpp`. Headers self-sufficient (include their own dependencies).
- No `using namespace`, no `friend` → −42.
- No `*printf()`, no `*alloc()`, no `free()` → 0.
- Errors on stdout unless the exercise says stderr (ex01 and ex02 say **stderr**).

## 2. Files

```
ex00/  Makefile  main.cpp  BitcoinExchange.cpp  BitcoinExchange.hpp   + data.csv
ex01/  Makefile  main.cpp  RPN.cpp              RPN.hpp
ex02/  Makefile  main.cpp  PmergeMe.cpp         PmergeMe.hpp
```

⚠️ **`data.csv` is missing.** The subject says the database "is provided with this subject" — it ships alongside the PDF on the intranet, it is not in this repo. Download it before starting ex00. Format: header `date,exchange_rate`, then `YYYY-MM-DD,<float>` lines.

You will also want a hand-made `input.txt` for testing — not a submitted file, just build the one from the subject's example.

## 3. ex00 — Bitcoin Exchange · binary `btc` · ~3h

Reads `data.csv` into a map, then streams the input file line by line and prints `date => value = value*rate`.

**Flow**
1. `main`: exactly one argument, else `Error: could not open file.` (that is the message the subject shows for `./btc` with no args too).
2. Load `data.csv` into `std::map<std::string, double>`. Skip its header line. Fail loudly if it can't be opened.
3. Open `argv[1]`, skip the header line `date | value`, then per line:
   - split on `" | "`; malformed → `Error: bad input => <the line>`
   - validate the date: `YYYY-MM-DD` shape **and** a real calendar date (`2001-42-42` must fail) → `Error: bad input => 2001-42-42`
   - validate the value → `Error: not a positive number.` if `< 0`, `Error: too large a number.` if `> 1000`
   - look up the rate, print `2011-01-03 => 3 = 0.9`

**Traps**
- The lookup is `lower_bound(date)`: if it returns `end()` or a key `> date`, step the iterator **back one** — the subject insists on the *lower* date. If it's already `begin()` and still greater, the date predates the DB → that's an error case.
- `2147483648` overflows `int`. Parse into a `double` (`std::strtod` or a `std::stringstream`) *before* range-checking, or you'll wrap around and print a result.
- Errors do not abort the program — print and continue to the next line.
- Default `std::cout` formatting already prints `3` as `3` and `1.2` as `1.2`, and `1.2 * 0.3` as `0.36`. Don't touch precision.
- Dates are `YYYY-MM-DD`, so plain `std::string` comparison is chronological. No date arithmetic needed.

**Done when**
```
./btc                 → Error: could not open file.
./btc input.txt       → matches the subject output line for line
```

## 4. ex01 — RPN · binary `RPN` · ~1h

Smallest exercise. Do it first if you want a fast win.

**Flow**
1. `main`: exactly one argument, else error.
2. Walk `argv[1]` token by token (a `std::stringstream >> std::string` loop is enough).
   - single digit `0`–`9` → push
   - `+ - * /` → need ≥2 operands, pop `b`, pop `a`, push `a op b` (order matters for `-` and `/`)
   - anything else → error
3. End: stack must hold **exactly one** value. Print it. More or fewer → error.

**Traps**
- Operand order: `a` is the *second* pop.
- Division by zero → error, don't crash.
- Numbers are `< 10` **on input only**; intermediate results and the final answer are not bounded, so keep them in `int`.
- `"(1 + 1)"` must print `Error` — the parens are just unknown tokens, so rule 2's "anything else" covers it.
- Error text goes to **stderr**; the subject shows plain `Error`.

**Done when** the four subject examples reproduce exactly (`42`, `42`, `0`, `Error`).

## 5. ex02 — PmergeMe · binary `PmergeMe` · ~6h

The real work. Ford-Johnson (merge-insertion), implemented **twice** — once per container, no generic function (the subject explicitly advises against a template here).

**Flow**
1. Parse `argv[1..n]`: every token must be a **positive integer**. Reject `-1`, non-digits, and overflow → `Error` on stderr. Duplicates: your call, the subject leaves it free.
2. Fill the `vector`, print `Before: ...`.
3. Sort the `vector`, time it. Sort the `deque`, time it.
4. Print `After: ...`, then two timing lines naming each container.

**Ford-Johnson, per container**
1. Pair up adjacent elements; inside each pair order them (bigger, smaller). Odd element out → set aside as a straggler.
2. Recurse on the pairs, sorting them by their **bigger** element.
3. `main` chain = the bigger elements, now sorted. `pend` = each pair's smaller element, kept associated with its partner.
4. `pend[0]` is smaller than `main[0]` by construction → insert it at the front, no search.
5. Insert the rest in **Jacobsthal order** (`0,1,1,3,5,11,21,43,85,171,341,683,1365,2731…`): for each group take indices from `J(k)` down to `J(k-1)+1`, and binary-search each into `main` — bounded above by the position of its already-placed partner, which is the whole point of the algorithm.
6. Binary-insert the straggler last, if there was one.

**Traps**
- Timing: no `<chrono>` in C++98. Use `clock()` from `<ctime>` or `gettimeofday()`. Report in **µs** and clock the *whole* job — parsing/copying into the container included, not just the sort call. Precision must be high enough to see the two containers differ.
- 3000 elements is the floor. Test with `./PmergeMe $(shuf -i 1-100000 -n 3000 | tr "\n" " ")` and verify sortedness, not just that it doesn't crash.
- Recursion depth at 3000 elements is ~12 levels. Fine.
- The two implementations differ only in the container type — write the vector one, get it correct, then port. Resist merging them into a template afterwards.
- Don't `#include <algorithm>`'s `std::sort` anywhere. That's the whole exercise.

**Done when**
```
./PmergeMe 3 5 9 7 4        → Before / After / two timings
./PmergeMe "-1" "2"         → Error
./PmergeMe $(shuf -i 1-100000 -n 3000 | tr "\n" " ")  → sorted, both timings shown
```

## 6. Suggested order

`ex01` (fast confidence build) → `ex00` (moderate, mostly parsing) → `ex02` (the algorithm).

Order doesn't actually matter — **as long as section 0's container budget is locked in first.**

## 7. Pre-defense checklist

- [ ] `make && make` → second run says "nothing to be done" (no relink), in all three dirs
- [ ] `make fclean` leaves the directory clean
- [ ] Compiles clean with `-Wall -Wextra -Werror -std=c++98`
- [ ] Each class is OCF, all four members defined in the `.cpp`
- [ ] No implementation in any `.hpp`, include guards everywhere
- [ ] Zero container reuse across ex00 / ex01 / ex02
- [ ] `valgrind` clean on all three
- [ ] `data.csv` committed with ex00
