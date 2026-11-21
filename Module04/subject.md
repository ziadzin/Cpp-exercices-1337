# C++ Module 04

> Subtype polymorphism, abstract classes, interfaces.
>
> Subject version 11 · eval sheet from evals-99cf9.web.app

**To pass: ex00 → ex02.** ex03 (Interface & recap) is optional (the subject says: *"You can pass this module without doing exercise 03"*).

---

## General rules (same in every module)

- Compile with `c++ -Wall -Wextra -Werror`. It must still compile with `-std=c++98`.
- Folders `ex00`, `ex01`, ...; classes in UpperCamelCase; class `Foo` lives in `Foo.hpp` / `Foo.cpp`.
- Every output message ends with a newline and goes to stdout (unless the subject says otherwise).
- Forbidden: `*printf`, `*alloc`, `free` → **0** · C++11 / Boost / external libs → **0** · `using namespace`, `friend` → **-42** · STL containers / `<algorithm>` before Module 08 → **-42**.
- No memory leaks. Orthodox Canonical Form for every class.
- **A function body written in a header = 0 for the exercise** (templates excepted).
- Every header includes what it needs and has include guards.
- Makefile: `$(NAME)`, `all`, `clean`, `fclean`, `re`, no relinking.

---

## ex00: Polymorphism

| | |
|---|---|
| **Files** | `Makefile`, `main.cpp`, `*.cpp`, `*.{h,hpp}` |
| **Forbidden** | None |

- Provide the most complete tests you can. **Each class prints its own constructor/destructor messages** (not the same message for all).
- Base class `Animal` with one **protected** attribute `std::string type;`
- `Dog` and `Cat` inherit from `Animal`; their `type` is `"Dog"` / `"Cat"`. Animal's type can be empty or anything.
- Every animal has `makeSound()`, which prints the right sound (cats don't bark).
- With the subject's main (`const Animal* j = new Dog();` ...), `j->makeSound()` must print the Dog sound, not the Animal one.
- Also write `WrongAnimal` and `WrongCat`: with them in the same main, **WrongCat prints the WrongAnimal sound**.
- Turn in more tests than the subject's.

## ex01: I don't want to set the world on fire

| | |
|---|---|
| **Files** | Files from ex00 + `*.cpp`, `*.{h,hpp}` |
| **Forbidden** | None |

- `Brain` class holding `std::string ideas[100]`.
- `Dog` and `Cat` have a **private `Brain*`**: `new Brain()` when built, `delete` when destroyed.
- In main: create and fill an **array of `Animal`**, half Dogs, half Cats. At the end, loop over it and delete every one **as an Animal**. Destructors must run in the right order. No leaks.
- **Copies of a Dog or a Cat must be deep.** Test it.

## ex02: Abstract class

| | |
|---|---|
| **Files** | Files from ex01 + `*.cpp`, `*.{h,hpp}` |
| **Forbidden** | None |

- `Animal` must **not be instantiable**. Everything else works as before.
- Renaming it `AAnimal` is allowed but not required.

## ex03: Interface & recap (optional, skipped)

Not needed to pass.

---

## Evaluation checklist

### Preliminary (any failure stops the grading)
- [ ] Compiles with `c++ -Wall -Wextra -Werror` (C++98)
- [ ] No function body in a header (templates excepted) → otherwise the exercise isn't graded
- [ ] The Makefile uses `c++` and the required flags
- [ ] No `*alloc`, `*printf`, `free`, `using namespace`, `friend`, C++11, external lib → **Forbidden function** flag
- [ ] Each exercise has enough tests and every non-interface class is in canonical form, **otherwise it isn't graded**

### ex00
- [ ] `Animal` has one attribute, `std::string type`, and can be instantiated and used
- [ ] At least `Cat` and `Dog` inherit from it; constructor/destructor outputs are clear
- [ ] **Ask the student about constructor and destructor order**
- [ ] `type` is `"Cat"` / `"Dog"` from creation
- [ ] The right `makeSound()` is always called; it is declared **`virtual`** (check the code)
- [ ] `WrongAnimal` / `WrongCat` without `virtual`: WrongCat prints its own sound only when used as a WrongCat

### ex01
- [ ] A `Brain` class; `Cat` and `Dog` have a private `Brain` attribute (not in `Animal`)
- [ ] Brain prints messages when created and deleted
- [ ] **Copying a Cat or Dog is deep.** Test: `Dog basic; { Dog tmp = basic; }`: with a shallow copy, `basic`'s Brain is deleted with `tmp` (crash / double free)
- [ ] The copy constructor is deep too
- [ ] `Animal`'s destructor is `virtual`. **Ask what happens without it**
- [ ] Copy and assignment work as the subject requires (a new Brain for each copy), no empty operators, nothing public without reason

### ex02
- [ ] `Animal::makeSound` is pure virtual: `virtual void makeSound() const = 0;`
- [ ] `Animal test;` gives a compile error
- [ ] `Cat` and `Dog` still work exactly like in ex01
