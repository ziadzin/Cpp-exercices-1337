# Module 09 · quick review

ex01 and ex02 work (I ran the sheet's RPN tests and the 3000-number test). **ex00 has a leftover debug print and the wrong database.**

## 🔴 Fix before pushing
1. **ex00 `BitcoinExchange.cpp:17`**: delete `std::cout << year << std::endl;`. Right now every input line first prints the year (`2011`, `2012`...) above the result.
2. **ex00 `data.csv`** is a 9-line sample you made. The subject provides the real database (~1600 lines, 2009 → 2022) in the attachment on the intra project page. The evaluator compares dates against it, so put the real `data.csv` in `ex00/`.
3. **ex00 `BitcoinExchange.cpp:22`**: any day up to 31 is accepted, so `2011-02-30` or `2011-04-31` gives a result. The sheet says "use a wrong date". Check the days per month (February: 29 in leap years, else 28).

## 🟡 Small risk (1 line)
- **ex01 `RPN.hpp:10`**: `std::stack<int>` uses a `std::deque` inside, and ex02 uses `std::deque`. The rule is "a container used once can't be used again". Most evaluators accept it, but to remove any doubt: `std::stack<int, std::list<int> > _stack;` (+ `#include <list>`).

## What your code does
| ex | Remember this |
|---|---|
| ex00 | **`std::map<std::string, double>`** date → rate. A map is sorted by key, and `YYYY-MM-DD` strings sort like dates. `loadDatabase` reads `data.csv` (skips the header, splits on `,`). `processInput` reads each line, splits on `" \| "`, checks date and value (0..1000), then `upper_bound(date)` gives the first date **after** it; one step back (`--it`) is the same or the closest lower date. Nothing before it → error. |
| ex01 | **`std::stack<int>`**: RPN is LIFO. Read tokens with `istringstream`: a digit → push; an operator → pop `b`, pop `a`, push `a op b`. Error if: token longer than 1 char, unknown char, fewer than 2 numbers for an operator, division by 0, or not exactly 1 number left at the end. |
| ex02 | **`std::vector`** and **`std::deque`**, same algorithm written twice. Parse: only digits allowed, ≤ INT_MAX. Sort (Ford-Johnson): pair the numbers, the bigger of each pair goes to `chain`, the smaller to `pend`; sort `chain` recursively; insert `pend[0]`, then the rest in **Jacobsthal order** (1, 3, 5, 11, 21...) going backwards inside each group, each one with a binary search (`upper_bound`). Time with `clock()`, printed in µs. |

## The sheet will ask you
- Why a map in ex00? (sorted keys + `upper_bound` = closest lower date)
- Why a stack in ex01? (RPN = last in, first out)
- Explain Ford-Johnson in 3 sentences (above), and why vector vs deque timings differ (vector is one contiguous block, deque is split into chunks; inserting in the middle costs differently).
- ⚠️ Your version doesn't track which `pend` number was paired with which `chain` number after the recursive sort, so every insertion searches the whole chain. It still sorts correctly, and the pairing, recursion and Jacobsthal order are there. If asked, say it's a simplified Ford-Johnson.
