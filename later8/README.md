# C++ Module 08 — Templated containers, iterators, algorithms

The whole point of this module: **stop writing your own data structures and start using the STL.**
Modules 00–07 forbade containers and `<algorithm>`. From 08 on, they're not just allowed — they're
mandatory. The subject says it explicitly: solving the exercises *without* containers/algorithms
gets you a very bad grade even if the code works.

Constraints stay the same as always: `c++ -Wall -Wextra -Werror -std=c++98`, Orthodox Canonical Form,
include guards, no `using namespace`, no `friend`, no `*printf`/`*alloc`/`free`, no leaks.

---

## Part 1 — The concepts you need to learn

### 1. The three pillars of the STL

The STL is built on a deliberate separation:

```
Containers   ──hand out──▶   Iterators   ──consumed by──▶   Algorithms
(store data)                (walk data)                    (do work)
```

The genius is that algorithms never know what container they're working on. `std::find` works on a
`vector`, a `list`, a `deque`, or a raw C array — because it only ever talks to iterators. That
decoupling is *the* idea to internalize this module.

### 2. Containers

Three families:

| Family | Members | Storage | Cost model |
|---|---|---|---|
| **Sequence** | `vector`, `list`, `deque` | order = insertion order | `vector`: O(1) random access, O(n) middle insert. `list`: O(1) insert anywhere, no random access. `deque`: O(1) push front/back |
| **Associative** | `map`, `set`, `multimap`, `multiset` | sorted by key (red-black tree) | O(log n) lookup/insert |
| **Adaptors** | `stack`, `queue`, `priority_queue` | wrap another container | restricted interface on purpose |

Things worth knowing before you write a line:
- `size()` vs `capacity()` on a `vector`, and why `reserve()` matters when you insert 10 000 elements.
- **Iterator invalidation**: a `vector` reallocating destroys every iterator/pointer into it. A `list` never does.
- `std::vector` is the default choice. Pick something else only when you can say why.

### 3. Iterators

An iterator is a generalized pointer. It supports some subset of `*it`, `++it`, `--it`, `it + n`,
`it1 == it2`. The subset it supports defines its **category**:

```
Input / Output  ──▶  Forward  ──▶  Bidirectional  ──▶  Random Access
(read/write once)    (++ only)     (++ and --)         (+ n, -, <)
                                   list, map, set      vector, deque
```

Key vocabulary:
- **Range** = a pair `[first, last)` — `last` is one *past* the end, never dereferenceable.
  Every algorithm and many container member functions take a range.
- `begin()` / `end()`, and the `const_iterator` versions you get from a const object.
- `reverse_iterator` via `rbegin()` / `rend()`.
- Dependent-type syntax: inside a template you must write `typename Container::iterator` — the
  `typename` keyword tells the compiler that name is a type, not a value. **You will hit this
  compile error in ex00.** Understand it, don't cargo-cult it.

### 4. Algorithms (`<algorithm>`, `<numeric>`)

The ones actually useful here:

| Function | Does |
|---|---|
| `std::find(first, last, value)` | returns iterator to first match, or `last` if none |
| `std::min_element` / `std::max_element` | iterator to smallest/largest |
| `std::sort` | needs random-access iterators (so: not on `std::list`) |
| `std::adjacent_difference` | `<numeric>` — differences between consecutive elements |
| `std::copy`, `std::for_each`, `std::count` | the everyday workhorses |

Notice the convention: algorithms that "fail" return the end iterator rather than throwing.
That's the "analyze how standard containers behave" hint in ex00.

### 5. Templates, revisited

Module 07 covered templates; here they interact with containers:
- Function templates deduce `T` from the arguments. Class templates (before C++11) don't — you must
  write `MutantStack<int>`.
- Template code must be **visible at instantiation**, so definitions live in the header (or a `.tpp`
  included at the bottom of the header). The subject explicitly allows this: templates are the one
  exception to "no implementations in headers".

### 6. Container adaptors and *"implemented in terms of"*

`std::stack` is not a container — it's an **adaptor** wrapping one (a `deque` by default):

```cpp
template <class T, class Container = std::deque<T> >
class stack {
protected:
    Container c;   // ← protected, not private. That is the whole trick of ex02.
};
```

That `protected` member `c` is deliberate: it exists so you can derive from `stack` and reach the
underlying container. Which is exactly what ex02 wants.

Also learn the distinction the subject leans on:
- **is-a** (public inheritance) → `MutantStack` *is a* `std::stack`
- **has-a / implemented-in-terms-of** (composition or private inheritance) → `Span` *has a* `vector`

