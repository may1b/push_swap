/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascheufe <ascheufe@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 16:16:23 by ascheufe          #+#    #+#             */
/*   Updated: 2026/04/27 14:49:03 by ascheufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <stddef.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

// Checks if input is a letter or number | Returns (1) if true
int			ft_isalnum(int c);
// Checks if input is a letter | Returns (1) if true
int			ft_isalpha(int c);
// Checks if input is ascii | Returns (1) if true
int			ft_isascii(int c);
// Checks if input is a digit | Returns (1) if true
int			ft_isdigit(int c);
// Checks if input is printable | Returns (1) if true
int			ft_isprint(int c);

// Converts input to lowercase if uppercase
int			ft_tolower(int c);
// Converts input to uppercase if lowercase
int			ft_toupper(int c);

// Returns the length of input string
size_t		ft_strlen(const char *s);
// Locate character in string 
char		*ft_strchr(const char *s, int d);
// Duplicates string
char		*ft_strdup(const char *src);
// Joins two strings together
char		*ft_strjoin(char const *s1, char const *s2);
// Appends on string onto the other
size_t		ft_strlcat(char *dst, const char *src, size_t size);
// Copies source string to dest with a max size
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
// Compares two strings with a max size
int			ft_strncmp(const char *s1, const char *s2, size_t n);
// Locates the substring in a string with a max size
char		*ft_strnstr(const char *big, const char *little, size_t size);
// Locates the last occurrence of the char in string
char		*ft_strrchr(const char *s, int d);
// Trims the first and last chars of a string with a char set
char		*ft_strtrim(char const *s1, char const *set);
// Locates substring in string
char		*ft_substr(char const *s, unsigned int start, size_t len);
// Splits string by char. Gives back array
char		**ft_split(char const *s, char c);
// Applies the function ’f’ to each character of the string passed as argument
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
// Same as ft_striteri put returns the new string
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));

// Outputs the character ’c’ to the specified file descriptor
int			ft_putchar_fd(char c, int fd);
// Outputs the string ’s’ to the specified file descriptor
int			ft_putstr_fd(char *s, int fd);
// Outputs the string ’s’ to the specified file descriptor followed by a newline
void		ft_putendl_fd(char *s, int fd);
// Outputs the integer ’n’ with a given base
int			ft_putnbr_base(long nbr, char *base, bool is_unsigned);
// Outputs the integer ’n’ to the specified file descriptor
void		ft_putnbr_fd(int n, int fd);

// Writes zeros into memory location
void		ft_bzero(void *b, size_t len);
// Locate byte in memory object
void		*ft_memchr(const void *b, int d, size_t len);
// Compares two memory locations with each other with max len
int			ft_memcmp(const void *d1, const void *d2, size_t len);
// Copies memory (Problem if overlap) 
void		*ft_memcpy(void *dst, const void *src, size_t len);
// Moves/copies memory with overlap handling
void		*ft_memmove(void *dst, const void *src, size_t len);
// Fills memory with set char
void		*ft_memset(void *b, int c, size_t n);

// Makes a new linked list with content
t_list		*ft_lstnew(void *content);
// Adds the node ’new’ at the beginning of the list
void		ft_lstadd_front(t_list **lst, t_list *new);
// Counts the number of nodes in the list
int			ft_lstsize(t_list *lst);
// Returns the last node of the list
t_list		*ft_lstlast(t_list *lst);
// Adds the node ’new’ at the end of the list
void		ft_lstadd_back(t_list **lst, t_list *new);
// Takes a node as parameter and frees its content using the function ’del’
void		ft_lstdelone(t_list *lst, void (*del)(void*));
// Iterates through the list ’lst’ and applies the function ’f’
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
// Deletes and frees the given node and all its successor
void		ft_lstclear(t_list **lst, void (*del)(void*));
// Iterates through the list ’lst’ and applies the function ’f’ to the contents
void		ft_lstiter(t_list *lst, void (*f)(void *));

// Convert ASCII string to integer
int			ft_atoi(const char *str);
// Allocates memory with malloc protecting from overflow and writes zero bytes
void		*ft_calloc(size_t nmemb, size_t size);
// Convert integer to ASCII string
char		*ft_itoa(int n);
#endif