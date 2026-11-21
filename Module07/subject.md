# C++ Module 07

> C++ templates.
>
> Subject version 7 · eval sheet from evals-99cf9.web.app

**To pass: ex00 → ex02** (all 3).

---

## General rules (same in every module)

- Compile with `c++ -Wall -Wextra -Werror`. It must still compile with `-std=c++98`.
- Folders `ex00`, `ex01`, ...; classes in UpperCamelCase; class `Foo` lives in `Foo.hpp` / `Foo.cpp` (or `Foo.tpp`).
- Every output message ends with a newline and goes to stdout (unless the subject says otherwise).
- Forbidden: `*printf`, `*alloc`, `free` → **0** · C++11 / Boost / external libs → **0** · `using namespace`, `friend` → **-42** · STL containers / `<algorithm>` before Module 08 → **-42**.
- No memory leaks. Orthodox Canonical Form for every class.
- A function body written in a header = 0 for the exercise, **except templates** (they must be in headers here).
- Every header includes what it needs and has include guards.
- Makefile: `$(NAME)`, `all`, `clean`, `fclean`, `re`, no relinking.

---

## ex00: Start with a few functions

| | |
|---|---|
| **Files** | `Makefile`, `main.cpp`, `whatever.{h,hpp}` |
| **Forbidden** | None |

Function templates:
- `swap`: swaps two values, returns nothing.
- `min`: returns the smallest; **if equal, returns the second**.
- `max`: returns the greatest; **if equal, returns the second**.

They work with any type whose two arguments have the same type and support all comparison operators. **Templates are defined in the header.**

The subject's main (ints `2`/`3`, then strings `"chaine1"`/`"chaine2"`) must print:

```text
a = 3, b = 2
min(a, b) = 2
max(a, b) = 3
c = chaine2, d = chaine1
min(c, d) = chaine1
max(c, d) = chaine2
```

## ex01: Iter

| | |
|---|---|
| **Files** | `Makefile`, `main.cpp`, `iter.{h,hpp}` |
| **Forbidden** | None |

- Function template `iter` with 3 parameters, returns nothing: the **address of an array**, its **length**, a **function called on every element**.
- Works with any type of array. The 3rd parameter can be an instantiated function template.
- Turn in a `main.cpp` with your tests.

## ex02: Array

| | |
|---|---|
| **Files** | `Makefile`, `main.cpp`, `Array.{h,hpp}` (+ optional `Array.tpp`) |
| **Forbidden** | None |

Class template `Array<T>`:
- No parameter → empty array.
- `unsigned int n` → array of n elements **initialized by default** (tip: `int *a = new int(); std::cout << *a;`).
- Copy constructor and assignment: changing the original or the copy afterwards must **not** affect the other.
- **Must use `new[]`.** No preventive allocation. Never access unallocated memory.
- Elements accessed with `[ ]`; an out-of-bounds index **throws an `std::exception`**.
- `size()`: returns the number of elements, takes no parameter, doesn't modify the instance.
- Turn in a `main.cpp` with your tests.

---

## Evaluation checklist

### Preliminary (any failure stops the grading)
- [ ] Compiles with `c++ -Wall -Wextra -Werror` (C++98)
- [ ] No non-template function body in a header → otherwise the exercise isn't graded
- [ ] The Makefile uses `c++` and the required flags
- [ ] No `*alloc`, `*printf`, `free`, `using namespace`, `friend`, C++11, external lib → **Forbidden function** flag

### ex00
- [ ] Simple types (int...) give the subject's output
- [ ] Also works with complex types: the evaluator runs the sheet's `ex00.cpp` (a class `Awesome` with comparison operators)

### ex01
- [ ] The evaluator runs the sheet's `ex01.cpp` with your `iter`. It must print `0 1 2 3 4` then `42` five times (one per line)

### ex02
- [ ] The inner array is allocated with `new[]`, **otherwise not graded**
- [ ] The student proves it works with simple and complex types
- [ ] Can create an empty array and an array of a given size
- [ ] Elements readable/writable with `operator[]` (read-only on a const instance); out of range throws an `std::exception`
