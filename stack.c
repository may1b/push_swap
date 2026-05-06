/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascheufe <ascheufe@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 09:58:26 by ascheufe          #+#    #+#             */
/*   Updated: 2026/05/06 11:46:55 by ascheufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#define OUTPUT 1

// ################################# HELPER START #####################################
// Swap the first two elements at the top of a stack
bool swap(t_stack *stack)
{
	int	tmp;

	if (stack->top < 1)
		return (false);
	tmp = stack->arr[stack->top];
	stack->arr[stack->top] = stack->arr[stack->top - 1];
	stack->arr[stack->top - 1] = tmp;
	return (true);
}
// Take the first element at the top of Stack A and put it at the top of B.
bool push(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b->top == -1)
		return (false);
	if (stack_a->top > 499)	// Should gard against putting over the 500 limit 
		return (write(OUTPUT, "STACK A IS FULL", 15), false);
	stack_a->arr[stack_a->top + 1] = stack_b->arr[stack_b->top];
	stack_a->top++;
	return (true);
}
// Shifts the 
bool shift(t_stack *stack, bool reverse)
{
	int	tmp;
	
	if (stack->top < 1)
		return (false);
	if (reverse)
	{
		tmp = stack->arr[stack->top];
		ft_memmove(stack->arr, stack->arr + 1, stack->top * sizeof(int));
		stack->arr[0] = tmp;
		return (true);
	}
	tmp = stack->arr[0];
	ft_memmove(stack->arr + 1, stack->arr, stack->top * sizeof(int));
	stack->arr[stack->top] = tmp;
	return (true);
}
// ################################# HELPER END #####################################

// Swap the first two elements at the top of stack a
bool sa(t_stack *stack_a)
{
	if (!swap(stack_a))
		return (false);
	write(OUTPUT, "sa\n", 3);
	return (true);
}

// Swap the first two elements at the top of stack b
bool sb(t_stack *stack_b)
{
	if (!swap(stack_b))
		return (false);
	write(OUTPUT, "sb\n", 3);
	return (true);
}

// sa and sb at the same time
bool ss(t_stack *stack_a, t_stack *stack_b)
{
    if (stack_a->top < 1 || stack_b->top < 1)
        return (false);
    swap(stack_a);
    swap(stack_b);
    write(OUTPUT, "ss\n", 3);
    return (true);
}

// Take the first element at the top of b and put it at the top of a
bool pa(t_stack *stack_a, t_stack *stack_b)
{
	if (!push(stack_a, stack_b))
		return (false);
	write(OUTPUT, "pa\n", 3);
	return (true);
}

// Take the first element at the top of a and put it at the top of b
bool pb(t_stack *stack_a, t_stack *stack_b)
{
	if (!push(stack_b, stack_a))
		return (false);
	write(OUTPUT, "pb\n", 3);
	return (true);
}

bool ra(t_stack *stack_a)
{
	if (!shift(stack_a, false))
		return (false);
	write(OUTPUT, "ra\n", 3);
	return (true);
}

bool rb(t_stack *stack_b)
{
	if (!shift(stack_b, false))
		return (false);
	write(OUTPUT, "rb\n", 3);
	return (true);
}

bool rr(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->top < 1 || stack_a->top < 1)
		return (false);
	ra(stack_a);
	ra(stack_a);
	return (true);
}

bool rra(t_stack *stack_a)
{
	if (!shift(stack_a, true))
		return (false);
	write(OUTPUT, "ra\n", 3);
	return (true);
}

bool rrb(t_stack *stack_b)
{
	if (!shift(stack_b, true))
		return (false);
	write(OUTPUT, "rb\n", 3);
	return (true);
}

bool rrr(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->top < 1 || stack_a->top < 1)
		return (false);
	ra(stack_a);
	ra(stack_a);
	return (true);
}