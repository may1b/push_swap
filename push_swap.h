/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascheufe <ascheufe@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 09:25:10 by ascheufe          #+#    #+#             */
/*   Updated: 2026/05/19 12:29:20 by ascheufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <errno.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include "libft/libft.h"
# include "ft_printf.h"

# define ERROR_OUT 2
# define STAND_OUT 1
# define MAX_SIZE 500

typedef struct s_stack
{
	int		arr[MAX_SIZE];
	size_t	size;
}	t_stack;

typedef enum e_arg
{
	ARG_NONE,
	ARG_SIMPLE,
	ARG_MEDIUM,
	ARG_COMPLEX,
	ARG_ADAPTIVE,
	ARG_BENCH,
}	t_arg;

typedef struct s_bench
{
	unsigned int	total;
	unsigned int	sa;
	unsigned int	sb;
	unsigned int	ss;
	unsigned int	pa;
	unsigned int	pb;
	unsigned int	ra;
	unsigned int	rb;
	unsigned int	rr;
	unsigned int	rra;
	unsigned int	rrb;
	unsigned int	rrr;
	float			disorder;
	char			*strategy;
	char			*complexity;
}	t_bench;

typedef struct s_args
{
	int		algorithm;
	bool	bench_on;
}	t_args;

typedef struct s_arena_block
{
	struct s_arena_block	*next;
	size_t					capacity;
	size_t					used;
}	t_arena_block;

typedef struct s_data
{
	t_stack	stack_a;
	t_stack	stack_b;
	t_args	args;
	t_bench	bench;
}	t_data;

typedef struct s_arena
{
	t_arena_block	*head;
	size_t			default_capacity;
}	t_arena;

typedef struct s_chunk_range
{
	size_t	start;
	size_t	end;
}	t_chunk_range;

t_arena	*arena_new(size_t capacity);
void	*arena_alloc(t_arena *a, size_t size);
void	arena_destroy(t_arena *a);

typedef struct s_sv
{
	const char	*str;
	size_t		size;
}	t_sv;

t_sv	sv_from_cstr(const char *str);
bool	sv_eq(t_sv a, const char *b);

// * Stack function START ---------------------------

// Swap the first two elements at the top of stack A
bool	sa(t_stack *stack_a, t_bench *bench);

// Swap the first two elements at the top of stack B
bool	sb(t_stack *stack_b, t_bench *bench);

// sa and sb at the same time
bool	ss(t_stack *stack_a, t_stack *stack_b, t_bench *bench);

// Take the first element at the top of B and put it at the top of A
bool	pa(t_stack *stack_a, t_stack *stack_b, t_bench *bench);

// Take the first element at the top of A and put it at the top of B
bool	pb(t_stack *stack_a, t_stack *stack_b, t_bench *bench);

// Shift up all elements of stack A by one
bool	ra(t_stack *stack_a, t_bench *bench);

// Shift up all elements of stack B by one
bool	rb(t_stack *stack_b, t_bench *bench);

// ra and rb at the same time
bool	rr(t_stack *stack_a, t_stack *stack_b, t_bench *bench);

// Shift down all elements of stack A by one
bool	rra(t_stack *stack_a, t_bench *bench);

// Shift down all elements of stack B by one
bool	rrb(t_stack *stack_b, t_bench *bench);

// rra and rrb at the same time
bool	rrr(t_stack *stack_a, t_stack *stack_b, t_bench *bench);

// * Stack function STOP ---------------------------

// Prints "ERROR\n" and then exits using the exitcode provided
void	error_fun(int error);
void	print_bench_report(t_bench bench);
size_t	count_numbers(char **argv, int argc);

t_stack	parse_input(int argc, char **argv, t_args *args);
float	disorder(t_stack *stack);
bool	has_dup(t_stack *numb);
void	bubble_sort(t_stack *stack_a, t_bench *bench);
void	turk_sort(t_stack *a, t_stack *b, t_bench *bench);
void	ranking(t_stack *stack);

void	chunk_sort(t_stack *stack_a, t_stack *stack_b, t_bench *bench);
void	better_chunk_sort(t_stack *stack_a, t_stack *stack_b, t_bench *bench);
size_t	find_best_chunk_index(t_stack *stack, size_t min, size_t max);
void	rotate_stack_a_to_top(t_stack *stack_a, size_t index,
	t_bench *bench);
void	push_chunk_range(t_stack *stack_a, t_stack *stack_b,
	t_chunk_range range, t_bench *bench);
void	push_all_chunks(t_stack *stack_a, t_stack *stack_b,
	size_t num_chunks, t_bench *bench);
void	pull_back_stack_b(t_stack *stack_a, t_stack *stack_b,
	t_bench *bench);
#endif