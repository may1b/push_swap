/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascheufe <ascheufe@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 09:25:10 by ascheufe          #+#    #+#             */
/*   Updated: 2026/05/19 13:46:56 by ascheufe         ###   ########.fr       */
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

bool	sa(t_stack *stack_a, t_bench *bench);
bool	sb(t_stack *stack_b, t_bench *bench);
bool	ss(t_stack *stack_a, t_stack *stack_b, t_bench *bench);
bool	pa(t_stack *stack_a, t_stack *stack_b, t_bench *bench);
bool	pb(t_stack *stack_a, t_stack *stack_b, t_bench *bench);
bool	ra(t_stack *stack_a, t_bench *bench);
bool	rb(t_stack *stack_b, t_bench *bench);
bool	rr(t_stack *stack_a, t_stack *stack_b, t_bench *bench);
bool	rra(t_stack *stack_a, t_bench *bench);
bool	rrb(t_stack *stack_b, t_bench *bench);
bool	rrr(t_stack *stack_a, t_stack *stack_b, t_bench *bench);
bool	stack_swap(t_stack *stack);
bool	stack_push(t_stack *from, t_stack *to);
bool	stack_shift(t_stack *stack, bool reverse);

void	error_fun(int error);
void	print_bench_report(t_bench bench);
size_t	count_numbers(char **argv, int argc);

t_stack	parse_input(int argc, char **argv, t_args *args);
t_sv	next_token(const char *str, size_t *pos);
void	push_token(t_sv token, t_stack *stack, t_args *args);
float	disorder(t_stack *stack);
bool	has_dup(t_stack *numb);
void	bubble_sort(t_stack *stack_a, t_bench *bench);
void	partial_bubble(t_stack *a, t_bench *bench, size_t max_passes);
void	lis_sort(t_stack *a, t_stack *b, t_bench *bench);
void	small_sort(t_stack *a, t_stack *b, t_bench *bench);
void	k_sort(t_stack *a, t_stack *b, t_bench *bench);
void	ranking(t_stack *stack);
int		ps_abs(int n);
int		ps_cost_to_top(size_t i, size_t size);
size_t	stack_min_index(t_stack *a);
size_t	stack_max_index(t_stack *a);
void	rotate_a_cost(t_stack *a, int cost, t_bench *bench);
void	rotate_b_cost(t_stack *b, int cost, t_bench *bench);
size_t	k_value_index(t_stack *b, int val);
void	k_pull_max(t_stack *a, t_stack *b, t_bench *bench);
bool	k_pull_pair_if_cheaper(t_stack *a, t_stack *b, t_bench *bench);
void	lis_mark(t_stack *a, bool keep[MAX_SIZE]);
size_t	lis_target_successor(t_stack *a, int val);
int		lis_move_cost(int a_cost, int b_cost);
#endif
