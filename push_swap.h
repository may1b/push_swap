/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrass <magrass@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 09:25:10 by ascheufe          #+#    #+#             */
/*   Updated: 2026/05/14 17:38:13 by magrass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <errno.h>
#include <limits.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include "libft/libft.h"

#define ERROR_OUT 2
#define STAND_OUT 1
#define MAX_SIZE 500


typedef struct s_stack {
    int arr[MAX_SIZE];  
    size_t size;
} t_stack;

typedef enum e_alg
{
    ALG_NONE,
	ALG_SIMPLE,
    ALG_MEDIUM,
    ALG_COMPLEX,
    ALG_ADAPTIVE,
}   t_alg;

typedef struct s_arena_block {
	struct s_arena_block	*next;
	size_t					capacity;
	size_t					used;
}	t_arena_block;

typedef struct s_arena {
	t_arena_block	*head;
	size_t			default_capacity;
}	t_arena;

t_arena	*arena_new(size_t capacity);
void	*arena_alloc(t_arena *a, size_t size);
void	arena_destroy(t_arena *a);

typedef struct s_sv {
	const char	*str;
	size_t		size;
}	t_sv;

t_sv	sv_from_cstr(const char *str);
bool	sv_eq(t_sv a, const char *b);

// Stack function START
// Swap the first two elements at the top of stack A
bool sa(t_stack *stack_a);

// Swap the first two elements at the top of stack B
bool sb(t_stack *stack_b);

// sa and sb at the same time
bool ss(t_stack *stack_a, t_stack *stack_b);

// Take the first element at the top of B and put it at the top of A
bool pa(t_stack *stack_a, t_stack *stack_b);

// Take the first element at the top of A and put it at the top of B
bool pb(t_stack *stack_a, t_stack *stack_b);

// Shift up all elements of stack A by one
bool ra(t_stack *stack_a);

// Shift up all elements of stack B by one
bool rb(t_stack *stack_b);

// ra and rb at the same time
bool rr(t_stack *stack_a, t_stack *stack_b);

// Shift down all elements of stack A by one
bool rra(t_stack *stack_a);

// Shift down all elements of stack B by one
bool rrb(t_stack *stack_b);

// rra and rrb at the same time
bool	rrr(t_stack *stack_a, t_stack *stack_b);

// Stack function STOP

t_stack	parse_input(int argc, char **argv, t_alg *alg_selected);
// Prints "ERROR\n" and then exits using the exitcode provided
void	error_fun(int error);



bool	has_dup(t_stack *numb);
void	bubble_sort(t_stack *stack_a);
void	turk_sort(t_stack *a, t_stack *b);
float disorder(t_stack *stack);
#endif