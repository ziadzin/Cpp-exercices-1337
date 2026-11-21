# Module 03 · quick review

ex00 and ex02 compile and work. **ex01 does not compile** and is missing a required function. ex03 skipped (allowed).

## 🔴 Fix before pushing (all in ex01)
1. **`ClapTrap.cpp:80`**: delete `if(this == ClapTrap)` (and the comment under it). It's a compile error, so the whole module gets "Invalid compilation".
2. **ScavTrap needs its own `attack()`**: it's commented out (`ScavTrap.hpp:14`, `ScavTrap.cpp:59-77`). The sheet checks that ScavTrap's `attack()` prints a different message. Uncomment both (ex02 has the same working version).
3. **`ScavTrap.cpp:54`**: `guardGate()` sets `hp = 0`, so entering Gate keeper mode kills the ScavTrap. Delete that line (ex02 doesn't have it).
4. **`main.cpp`**: it only tests one attack. "Not enough tests" = not graded. Make it show: a named ScavTrap (chaining order), `attack`, `takeDamage`, `beRepaired`, `guardGate`. You can just uncomment lines 6-12.
5. `ScavTrap.o`, `main.o` and the binary `scavtrap` are committed in git. Don't push them.

## 🟡 Small risk
- **ex00 `ClapTrap.cpp:114-125`**: `beRepaired` refuses at 10 HP and caps HP at 10. The subject only says "gets `<amount>` hit points back". Be ready to defend it as a design choice, or delete those 2 checks (ex01/ex02 already don't have them).

## What your code does
| ex | Remember this |
|---|---|
| ex00 | `name`, `hp`=10, `ep`=10, `damage`=0 (private). `attack`: needs hp > 0 and ep > 0, costs 1 ep (`ep--` inside the condition). `takeDamage`: hp can't go below 0 (unsigned, so it checks `hp <= amount` first). `beRepaired`: costs 1 ep, adds hp. `putname()` is a small helper that prints "ClapTrap <name>". |
| ex01 | Attributes become `protected` so ScavTrap can set them. `ScavTrap : public ClapTrap`; constructors call `ClapTrap(name)` in the init list, then set 100/50/20. Copy and `=` reuse ClapTrap's. `guardGate()` prints Gate keeper mode. |
| ex02 | `FragTrap : public ClapTrap`, 100/100/30, `highFivesGuys()`. Main builds a ScavTrap and a FragTrap, assigns one FragTrap to another, calls the special functions. |

## The sheet will ask you
- Why is ClapTrap built first and destroyed last? (the child is built on top of the parent: parent first; destruction is the reverse)
- Why `protected` instead of `private` in ex01?
