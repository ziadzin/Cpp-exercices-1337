# C++ Module 05

> Repetition and exceptions.
>
> Subject version 10.1 · eval sheet from evals-99cf9.web.app

**To pass: ex00 → ex03** (all 4, none is optional).

---

## General rules (same in every module)

- Compile with `c++ -Wall -Wextra -Werror`. It must still compile with `-std=c++98`.
- Folders `ex00`, `ex01`, ...; classes in UpperCamelCase; class `Foo` lives in `Foo.hpp` / `Foo.cpp`.
- Every output message ends with a newline and goes to stdout (unless the subject says otherwise).
- Forbidden: `*printf`, `*alloc`, `free` → **0** · C++11 / Boost / external libs → **0** · `using namespace`, `friend` → **-42** · STL containers / `<algorithm>` before Module 08 → **-42**.
- No memory leaks. Orthodox Canonical Form for every class (**exception classes don't need it**).
- **A function body written in a header = 0 for the exercise** (templates excepted). This includes an exception's `what()`.
- Every header includes what it needs and has include guards.
- Makefile: `$(NAME)`, `all`, `clean`, `fclean`, `re`, no relinking.

---

## ex00: Mommy, when I grow up, I want to be a bureaucrat!

| | |
|---|---|
| **Files** | `Makefile`, `main.cpp`, `Bureaucrat.{h,hpp}`, `Bureaucrat.cpp` |
| **Forbidden** | None |

- `Bureaucrat` has a **constant name** and a **grade from 1 (highest) to 150 (lowest)**.
- Creating one with an invalid grade throws `Bureaucrat::GradeTooHighException` or `Bureaucrat::GradeTooLowException`.
- Getters `getName()` and `getGrade()`.
- Two functions to increment / decrement the grade; out of range → same exceptions. Incrementing grade 3 gives grade 2.
- Exceptions must be catchable with `catch (std::exception & e)`.
- `<<` overload printing `<name>, bureaucrat grade <grade>.`
- Turn in tests.

## ex01: Form up, maggots!

| | |
|---|---|
| **Files** | Files from ex00 + `Form.{h,hpp}`, `Form.cpp` |
| **Forbidden** | None |

- `Form` has: a constant name, a bool "is signed" (false at construction), a constant grade to sign, a constant grade to execute. All **private**, not protected.
- Grades follow the Bureaucrat rules: `Form::GradeTooHighException` / `Form::GradeTooLowException`.
- Getters for everything and a `<<` overload printing all the form's info.
- `beSigned(Bureaucrat)`: signs the form if the bureaucrat's grade is high enough (≤ required), otherwise throws `Form::GradeTooLowException`.
- `Bureaucrat::signForm()`: prints `<bureaucrat> signed <form>` or `<bureaucrat> couldn't sign <form> because <reason>.`
- Turn in tests.

## ex02: No, you need form 28B, not 28C...

| | |
|---|---|
| **Files** | `Makefile`, `main.cpp`, `Bureaucrat`, `AForm`, `ShrubberyCreationForm`, `RobotomyRequestForm`, `PresidentialPardonForm` (`.hpp` + `.cpp` each) |
| **Forbidden** | None |

- `Form` becomes abstract and is renamed **`AForm`**. Its attributes stay private, in the base class.
- Concrete forms, each taking **one constructor parameter: the target**:

| Form | Sign | Exec | Action |
|---|---|---|---|
| `ShrubberyCreationForm` | 145 | 137 | Creates `<target>_shrubbery` in the working directory with ASCII trees inside |
| `RobotomyRequestForm` | 72 | 45 | Drilling noises, then `<target>` robotomized successfully **50% of the time**, otherwise "robotomy failed" |
| `PresidentialPardonForm` | 25 | 5 | `<target> has been pardoned by Zaphod Beeblebrox.` |

- `execute(Bureaucrat const & executor) const` in the base form: check that the form is **signed** and the executor's grade is **high enough**, else throw. Checks in each class or in the base class (then call the action): both are fine.
- `Bureaucrat::executeForm(AForm const & form)`: tries to execute, prints `<bureaucrat> executed <form>` or an explicit error.
- Turn in tests.

## ex03: At least this beats coffee-making

| | |
|---|---|
| **Files** | Files from ex02 + `Intern.{h,hpp}`, `Intern.cpp` |
| **Forbidden** | None |

- `Intern`: no name, no grade. One function: `makeForm(formName, target)` returns a pointer to the new form (`AForm*`).
- Prints `Intern creates <form>`. Unknown name → explicit error message.
- **No if/else-if/else forest.**
- Example: `Intern someRandomIntern; AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");`

---

## Evaluation checklist

### Preliminary (any failure stops the grading)
- [ ] Compiles with `c++ -Wall -Wextra -Werror` (C++98)
- [ ] **No function body in a header** (templates excepted) → otherwise the exercise isn't graded
- [ ] The Makefile uses `c++` and the required flags
- [ ] No `*alloc`, `*printf`, `free`, `using namespace`, `friend`, C++11, external lib → **Forbidden function** flag
- [ ] No leaks
- [ ] Each exercise has a main with **enough tests** and every non-interface class is in canonical form, **otherwise it isn't graded**

### ex00
- [ ] Makefile with the right flags; a `Bureaucrat` class with a constant name
- [ ] Grade from 1 (highest) to 150 (lowest); exceptions when creating with a grade too high / too low
- [ ] Getters; increment / decrement functions that throw when needed (incrementing 3 gives 2)
- [ ] Exceptions inherit from `std::exception` (catchable as `std::exception & e`)
- [ ] `<<` overload that prints the Bureaucrat's info

### ex01
- [ ] A `Form` class: name, signed bool (false at start), grade to sign, grade to execute
- [ ] Names and grades are constant; all attributes **private**, not protected
- [ ] Same grade rules and exceptions as Bureaucrat
- [ ] Getters and a `<<` overload showing the full state
- [ ] `Form::beSigned()` and `Bureaucrat::signForm()` work as the subject says

### ex02
- [ ] Concrete forms with the right names, grades and actions
- [ ] Their constructors take only one parameter: the target
- [ ] `execute(Bureaucrat const & executor)` works as specified (pure in the base + checks in each class, or checks in the base + action in the child: both valid)
- [ ] `Bureaucrat::executeForm(Form const & form)` works as specified

### ex03
- [ ] An `Intern` class with a working `makeForm()`
- [ ] **Good dispatching**: an array of pointers to member functions (or similar). if/else-if/else = wrong
