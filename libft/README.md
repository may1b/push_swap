*This project has been created as part of the 42 curriculum by ascheufe.*

# Libft

Your very first own library

---

## Description

Libft is a custom C library that reimplements a set of standard C library (libc) functions, along with additional utility functions and a linked list API.

The library is divided into three main parts:

1. **Libc functions** – Reimplementations of standard functions (e.g. `strlen`, `memcpy`, `atoi`)
2. **Additional functions** – Higher-level utilities (e.g. `ft_split`, `ft_itoa`, `ft_strjoin`)
3. **Linked list functions** – A full API to create and manipulate linked lists

This library will be reused throughout the 42 curriculum.

---

## Instructions

### Compilation

To compile the library, run:

```bash
make
```

This will generate:

```
libft.a
```

### Available Makefile rules

```bash
make        # Compile the library
make all    # Same as make
make clean  # Remove object files
make fclean # Remove object files + library
make re     # Recompile everything
```

### Usage

Include the header in your project:

```c
#include "libft.h"
```

Compile your program with the library:

```bash
cc main.c -Wall -Wextra -Werror -L. -lft
```

---

## Library Overview

### Part 1 – Libc Functions

Reimplemented standard functions:

* Character checks:
  `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`

* String handling:
  `ft_strlen`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`

* Memory handling:
  `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`

* Conversions:
  `ft_atoi`

* Case conversion:
  `ft_tolower`, `ft_toupper`

* Allocation:
  `ft_calloc`, `ft_strdup`

---

### Part 2 – Additional Functions

Higher-level utilities:

* `ft_substr` – Extract substring
* `ft_strjoin` – Concatenate strings
* `ft_strtrim` – Trim characters from start/end
* `ft_split` – Split string into array
* `ft_itoa` – Convert int to string
* `ft_strmapi` – Map function to string
* `ft_striteri` – Iterate over string

File descriptor output:

* `ft_putchar_fd`
* `ft_putstr_fd`
* `ft_putendl_fd`
* `ft_putnbr_fd`

---

### Part 3 – Linked List API

Custom linked list implementation using:

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
} t_list;
```

Available functions:

* Creation:
  `ft_lstnew`

* Manipulation:
  `ft_lstadd_front`, `ft_lstadd_back`

* Inspection:
  `ft_lstsize`, `ft_lstlast`

* Memory management:
  `ft_lstdelone`, `ft_lstclear`

* Iteration & mapping:
  `ft_lstiter`, `ft_lstmap`

---

* The library is built using `ar` (static library)

---

## Resources

### Documentation

* `man` pages (e.g. `man strlen`, `man malloc`)
* 42 intra subject PDF 
* Styling convention: https://github.com/42School/norminette/blob/master/pdf/en.norm.pdf

### Helpful references

* https://linux.die.net/
* https://man.freebsd.org/cgi/man.cgi
