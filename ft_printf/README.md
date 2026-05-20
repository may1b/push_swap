*This project has been created as part of the 42 curriculum by <login>.*

# ft_printf

## Description

`ft_printf` is a C library that reimplements the standard `printf()` function from libc. The goal is to understand variadic functions in C — functions that accept a variable number of arguments — by building a clean, well-structured, and extensible version from scratch.

The library is compiled into a static archive `libftprintf.a` and supports the most common format specifiers used in everyday C programming.

## Supported Conversions

| Specifier | Description |
|-----------|-------------|
| `%c` | Prints a single character |
| `%s` | Prints a string |
| `%p` | Prints a pointer address in hexadecimal |
| `%d` | Prints a decimal (base 10) integer |
| `%i` | Prints an integer in base 10 |
| `%u` | Prints an unsigned decimal (base 10) number |
| `%x` | Prints a number in hexadecimal (lowercase) |
| `%X` | Prints a number in hexadecimal (uppercase) |
| `%%` | Prints a literal percent sign |

## Instructions

### Compilation

Clone the repository and run `make` at its root:

```bash
make
make clean # optionally cleans up the object (.o) files
```

This will compile all source files and produce `libftprintf.a` at the root of the repository.

### Using the library in your project

Include the header and link against the archive when compiling:

```c
#include "ft_printf.h"
```

```bash
cc -Wall -Wextra -Werror main.c -L. -lftprintf -o main
```

### Makefile rules

| Rule | Description |
|------|-------------|
| `make` / `make all` | Compiles the library |
| `make clean` | Removes object files |
| `make fclean` | Removes object files and `libftprintf.a` |
| `make re` | Runs `fclean` then `all` |

## Resources

- [printf(3) man page](https://man7.org/linux/man-pages/man3/printf.3.html)
- [stdarg(3) man page — variadic functions](https://man7.org/linux/man-pages/man3/stdarg.3.html)

### AI usage

AI was used to ask about the usage of variadic functions.
Otherwise I wrote all of the code myself.
