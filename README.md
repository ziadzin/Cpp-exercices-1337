# CPP 00–09 · revalidation status (2026-11-21)

Each `ModuleXX/` has a **`subject.md`** (subject + evaluation sheet) and a **`README.md`** (what your code does + what to fix).
Only the exercises needed to pass are covered. Optional ones (M01 ex06, M02/M03/M04 ex03) are skipped: the subjects say you can pass without them.

| Module | State | Fix before pushing |
|---|---|---|
| 00 | ✅ done | — |
| 01 | 🟠 1 fail | ex02 `stringREF` must be a reference · ex04 remove `-w` |
| 02 | ✅ ready | don't push the `.o` / binary in ex00 |
| 03 | 🔴 ex01 broken | doesn't compile · ScavTrap `attack()` commented out · `guardGate()` sets hp to 0 · thin main |
| 04 | 🟠 tidy | ex02 main too thin · WrongAnimal messages print the child's type |
| 05 | 🔴 most work | restore `da17717` · move every `what()` into the `.cpp` · ex03 leak · thin mains + `srand` |
| 06 | ✅ ready | (ex01: print `*d`, compare pointers) |
| 07 | ✅ ready | — |
| 08 | 🟠 tests | ex02 needs more tests than the subject's · ex01 10 000-number test |
| 09 | 🔴 ex00 | debug print · real `data.csv` · days-per-month check |

All modules were built with this machine's `c++` (clang 12) with `-Wall -Wextra -Werror -std=c++98` and run under valgrind.
