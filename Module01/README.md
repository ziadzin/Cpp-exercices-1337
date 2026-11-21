# Module 01 · quick review

Compiles with clang, no leaks, no forbidden code. ex06 skipped (allowed).

## 🔴 Fix before pushing
1. **ex02 `main.cpp:8`**: `ref` is a pointer (`std::string *ref = ptr;`). The eval sheet checks that `stringREF` **is a reference**, so the exercise fails as it is.
   Use `std::string &stringREF = brain;`, then print `&stringREF` and `stringREF` (and rename `ptr` to `stringPTR`).
2. **ex04 `Makefile:3`**: remove `-w`. It turns off every warning, so `-Wall -Wextra -Werror` do nothing.

## 🟡 Small risks (1 min each)
- **ex04**: `./replace somedir a b` creates an empty `somedir.replace` and returns 0. The sheet says any non-esoteric unhandled error = 0 points. Fix: just before line 29 (where `dst` is created), add `src.peek(); if (src.bad()) { std::cerr << "cannot read " << filename << "\n"; return 1; }`
- **ex05 `Harl.cpp:50`**: the "Invalid condition!" message has no `\n` (rule: every output ends with a newline).

## What your code does
| ex | Remember this |
|---|---|
| ex00 | `newZombie` = `new Zombie(name)` on the **heap**: it outlives the function, main must `delete` it. `randomChump` = local `Zombie` on the **stack**: destroyed automatically when the function returns. Destructor prints `<name> destroyed`. |
| ex01 | `zombieHorde` = **one** `new Zombie[N]` (calls the default constructor N times), then `setName()` in a loop. Main announces all of them, then one `delete[] horde`. Returns NULL if N <= 0. |
| ex02 | Prints 3 addresses, then 3 values. A reference is another name for the same variable (it can't be NULL or reseated). |
| ex03 | `HumanA` stores `Weapon&`: always armed, set in the init list. `HumanB` stores `Weapon*`: starts NULL, `setWeapon()` later, `attack()` prints nothing without a weapon. Both see `setType()` changes because they don't copy the weapon. |
| ex04 | Reads line by line with `getline`, `find(s1, pos)`, writes `substr(0, pos) + s2`, cuts the line after `s1`, repeats. Adds `\n` back unless the last line had none. Rejects: wrong arg count, empty `s1`, unreadable input, uncreatable output. |
| ex05 | Two arrays filled in the constructor: `methods[4]` (pointers to `debug/info/warning/error`) and `options[4]` (`"DEBUG"`...). `complain()` loops, finds the matching string, calls `(this->*methods[i])()`. |

## The sheet will ask you
- ex00: why heap for `newZombie` and stack for `randomChump`?
- ex03: why a reference in `HumanA` and a pointer in `HumanB`?
