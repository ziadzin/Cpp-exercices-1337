# Module 02 · quick review

✅ Nothing blocking. Compiles with clang, outputs match the subject, no forbidden code. ex03 skipped (allowed).

## 🟡 Before pushing
- `ex00/` has `Fixed.o`, `main.o` and the binary `fixed` committed in git. Don't push them (`git rm --cached` them).

## What your code does
| ex | Remember this |
|---|---|
| ex00 | `int value` + `static const int fraction = 8`. The copy constructor calls `*this = other`, so it prints "Copy assignment operator called", and the assignment uses `getRawBits()`: that's why the output matches the subject line for line. |
| ex01 | int → fixed: `x << 8` (= x × 256). float → fixed: `roundf(y * 256)`. fixed → float: `value / 256.0`. fixed → int: `value >> 8`. `operator<<` is a free function in `Fixed.cpp` that prints `toFloat()`. |
| ex02 | Comparisons compare the raw `value`s. `+`/`-` add/subtract raw values. `*` = `(a × b) >> 8`, `/` = `(a << 8) / b`, both computed in `long` to avoid overflow. `++`/`--` change the raw value by 1 = ϵ = 1/256 = 0.00390625. Prefix returns `*this` by reference, postfix returns a copy made before the change. `min`/`max` are `static`, each in a non-const and a const version. |

## The sheet may ask you
- Why fixed-point? Exact like integers, but with a fraction part (8 bits = steps of 1/256).
- Difference between `++a` and `a++` in your code (reference vs copy).
- To test an operator live, e.g. `std::cout << (a < b) << std::endl;` or `Fixed::min(a, b)`.
