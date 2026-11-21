# Module 06 · quick review

✅ Nothing blocking. Compiles, outputs match the subject, one cast type per exercise, no `<typeinfo>`.

## 🟡 Before pushing (2 min)
- **ex01 `main.cpp:31`**: after deserializing you print `data` (the original), not `*d`. The sheet checks "the resulting Data struct is usable" and the subject says "check it compares equal". Print `printdata(*d)` and add `std::cout << (d == &data ? "same pointer" : "different") << '\n';`
- **ex01 `Makefile:3`**: remove `-g` (harmless, but keep only the required flags).
- `ex00/convert` and `ex02/identify` binaries are committed in git. Don't push them.
- ex00: the evaluator should type `./convert a`, not `./convert "'a'"` (with quotes it says impossible). Fine per the subject, just know it.

## What your code does
| ex | Remember this |
|---|---|
| ex00 | Constructors are private → not instantiable. `getType()` detects: 1 non-digit char → CHAR, pseudo-literal (`nan`, `+inff`...) → PSEUDO, digits only → INT, digits/one dot + `f` → FLOAT, digits/one dot → DOUBLE, else impossible. Everything goes into a `double` (`strtod`, or the char's code), then `static_cast` to char/int/float. char: out of 0–127 → impossible, not printable → Non displayable. int: outside INT_MIN..INT_MAX → impossible. Adds `.0` when the number is whole. |
| ex01 | `Data` = `{ int id; std::string link; }`. `serialize` = `reinterpret_cast<uintptr_t>(ptr)`, `deserialize` = `reinterpret_cast<Data*>(raw)`. `uintptr_t` comes from `<stdint.h>` (C++98 has no `<cstdint>`). |
| ex02 | `generate()`: `srand(time(NULL))` in main, `rand() % 3` → new A/B/C. `identify(Base*)`: `dynamic_cast<A*>(p)` returns NULL if wrong, try A, B, C. `identify(Base&)`: `dynamic_cast<A&>(p)` **throws** `std::bad_cast` if wrong, so each try is in try/catch. Works only because `Base` has a virtual destructor (polymorphic class). |

## The sheet will ask you
- Why `static_cast` in ex00, `reinterpret_cast` in ex01, `dynamic_cast` in ex02?
- Why does `dynamic_cast` need a virtual function in `Base`?
