# C++ Module 02

> Ad-hoc polymorphism, operator overloading and the Orthodox Canonical class form.
>
> Subject version 8 · eval sheet from evals-99cf9.web.app (translated from French)

**To pass: ex00 → ex02.** ex03 (BSP) is optional (the subject says: *"You can pass this module without doing exercise 03"*).

---

## General rules (same in every module)

- Compile with `c++ -Wall -Wextra -Werror`. It must still compile with `-std=c++98`.
- Folders `ex00`, `ex01`, ...; classes in UpperCamelCase; class `Foo` lives in `Foo.hpp` / `Foo.cpp`.
- Every output message ends with a newline and goes to stdout (unless the subject says otherwise).
- Forbidden: `*printf`, `*alloc`, `free` → **0** · C++11 / Boost / external libs → **0** · `using namespace`, `friend` → **-42** · STL containers / `<algorithm>` before Module 08 → **-42**.
- No memory leaks.
- **A function body written in a header = 0 for the exercise** (templates excepted).
- Every header includes what it needs and has include guards.
- Makefile: `$(NAME)`, `all`, `clean`, `fclean`, `re`, no relinking.

## New rule from this module on: Orthodox Canonical Form

Every class has: default constructor, copy constructor, copy assignment operator, destructor. Class definition in the `.hpp`, implementation in the `.cpp`.

---

## ex00: My First Class in Orthodox Canonical Form

| | |
|---|---|
| **Files** | `Makefile`, `main.cpp`, `Fixed.{h,hpp}`, `Fixed.cpp` |
| **Forbidden** | None |

A fixed-point number class:
- Private: an `int` for the raw value, a `static const int` for the number of fractional bits, always **8**.
- Public: default constructor (value = 0), copy constructor, copy assignment operator, destructor,
  `int getRawBits(void) const;`, `void setRawBits(int const raw);`.

Running the subject's main (`Fixed a; Fixed b(a); Fixed c; c = b;` then print the 3 raw values) prints:

```text
Default constructor called
Copy constructor called
Copy assignment operator called
getRawBits member function called
Default constructor called
Copy assignment operator called
getRawBits member function called
getRawBits member function called
0
getRawBits member function called
0
getRawBits member function called
0
Destructor called
Destructor called
Destructor called
```

## ex01: Towards a more useful fixed-point number class

| | |
|---|---|
| **Files** | `Makefile`, `main.cpp`, `Fixed.{h,hpp}`, `Fixed.cpp` |
| **Allowed** | `roundf` (from `<cmath>`) |

Add:
- A constructor taking a `const int` → converts to fixed point.
- A constructor taking a `const float` → converts to fixed point.
- `float toFloat(void) const;` and `int toInt(void) const;`
- An overload of `<<` that inserts the float value into the stream.

The subject's main prints (constructor messages removed here):

```text
a is 1234.43
b is 10
c is 42.4219
d is 10
a is 1234 as integer
b is 10 as integer
c is 42 as integer
d is 10 as integer
```

## ex02: Now we're talking

| | |
|---|---|
| **Files** | `Makefile`, `main.cpp`, `Fixed.{h,hpp}`, `Fixed.cpp` |
| **Allowed** | `roundf` (from `<cmath>`) |

Add public member operators:
- The 6 comparisons: `>`, `<`, `>=`, `<=`, `==`, `!=`
- The 4 arithmetic ones: `+`, `-`, `*`, `/`
- The 4 increment/decrement ones (pre/post `++` and `--`), changing the value by the smallest step ϵ (`1 + ϵ > 1`)
- Static `min` and `max`, each in 2 versions: with references and with const references.

The subject's main prints:

```text
0
0.00390625
0.00390625
0.00390625
0.0078125
10.1016
10.1016
```

Division by 0 may crash, that's accepted.

## ex03: BSP (optional, skipped)

Not needed to pass.

---

## Evaluation checklist

### Preliminary (any failure stops the grading)
- [ ] Compiles with `c++ -Wall -Wextra -Werror` (C++98)
- [ ] No function body in a header (templates excepted) → otherwise the exercise isn't graded
- [ ] The Makefile uses `c++` and the required flags
- [ ] No `*alloc`, `*printf`, `free`, `using namespace`, `friend`, C++11, external lib → **Forbidden function** flag

### ex00
- [ ] Makefile with the right flags
- [ ] `getRawBits()` and `setRawBits()` present and working
- [ ] Canonical form: default constructor, destructor, copy constructor, assignment operator, all working

### ex01
- [ ] Can build an instance from a float
- [ ] `<<` operator present and working
- [ ] `int toInt(void) const` present and working
- [ ] `float toFloat(void) const` present and working
- [ ] Can build an instance from an int

### ex02
- [ ] The 6 comparison operators present and working
- [ ] The 4 arithmetic operators present and working (a crash on division by 0 is accepted)
- [ ] The 4 increment/decrement operators present and working
- [ ] Static `min()` and `max()` present and working
