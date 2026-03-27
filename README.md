# Advanced Calculator (C++)

This project is an interactive **advanced calculator** written in C++. It provides both basic arithmetic and common scientific functions through a menu-driven interface.

## Features

- Basic arithmetic:
  - Addition
  - Subtraction
  - Multiplication
  - Division (with divide-by-zero protection)
- Advanced operations:
  - Power (`x^y`)
  - Square root
  - Trigonometric functions (`sin`, `cos`, `tan`) using degree input
  - Logarithms (`ln` and `log10`)
  - Factorial (supports whole numbers from `0` to `20`)
- Input validation for both numbers and menu choices
- Calculation history that can be viewed at any time

## Build and Run

From the project root:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o calculator
./calculator
```

## Notes

- Trigonometric inputs are entered in **degrees**.
- Factorial is limited to `0..20` to avoid integer overflow.
- History stores successful calculations only.
