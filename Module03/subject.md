# C++ Module 03

> Inheritance.
>
> Subject version 7 · eval sheet from evals-99cf9.web.app

**To pass: ex00 → ex02.** ex03 (DiamondTrap) is optional (the subject says: *"You can pass this module without doing exercise 03"*).

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

## ex00: Aaaaand... OPEN!

| | |
|---|---|
| **Files** | `Makefile`, `main.cpp`, `ClapTrap.{h,hpp}`, `ClapTrap.cpp` |
| **Forbidden** | None |

`ClapTrap` with **private** attributes:
- Name (passed to a constructor)
- Hit points **10**, energy points **10**, attack damage **0**

Public member functions:
- `void attack(const std::string& target);`
- `void takeDamage(unsigned int amount);`
- `void beRepaired(unsigned int amount);`

Rules:
- Attacking makes the target lose `<attack damage>` hit points. Repairing gives back `<amount>` hit points.
- Attacking and repairing cost **1 energy point** each.
- Nothing works with 0 hit points or 0 energy points.
- Every function prints what happens, e.g. `ClapTrap <name> attacks <target>, causing <damage> points of damage!`
- Constructors and destructor print a message too. Turn in your own tests.

## ex01: Serena, my love!

| | |
|---|---|
| **Files** | Files from ex00 + `ScavTrap.{h,hpp}`, `ScavTrap.cpp` |
| **Forbidden** | None |

- `ScavTrap` inherits from `ClapTrap` (constructors and destructor too), but **its constructors, destructor and `attack()` print different messages**.
- Tests must show the construction/destruction chaining: ClapTrap built first, destroyed last.
- Uses ClapTrap's attributes (make them accessible to the child), initialized to: hit points **100**, energy **50**, damage **20**.
- Special capacity: `void guardGate();` prints that ScavTrap is now in Gate keeper mode.

## ex02: Repetitive work

| | |
|---|---|
| **Files** | Files from previous exercises + `FragTrap.{h,hpp}`, `FragTrap.cpp` |
| **Forbidden** | None |

- `FragTrap` inherits from `ClapTrap`, with different construction/destruction messages. Show the chaining in tests.
- Hit points **100**, energy **100**, damage **30**.
- Special capacity: `void highFivesGuys(void);` prints a positive high-five request.

## ex03: Now it's weird! (optional, skipped)

Not needed to pass.

---

## Evaluation checklist

### Preliminary (any failure stops the grading)
- [ ] Compiles with `c++ -Wall -Wextra -Werror` (C++98)
- [ ] No function body in a header (templates excepted) → otherwise the exercise isn't graded
- [ ] The Makefile uses `c++` and the required flags
- [ ] No `*alloc`, `*printf`, `free`, `using namespace`, `friend`, C++11, external lib → **Forbidden function** flag
- [ ] Each exercise has enough tests, **otherwise it isn't graded**

### ex00
- [ ] `ClapTrap` with private name, hit points, energy points, attack damage, initialized to the requested values
- [ ] `attack()`, `takeDamage()`, `beRepaired()` present and working as specified

### ex01
- [ ] `ScavTrap` publicly inherits from `ClapTrap`, doesn't redeclare the attributes; ClapTrap's attributes are now **protected**
- [ ] Attributes initialized to the requested values
- [ ] `attack()`, `takeDamage()` (inherited), `beRepaired()` (inherited) work
- [ ] **Constructor, destructor and `attack()` messages differ from ClapTrap's**
- [ ] Order shown: ClapTrap constructor then ScavTrap constructor; ScavTrap destructor then ClapTrap destructor
- [ ] `guardGate()` prints a message; ScavTrap's `attack()` prints its own message

### ex02
- [ ] `FragTrap` publicly inherits from `ClapTrap`, no redeclared attributes
- [ ] Constructor/destructor with their own messages, in the right order (ClapTrap → FragTrap, then FragTrap → ClapTrap)
- [ ] `highFivesGuys()` prints a message
