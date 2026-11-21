# Module 05 · quick review

⚠️ **The module that needs the most work.** A July commit (`8f7d277`, "06done") damaged it: it deleted ex00, added a `printf` to ex02 (doesn't even compile), and replaced ex03's main with an unrelated test plus `using namespace std`.

## 🔴 Fix before pushing
1. **Get the good version back** (the commit right before the damage):
   `cd ~/cppyat && git checkout da17717 -- Module05`
   This restores ex00, removes the `printf` and `using namespace`, and puts back the Intern test. It doesn't touch this README or `subject.md`.
2. **Move every `what()` body out of the headers.** `Bureaucrat.hpp`, `Form.hpp` and `AForm.hpp` define `what()` inside the class. The sheet says a function body in a header = **the exercise isn't graded**, so as it is, ex00–ex03 all fail. In the `.hpp` keep only:
   `virtual const char* what() const throw();`
   and in the `.cpp` add:
   `const char* Bureaucrat::GradeTooHighException::what() const throw() { return ("Grade is too high!"); }`
   Do this for each exception class in every exercise (2 in Bureaucrat, 2 in Form, 3 in AForm).
3. **ex03 main leaks**: the form from `makeForm()` is never deleted (valgrind: 112 bytes lost). Leaks flag = 0. `delete` every form it returns. Also remove the old "bug confirmed" comments, they're wrong now.
4. **Thin mains.** The sheet says "not enough tests = not graded". Minimum:
   - **ex00**: print a Bureaucrat with `<<`; `try` creating grade 0 and 151; `raiseGrade()` at 1; `lowerGrade()` at 150 (each throws, caught as `std::exception &`).
   - **ex01**: add a **failed** signature (grade 100 tries a form that needs 50 → "couldn't sign ... because ...").
   - **ex02**: add `std::srand(std::time(NULL));` once at the top (otherwise the robotomy gives the same result every run, but it must be 50/50). Test all 3 forms with a grade 1 bureaucrat, executing an **unsigned** form, and executing with a grade that's **too low**.
   - **ex03**: `makeForm("robotomy request", "Bender")` → sign → execute → delete, plus an unknown name that returns NULL.

## 🟡 Small things
- After restoring, `ex03/Intern.hpp` gets back a commented-out exception class written inline. Delete those comment lines so the evaluator doesn't see code in the header.

## What your code does
| ex | Remember this |
|---|---|
| ex00 | `const std::string _name`, `int _grade`. The constructor throws `GradeTooHighException` (< 1) or `GradeTooLowException` (> 150). `raiseGrade()` = `_grade--` (1 is the best), throws at 1; `lowerGrade()` throws at 150. The exception classes are nested in Bureaucrat and inherit `std::exception`, overriding `what()`. `operator=` copies only the grade (the name is const). |
| ex01 | `Form`: const name, `_isSigned`, const sign/exec grades, checked in the constructor. `beSigned(b)`: signs if `b.getGrade() <= _gradeToSign`, else throws `GradeTooLowException`. `Bureaucrat::signForm()` calls `beSigned` in a `try` and prints "signed" or "couldn't sign ... because `e.what()`". |
| ex02 | `AForm` is abstract: `virtual void execute(...) const = 0;`. Each form's `execute()` first calls `checkExecReqs()` (throws `FormNotSignedException` or `GradeTooLowException`), then does its action. Shrubbery writes trees with `ofstream` to `<target>_shrubbery`; Robotomy uses `rand() % 2`; Pardon prints Zaphod. `executeForm()` = `try { form.execute(*this); }`. |
| ex03 | `makeForm()` has 2 parallel arrays: the names (`"shrubbery creation"`, `"robotomy request"`, `"presidential pardon"`) and pointers to member functions (`&Intern::_makeShrubberyCreationForm`...). It loops, finds the name, calls `(this->*formCreators[i])(target)`, which returns `new XxxForm(target)`. Unknown → error message + `NULL`. The caller must `delete` the form. |

## The sheet will ask you
- Why do the exceptions inherit from `std::exception`? (so one `catch (std::exception &e)` catches them all, and `what()` gives the message)
- Why an array of member-function pointers in Intern instead of if/else?
