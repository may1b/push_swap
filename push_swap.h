/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascheufe <ascheufe@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 09:25:10 by ascheufe          #+#    #+#             */
/*   Updated: 2026/05/08 12:25:18 by ascheufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <errno.h>	// We are allowed to use exit() So might as well use proper exitcodes!
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include "libft/libft.h"

#define ERROR_OUT 2
#define STAND_OUT 1
#define MAX_SIZE 500


typedef struct s_stack {
    int arr[MAX_SIZE];  
	int top;        
} t_stack;

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

bool	input_handler(int argc, char **argv);
// Prints "ERROR\n" and then exits using the exitcode provided
void	error_fun(int error);



// Input file
int	selected_alg(char **argv);




// check str
int	*check_string(char *argv);
int	*create_num_arr(char *str);
bool has_dup(int *numbers);
bool is_just_num(char *str);

#endif