### 7. Exceptions

Already seen in Module 05, but used properly here: derive from `std::exception`, override
`what() const throw()`, and note the C++98 `throw()` specifier that C++11 replaced with `noexcept`.

---

## Part 2 — What we're actually going to build

### ex00 — `easyfind`

**Files:** `Makefile`, `main.cpp`, `easyfind.{h,hpp}`, optional `easyfind.tpp`

A function template `easyfind(T container, int value)` that finds the first occurrence of `value`
in a container of ints. If it's not there: throw, or return an error value — your call, but justify it.

*What this is really teaching:* that one template + `std::find` covers `vector`, `list` and `deque`
at once. Associative containers are explicitly out of scope. Small exercise, but it's where you'll
meet `typename Container::iterator` and decide on your not-found policy.

Test it with at least two different container types — that's the only way to show the template earns its keep.

### ex01 — `Span`

**Files:** `Makefile`, `main.cpp`, `Span.{h,hpp}`, `Span.cpp`

A class holding at most `N` ints (`N` is an `unsigned int`, the sole constructor parameter):

- `addNumber(int)` — adds one number; throws if already at `N` elements.
- `shortestSpan()` — smallest distance between any two stored numbers.
- `longestSpan()` — largest distance (i.e. max − min).
- Both throw if fewer than 2 numbers are stored.
- Plus a **range-based fill**: a member function taking a *pair of iterators* to insert many numbers
  in one call — because calling `addNumber()` 10 000 times is absurd. Look at how
  `vector::insert(pos, first, last)` and the range constructor are declared, and mirror that.

Expected behaviour from the subject:

```
Span sp = Span(5);
sp.addNumber(6); sp.addNumber(3); sp.addNumber(17); sp.addNumber(9); sp.addNumber(11);
sp.shortestSpan();  // 2
sp.longestSpan();   // 14
```

*The real lesson:* algorithmic thinking. `longestSpan` is `max_element - min_element` — trivial.
`shortestSpan` naively is O(n²): comparing every pair. Sort a copy first and the answer is the
smallest gap between *adjacent* elements, O(n log n). That's why they demand you test with **10 000+
numbers** — the naive version will crawl. Note: you should not sort the real data if you want to keep
insertion order; work on a copy.

Watch out for `int` overflow when computing distances between extremes, and make the range-fill
respect the `N` limit (throw rather than silently truncate).

### ex02 — `MutantStack`

**Files:** `Makefile`, `main.cpp`, `MutantStack.{h,hpp}`, optional `MutantStack.tpp`

`std::stack` is the one STL container that is **not iterable** — by design, since a stack only exposes
`top()`. The exercise: fix that "injustice". Write `MutantStack<T>`, implemented in terms of
`std::stack`, offering all of stack's member functions *plus* iterators.

You need `begin()`, `end()`, and the `iterator` typedef (do `const_iterator` and the reverse ones too —
it's a couple of lines and evaluators ask). The path there is the `protected` member `c` shown above:
inherit publicly from `std::stack<T>`, then expose the underlying container's iterators.

Validation criterion from the subject: run their `main` with your `MutantStack`, then again with a
`std::list` (renaming `push`→`push_back`). **The output must be identical.** That's your proof the
mutant behaves like a real container.

Also note the last line of their test — `std::stack<int> s(mstack);` — it must still compile. Your
mutant has to remain a genuine `std::stack`.

---

## Suggested order of study

1. Read cppreference on `std::vector`, `std::list`, `std::stack` — especially the *member function*
   tables and each one's complexity.
2. Read `std::find`, `std::min_element`, `std::max_element`, `std::sort`.
3. Write ex00. Fight the `typename` error until you understand it rather than until it compiles.
4. Write ex01 naive first, benchmark it at 10 000 elements, then make it fast. That contrast is the
   lesson.
5. For ex02, go read the actual `<stack>` header on your machine
   (`/usr/include/c++/*/bits/stl_stack.h`). The answer is sitting right there in the class definition.

## Self-check before defence

- [ ] Can you explain why `std::sort` doesn't work on `std::list`?
- [ ] Can you name a case where a `vector` iterator becomes invalid?
- [ ] Why must template definitions live in the header?
- [ ] What's the complexity of your `shortestSpan`? Can you prove it?
- [ ] Why is `std::stack::c` protected instead of private?
- [ ] Is your `MutantStack` an *is-a* or a *has-a* relationship — and why did you pick that?
