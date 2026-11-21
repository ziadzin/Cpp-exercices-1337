# C++ Module 06

> C++ casts.
>
> Subject version 6.2 · eval sheet from evals-99cf9.web.app

**To pass: ex00 → ex02** (all 3).

---

## General rules (same in every module)

- Compile with `c++ -Wall -Wextra -Werror`. It must still compile with `-std=c++98`.
- Folders `ex00`, `ex01`, ...; classes in UpperCamelCase; class `Foo` lives in `Foo.hpp` / `Foo.cpp`.
- Every output message ends with a newline and goes to stdout (unless the subject says otherwise).
- Forbidden: `*printf`, `*alloc`, `free` → **0** · C++11 / Boost / external libs → **0** · `using namespace`, `friend` → **-42** · STL containers / `<algorithm>` before Module 08 → **-42**.
- No memory leaks. Orthodox Canonical Form for every class (unless the subject says otherwise).
- **A function body written in a header = 0 for the exercise** (templates excepted).
- Every header includes what it needs and has include guards.
- Makefile: `$(NAME)`, `all`, `clean`, `fclean`, `re`, no relinking.

## Module rule

**Each exercise is solved with one specific type of cast.** Your choice is checked during the defense.

---

## ex00: Conversion of scalar types

| | |
|---|---|
| **Files** | `Makefile`, `*.cpp`, `*.{h,hpp}` |
| **Allowed** | Any function converting a string to int / float / double |

- Class `ScalarConverter` with **one static method `convert`**, taking the string form of a C++ literal. It prints the value as `char`, `int`, `float` and `double`.
- The class stores nothing, so it **must not be instantiable**.
- Only decimal notation (except chars).
- Char literals: `c`, `a`, ... Non-displayable chars aren't used as input; if a converted char isn't displayable, print an informative message.
- Int literals: `0`, `-42`, `42`...
- Float literals: `0.0f`, `-4.2f`, `4.2f`... plus the pseudo-literals `-inff`, `+inff`, `nanf`.
- Double literals: `0.0`, `-4.2`, `4.2`... plus `-inf`, `+inf`, `nan`.
- Detect the literal's type, convert it to that type, then **explicitly** to the 3 others.
- A conversion that makes no sense or overflows → say it's impossible.

```text
./convert 0          ./convert nan            ./convert 42.0f
char: Non displayable char: impossible        char: '*'
int: 0               int: impossible          int: 42
float: 0.0f          float: nanf              float: 42.0f
double: 0.0          double: nan              double: 42.0
```

## ex01: Serialization

| | |
|---|---|
| **Files** | `Makefile`, `*.cpp`, `*.{h,hpp}` |
| **Forbidden** | None |

- Class `Serializer`, **not instantiable** in any way, with static methods:
  - `uintptr_t serialize(Data* ptr);` pointer → `uintptr_t`
  - `Data* deserialize(uintptr_t raw);` `uintptr_t` → pointer to `Data`
- Create a **non-empty** `Data` struct (it has data members) and turn in its files.
- Test: `serialize()` the address of a `Data`, pass the result to `deserialize()`, and **check it compares equal to the original pointer**.

## ex02: Identify real type

| | |
|---|---|
| **Files** | `Makefile`, `*.cpp`, `*.{h,hpp}` |
| **Forbidden** | `std::typeinfo` (the `<typeinfo>` header is forbidden) |

- `Base` with **only a public virtual destructor**. Empty classes `A`, `B`, `C` inherit publicly from it. These 4 don't need canonical form.
- `Base* generate(void);` randomly creates an `A`, `B` or `C` and returns it as `Base*`.
- `void identify(Base* p);` prints `"A"`, `"B"` or `"C"`.
- `void identify(Base& p);` same, but **using a pointer inside this function is forbidden**.
- Test it.

---

## Evaluation checklist

### Preliminary (any failure stops the grading)
- [ ] Compiles with `c++ -Wall -Wextra -Werror` (C++98)
- [ ] No function body in a header (templates excepted) → otherwise the exercise isn't graded
- [ ] The Makefile uses `c++` and the required flags
- [ ] No `*alloc`, `*printf`, `free`, `using namespace`, `friend`, C++11, external lib → **Forbidden function** flag

### ex00 (about `static_cast`)
- [ ] A class with a private constructor and static methods
- [ ] Uses `static_cast` to convert values (implicit casts accepted only for promotions)
- [ ] Works as required (don't be too strict on the exact output if the spirit is respected)

### ex01 (about `reinterpret_cast`)
- [ ] Works as required; class with a private constructor and static methods
- [ ] `reinterpret_cast` used twice: `Data*` → `uintptr_t`, then `uintptr_t` → `Data*`
- [ ] **The resulting Data struct is usable**

### ex02 (about `dynamic_cast`)
- [ ] Works as required, uses `dynamic_cast` to identify the type
- [ ] `identify(Base* p)` checks if the cast returns NULL
- [ ] `identify(Base& p)` uses try/catch to see if the cast failed
- [ ] `<typeinfo>` appears nowhere
