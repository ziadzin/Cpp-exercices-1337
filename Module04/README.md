# Module 04 · quick review

✅ Compiles, no leaks (valgrind), no forbidden code. ex03 skipped (allowed). Two things to tidy so the evaluator doesn't get confused or call the tests too thin.

## 🟠 Fix before pushing (5 min)
1. **ex02 `main.cpp`**: it only builds one Dog and one Cat. The sheet says "Cat and Dog still work exactly like in ex01" and "not enough tests = not graded". Copy ex01's `main.cpp` into ex02 (it works as is, it only uses `Animal*` pointers) and keep the commented `// Animal a;` line to show the compile error live.
2. **ex00 + ex01 `WrongAnimal.cpp`**: the messages print `this->type`, so deleting a WrongCat prints **"WrongCat destructor called" twice**, and the WrongAnimal sound prints "WrongCat sound". It looks like a bug. Print fixed text instead (`"WrongAnimal destructor called"`, `"WrongAnimal sound"`...), like you already did in ex02.

## What your code does
| ex | Remember this |
|---|---|
| ex00 | `Animal` has `protected type`, a **virtual** destructor and a **virtual** `makeSound()`. `Dog`/`Cat` set `type` in their constructor and override `makeSound()`. `WrongAnimal::makeSound()` is **not** virtual, so `WrongAnimal* p = new WrongCat(); p->makeSound();` calls WrongAnimal's version. |
| ex01 | `Brain` = `std::string ideas[100]`. Dog/Cat hold a private `Brain*`: `new Brain()` in the constructor, `delete` in the destructor. Copy constructor = `new Brain(*other.brain)` (deep). Assignment = `*brain = *other.brain` (copies the ideas into the existing Brain). Main: 4 Animals in an array, deleted as `Animal*`, plus the `Dog copy = original;` deep copy test. |
| ex02 | Same as ex01, but `makeSound() const = 0` makes `Animal` abstract: `new Animal()` no longer compiles. |

## The sheet will ask you
- Constructor/destructor order (parent built first, destroyed last).
- What happens without `virtual` on `~Animal()`: `delete animalPtr` only runs `~Animal()`, so Dog's destructor never runs and its Brain leaks.
- Shallow vs deep copy: with a shallow copy both Dogs share one Brain, and it gets deleted twice.
