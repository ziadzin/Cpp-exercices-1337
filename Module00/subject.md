# C++ Module 00

> Namespaces, classes, member functions, stdio streams, initialization lists, static, const, and some other basic stuff.
>
> Version 11.2

## Table of contents

1. [General rules](#general-rules)
2. [Exercise 00: Megaphone](#exercise-00-megaphone)
3. [Exercise 01: My Awesome PhoneBook](#exercise-01-my-awesome-phonebook)
4. [Exercise 02: The Job Of Your Dreams](#exercise-02-the-job-of-your-dreams-optional)
5. [Submission and peer evaluation](#submission-and-peer-evaluation)
6. [Evaluation checklist](#evaluation-checklist)

---

## General rules

### Compiling
- Compile with `c++` and the flags `-Wall -Wextra -Werror`.
- The code must still compile if you add `-std=c++98`.

### Naming and formatting
- Directories: `ex00`, `ex01`, ..., `exn`.
- Class names in **UpperCamelCase**.
- A file that holds class code is named after the class: `BrickWall.hpp`, `BrickWall.cpp`, `BrickWall.tpp`.
- Unless the subject says otherwise, every output message ends with a newline and goes to standard output.
- No Norminette. Any coding style is allowed, but the code must be readable for the evaluator.

### Allowed / forbidden

| Rule | Penalty |
|---|---|
| `*printf()`, `*alloc()`, `free()` | **0** |
| C++11 (or later) and Boost | **0** |
| Any external library | **0** |
| `using namespace <ns>` | **-42** |
| `friend` keyword | **-42** |
| STL containers (`vector`, `list`, `map`...) and `<algorithm>` before Modules 08/09 | **-42** |

- Prefer the C++ versions of the C functions you know.

### Design requirements
- No memory leaks: everything you allocate with `new` must be freed.
- Orthodox Canonical Form is required from Module 02 to Module 09 (not in Module 00).
- **Any function implemented in a header (except function templates) = 0 for the exercise.**
- Every header must work on its own: it includes everything it needs and has **include guards** (otherwise 0).

### Makefile
- Same rules as in C (see the Norm): `$(NAME)`, `all`, `clean`, `fclean`, `re`, and no relinking.

### Good to know
- You can add extra files to split your code, as long as the mandatory files are there.
- The examples can contain requirements the instructions don't spell out.
- Read the whole module before starting.

---

## Exercise 00: Megaphone

| | |
|---|---|
| **Directory** | `ex00/` |
| **Files** | `Makefile`, `megaphone.cpp` |
| **Forbidden** | None |

Write a program that prints its arguments in uppercase. With no arguments, it prints a fixed message.

```console
$> ./megaphone "shhhhh... I think the students are asleep..."
SHHHHH... I THINK THE STUDENTS ARE ASLEEP...
$> ./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.
$> ./megaphone
* LOUD AND UNBEARABLE FEEDBACK NOISE *
$>
```

- Arguments are printed one after another with **no added separator**.
- Solve it in a C++ way (`std::string`, `std::toupper`, `std::cout`).

---

## Exercise 01: My Awesome PhoneBook

| | |
|---|---|
| **Directory** | `ex01/` |
| **Files** | `Makefile`, `*.cpp`, `*.{h, hpp}` |
| **Forbidden** | None |

### Classes

**`PhoneBook`**
- Holds an **array** of contacts.
- Stores **at most 8** contacts. A 9th contact replaces the **oldest** one.
- **No dynamic allocation.**

**`Contact`**
- One phonebook entry.

**Rules for both**
- The phonebook is an instance of `PhoneBook`, and each contact is an instance of `Contact`.
- Anything only used inside a class is **private**. Anything used from outside is **public**.

### Program behavior

At start-up the phonebook is empty. The program waits for one of three commands: `ADD`, `SEARCH` or `EXIT`. **Any other input is ignored.** After each command it waits for the next one, until `EXIT`.

#### `ADD`: save a new contact
- Ask for each field, one at a time:
  1. first name
  2. last name
  3. nickname
  4. phone number
  5. darkest secret
- A saved contact **can't have empty fields**.
- Once every field is filled in, add the contact to the phonebook.

#### `SEARCH`: display a contact
1. Show the saved contacts as a table of **4 columns**: index, first name, last name, nickname.
   - Each column is **10 characters wide**.
   - Columns are separated by a pipe `|`.
   - Text is **right-aligned**.
   - Text longer than 10 characters is truncated, and the last visible character is replaced by a dot `.`.
2. Ask for the index of the entry to display.
   - Index out of range or invalid: choose a sensible behavior.
   - Otherwise, show every field of the contact, **one per line**.
- **Use `<iomanip>`** (`std::setw`, ...) to produce this display.

Example table:

```text
     index|first name| last name|  nickname
         0|      John|       Doe|     johnd
         1|Alexandra.|     Smith|       Al
```

#### `EXIT`
- The program quits, and the contacts are lost forever.

### Other
- Give the executable a meaningful name.
- References: [std::string](http://www.cplusplus.com/reference/string/string/), [iomanip](http://www.cplusplus.com/reference/iomanip/)

---

## Exercise 02: The Job Of Your Dreams (optional)

| | |
|---|---|
| **Directory** | `ex02/` |
| **Files** | `Makefile`, `Account.cpp`, `Account.hpp`, `tests.cpp` |
| **Forbidden** | None |

> **Not mandatory** to pass the module.

- `Account.hpp`, `tests.cpp` and a log file are available on the intranet.
- `Account.cpp` was lost. **Rewrite it** so that `tests.cpp` compiles and its output **matches the log file**.
- Only two differences are allowed:
  - timestamps
  - the order in which destructors are called (it depends on the compiler/OS)

---

## Submission and peer evaluation

- Push to your Git repository. Only what is in the repository is evaluated.
- Double-check the file names.
- During the defense you may be asked for a **small change** (a few lines, a display tweak, a new field...). It should take a few minutes.

---

## Evaluation checklist

### Preliminary checks (any failure stops the grading)
- [ ] Compiles with `c++ -Wall -Wextra -Werror` (and `-std=c++98`)
- [ ] No function implemented in a header (templates excepted) → otherwise the exercise isn't graded
- [ ] The Makefile uses `c++` and the required flags
- [ ] No `*alloc`, `*printf`, `free` → otherwise **Forbidden Function** flag
- [ ] No `using namespace` and no `friend` → otherwise **Forbidden Function** flag
- [ ] No C++11 features and no external libraries

### ex00: Megaphone
- [ ] Uppercase conversion done the C++ way (`std::string` / `toupper`)
- [ ] Prints the feedback message when run with no arguments

### ex01: PhoneBook (each part graded 0–5)
- [ ] **Error handling**: no crash on bad input or EOF (Ctrl+D)
- [ ] **EXIT** works as described
- [ ] **Visibility**: `Contact` attributes are private and have getters/setters; only what's needed is public
- [ ] **Classes**: a `Contact` class with the 5 fields; a `PhoneBook` class with an array of `Contact`
- [ ] **Read/eval loop** with `std::cin`, which runs until `EXIT`
- [ ] **ADD**: all fields required, none empty; the 9th contact replaces the oldest
- [ ] **SEARCH**: 10-character columns, `|` separators, right-aligned, truncated with `.`, uses `iomanip`

### ex02: Account
- [ ] Output identical to the log, except for timestamps and destructor order
