# C++ Module 01

> Memory allocation, pointers to members, references, switch statement.
>
> Subject version 10 · eval sheet from evals-99cf9.web.app

**To pass: ex00 → ex05.** ex06 is optional (the subject says: *"You can pass this module without doing exercise 06"*).

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

---

## ex00: BraiiiiiiinnnzzzZ

| | |
|---|---|
| **Files** | `Makefile`, `main.cpp`, `Zombie.{h,hpp}`, `Zombie.cpp`, `newZombie.cpp`, `randomChump.cpp` |
| **Forbidden** | None |

- `Zombie` class with a private `std::string name` and `void announce(void);` that prints `<name>: BraiiiiiiinnnzzzZ...`
- `Zombie* newZombie(std::string name);` creates a zombie, names it, returns it so it can be used outside the function.
- `void randomChump(std::string name);` creates a zombie, names it, and it announces itself.
- The point: know when to allocate on the **stack** vs the **heap**.
- The destructor prints a message with the zombie's name.

## ex01: Moar brainz!

| | |
|---|---|
| **Files** | `Makefile`, `main.cpp`, `Zombie.{h,hpp}`, `Zombie.cpp`, `zombieHorde.cpp` |
| **Forbidden** | None |

- `Zombie* zombieHorde(int N, std::string name);` allocates **N zombies in a single allocation**, gives each the name, returns a pointer to the first one.
- Test it (call `announce()` on each), then delete all zombies, no leaks.

## ex02: HI THIS IS BRAIN

| | |
|---|---|
| **Files** | `Makefile`, `main.cpp` |
| **Forbidden** | None |

- A string variable initialized to `"HI THIS IS BRAIN"`.
- `stringPTR`: a **pointer** to the string. `stringREF`: a **reference** to the string.
- Print the address of the string, the address held by `stringPTR`, the address held by `stringREF`.
- Then print the value of the string, the value pointed to by `stringPTR`, the value pointed to by `stringREF`.

## ex03: Unnecessary violence

| | |
|---|---|
| **Files** | `Makefile`, `main.cpp`, `Weapon`, `HumanA`, `HumanB` (`.hpp` + `.cpp` each) |
| **Forbidden** | None |

- `Weapon`: private `std::string type`, `getType()` returns a **const reference** to `type`, `setType()` sets it.
- `HumanA` and `HumanB` have a `Weapon` and a name, and `attack()` prints `<name> attacks with their <weapon type>`.
- `HumanA` takes the Weapon in its constructor and is always armed. `HumanB` doesn't take it in the constructor and may have no weapon.
- The subject's main must print "crude spiked club" then "some other type of club" for both humans.

## ex04: Sed is for losers

| | |
|---|---|
| **Files** | `Makefile`, `main.cpp`, `*.cpp`, `*.{h,hpp}` |
| **Forbidden** | `std::string::replace` (and C file functions = cheating) |

- Takes 3 parameters: `<filename> <s1> <s2>`.
- Opens `<filename>`, copies it into `<filename>.replace`, replacing every `s1` with `s2`.
- Handle unexpected inputs and errors. Turn in your own tests.

## ex05: Harl 2.0

| | |
|---|---|
| **Files** | `Makefile`, `main.cpp`, `Harl.{h,hpp}`, `Harl.cpp` |
| **Forbidden** | None |

- Private member functions `debug()`, `info()`, `warning()`, `error()`.
- Public `void complain(std::string level);` calls the right one for `"DEBUG"`, `"INFO"`, `"WARNING"`, `"ERROR"`.
- **Must use pointers to member functions.** No if/else-if forest.
- Messages: the subject's examples or your own.

## ex06: Harl filter (optional, skipped)

Not needed to pass.

---

## Evaluation checklist

### Preliminary (any failure stops the grading)
- [ ] Compiles with `c++ -Wall -Wextra -Werror` (C++98)
- [ ] No function body in a header (templates excepted) → otherwise the exercise isn't graded
- [ ] The Makefile uses `c++` and the required flags
- [ ] No `*alloc`, `*printf`, `free`, `using namespace`, `friend`, C++11, external lib → **Forbidden function** flag
- [ ] No leaks

### ex00
- [ ] Makefile with the right flags, a main that tests the exercise
- [ ] `Zombie` class, private `name`, at least one constructor, `announce()` prints `<name>: BraiiiiiiinnnzzzZ...`
- [ ] Destructor prints a debug message with the name
- [ ] `newZombie()` allocates on the heap and returns it; the zombie announces with the given name; it's deleted before the end
- [ ] `randomChump()` creates a zombie on the stack and it announces itself
- [ ] **The student justifies heap vs stack**

### ex01
- [ ] `Zombie` has a default constructor
- [ ] `zombieHorde()` uses `new[]` (one allocation), then sets the names, returns the first zombie
- [ ] Tests call `announce()` on every zombie; all zombies deleted at once in main (`delete[]`)

### ex02
- [ ] A string containing `"HI THIS IS BRAIN"`
- [ ] `stringPTR` is a pointer, **`stringREF` is a reference**
- [ ] Address printed using the string, `stringPTR` and `stringREF`
- [ ] Value printed using `stringPTR` and `stringREF`

### ex03
- [ ] `Weapon` with a type string, `getType()` (returns a const reference) and `setType()`
- [ ] `HumanA` holds a reference (ideal) or pointer to the Weapon
- [ ] `HumanB` holds a **pointer** (the weapon is set later and can be NULL)

### ex04
- [ ] A replace function that works as the subject says
- [ ] Good error handling: missing file, no permissions, empty file, etc. **Any non-esoteric unhandled error = no points**
- [ ] Reads with an `ifstream`, writes with an `ofstream`
- [ ] Uses `std::string` functions, not char-by-char reading

### ex05
- [ ] `Harl` class with at least the 5 functions
- [ ] `complain()` calls the others through pointers to member functions
- [ ] No if/else-if/else forest
