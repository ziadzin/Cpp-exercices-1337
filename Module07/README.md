# Module 07 · quick review

✅ Nothing blocking. Compiles, no leaks. I ran your `swap/min/max` and `iter` against the sheet's attachment tests (`Awesome` class): both give the expected output.

## 🟡 Optional (1 min)
- **ex02 `Array.tpp`** is an empty file. Delete it, or the evaluator may ask what it's for.
- **ex02 `main.cpp:23`**: after `b[0] = 42` you print `b` but not `a`. Print `a` too, to show the copy is deep (a still starts with 9).

## What your code does
| ex | Remember this |
|---|---|
| ex00 | 3 templates in `whatever.hpp`. `swap` uses a temp copy. `max` returns `a` only if `a > b`, otherwise `b`; `min` returns `a` only if `a < b`, otherwise `b`. So when they're equal you get the **second** one, as the subject asks. They take and return `const T&`. Main calls `::swap` (the `::` means the global one, not `std::swap`). |
| ex01 | `template <typename T, typename F> void iter(T *arr, const size_t length, F f)`: calls `f(arr[i])` on each element. Making the function's type a template parameter `F` lets it accept anything: `print<int>`, a function taking `int&` (`addOne` modifies the array), or one taking `const T&`. |
| ex02 | `T *_data` + `unsigned int _size`. `Array(n)` = `new T[n]()` (the `()` initializes elements: ints become 0). Copy constructor → `operator=` → `delete[]` old data, then `newcopy()` allocates a new array and copies each element (deep copy). `operator[]` throws `std::out_of_range` if `index >= _size`, with a const version for const arrays. Destructor `delete[]`. |

## The sheet will ask you
- Why must templates be in the header? (the compiler needs the full code to generate each version, e.g. `Array<int>`, where it's used)
