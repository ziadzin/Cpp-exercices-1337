# C++ Module 09

> STL.
>
> Subject version 2 · eval sheet from evals-99cf9.web.app

**To pass: ex00 → ex02** (all 3).

---

## General rules (same in every module)

- Compile with `c++ -Wall -Wextra -Werror`. It must still compile with `-std=c++98`.
- Folders `ex00`, `ex01`, ...; classes in UpperCamelCase; class `Foo` lives in `Foo.hpp` / `Foo.cpp`.
- Every output message ends with a newline and goes to stdout (unless the subject says otherwise).
- Forbidden: `*printf`, `*alloc`, `free` → **0** · C++11 / Boost / external libs → **0** · `using namespace`, `friend` → **-42**.
- No memory leaks. Orthodox Canonical Form for every class.
- **A function body written in a header = 0 for the exercise** (templates excepted).
- Every header includes what it needs and has include guards.
- Makefile: `$(NAME)`, `all`, `clean`, `fclean`, `re`, no relinking.

## Module rules

- Every exercise **must use standard containers**: at least 1 in ex00 and ex01, **at least 2 in ex02**.
- **Once a container is used, it can't be used again in the rest of the module.**

---

## ex00: Bitcoin Exchange

| | |
|---|---|
| **Files** | `Makefile`, `main.cpp`, `BitcoinExchange.{cpp,hpp}` |
| **Forbidden** | None |

- Program `btc`: outputs the value of an amount of bitcoin on a given date.
- Uses a csv database of bitcoin prices over time, **provided with the subject** (`data.csv`).
- Takes a file as argument; each line is `date | value`.
- Valid date: `Year-Month-Day`. Valid value: a float or a positive integer **between 0 and 1000**.
- Prints `value × exchange rate` for that date. **If the date isn't in the DB, use the closest *lower* date.**
- Handle errors with an appropriate message.

```text
$> ./btc
Error: could not open file.
$> ./btc input.txt
2011-01-03 => 3 = 0.9
2011-01-03 => 2 = 0.6
2011-01-03 => 1 = 0.3
2011-01-03 => 1.2 = 0.36
2011-01-09 => 1 = 0.32
Error: not a positive number.
Error: bad input => 2001-42-42
2012-01-11 => 1 = 7.1
Error: too large a number.
```

## ex01: Reverse Polish Notation

| | |
|---|---|
| **Files** | `Makefile`, `main.cpp`, `RPN.{cpp,hpp}` |
| **Forbidden** | None |

- Program `RPN`: takes an inverted Polish expression as **one argument**.
- Numbers in the expression are always **< 10** (results and intermediate values can be bigger).
- Prints the result; on error prints an error message.
- Tokens: `+ - / *`. No brackets, no decimals.

```text
$> ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
42
$> ./RPN "7 7 * 7 -"
42
$> ./RPN "1 2 * 2 / 2 * 2 4 - +"
0
$> ./RPN "(1 + 1)"
Error
```

## ex02: PmergeMe

| | |
|---|---|
| **Files** | `Makefile`, `main.cpp`, `PmergeMe.{cpp,hpp}` |
| **Forbidden** | None |

- Program `PmergeMe`: takes a sequence of positive integers as arguments.
- Sorts it with the **merge-insert sort, i.e. the Ford-Johnson algorithm**.
- Uses **at least 2 different containers**; handles at least **3000** integers. Implement the algorithm once per container (no generic function).
- Output, line by line: `Before:` + unsorted sequence; `After:` + sorted sequence; time with the 1st container; time with the 2nd container. The time precision must show the difference.
- On error, print an error message. Duplicates: up to you.

```text
$> ./PmergeMe 3 5 9 7 4
Before: 3 5 9 7 4
After: 3 4 5 7 9
Time to process a range of 5 elements with std::[..] : 0.00031 us
Time to process a range of 5 elements with std::[..] : 0.00014 us
$> ./PmergeMe "-1" "2"
Error
```

---

## Evaluation checklist

### Preliminary (any failure stops the grading)
- [ ] Compiles with `c++ -Wall -Wextra -Werror` (C++98)
- [ ] No function body in a header (templates excepted) → otherwise the exercise isn't graded
- [ ] The Makefile uses `c++` and the required flags
- [ ] No `*alloc`, `*printf`, `free`, C++11, external lib → **Forbidden function** flag

### ex00
- [ ] Makefile with the usual rules; the code uses at least one container
- [ ] **The student explains why this container** and not another (otherwise the evaluation stops)
- [ ] An empty file and a file with errors work; the program goes through the **whole file** without stopping
- [ ] A wrong date, a value > 1000 and a value < 0 are handled
- [ ] With the sheet's `input.csv`, compare some dates by hand with the DB; a missing date uses the **nearest lower** date

### ex01
- [ ] Makefile with the usual rules; at least one container, **not the one from ex00**
- [ ] The student explains the container choice
- [ ] Works with different formulas. Sheet tests:
  - `8 9 * 9 - 9 - 9 - 4 - 1 +` → `42`
  - `9 8 * 4 * 4 / 2 + 9 - 8 - 8 - 1 - 6 -` → `42`
  - `1 2 * 2 / 2 + 5 * 6 - 1 3 * - 4 5 * * 8 /` → `15`

### ex02
- [ ] Enough tests, canonical classes
- [ ] At least 2 containers, **none used in ex00 or ex01**; the student explains the choice
- [ ] The merge-insert (Ford-Johnson) sort is in the code and used for each container; **a brief explanation is expected**
- [ ] 5 to 10 positive integers give a sorted sequence
- [ ] `shuf -i 1-1000 -n 3000 | tr "\n" " "` as arguments works; the student explains the time difference between the containers
