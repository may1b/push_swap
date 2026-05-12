/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrass <magrass@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 09:58:26 by ascheufe          #+#    #+#             */
/*   Updated: 2026/05/12 22:22:00 by magrass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#define OUTPUT 1

// ################################# HELPER START #####################################
// Swap the first two elements at the top of a stack
bool	swap(t_stack *stack)
{
	int	last_el;

	if (stack->size < 2)
		return (false);
	last_el = stack->arr[stack->size - 1];
	stack->arr[stack->size - 1] = stack->arr[stack->size];
	stack->arr[stack->size] = last_el;
	return (true);
}
// Take the first element at the top of Stack A and put it at the top of B.
bool	push(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a->size)
		return (false);
	stack_b->arr[stack_b->size++] = stack_a->arr[--(stack_a->size)];
	return (true);
}
// Shifts the 
bool shift(t_stack *stack, bool reverse)
{
	int	tmp;
	
	if (!stack->size)
		return (false);
	if (reverse)
	{
		tmp = stack->arr[0];
		ft_memmove(stack->arr, stack->arr + 1, stack->top * sizeof(int));
		stack->arr[stack->top] = tmp;
		return (true);
	}
	tmp = stack->arr[stack->top];
	ft_memmove(stack->arr + 1, stack->arr, stack->top * sizeof(int));
	stack->arr[0] = tmp;
	return (true);
}
// ################################# HELPER END #####################################

// Swap the first two elements at the top of stack A
bool sa(t_stack *stack_a)
{
	if (!swap(stack_a))
		return (false);
	write(OUTPUT, "sa\n", 3);
	return (true);
}

// Swap the first two elements at the top of stack B
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
    if (!stack_a->size || !stack_b->size)
        return (false);
    swap(stack_a);
    swap(stack_b);
    write(OUTPUT, "ss\n", 3);
    return (true);
}

// Take the first element at the top of B and put it at the top of A
bool pa(t_stack *stack_a, t_stack *stack_b)
{
	if (!push(stack_b, stack_a))
		return (false);
	write(OUTPUT, "pa\n", 3);
	return (true);
}

// Take the first element at the top of A and put it at the top of B
bool pb(t_stack *stack_a, t_stack *stack_b)
{
	if (!push(stack_a, stack_b))
		return (false);
	write(OUTPUT, "pb\n", 3);
	return (true);
}

// Shift up all elements of stack A by one
bool ra(t_stack *stack_a)
{
	if (!shift(stack_a, false))
		return (false);
	write(OUTPUT, "ra\n", 3);
	return (true);
}

// Shift up all elements of stack B by one
bool rb(t_stack *stack_b)
{
	if (!shift(stack_b, false))
		return (false);
	write(OUTPUT, "rb\n", 3);
	return (true);
}

// ra and rb at the same time
bool rr(t_stack *stack_a, t_stack *stack_b)
{
    if (!stack_a->size || !stack_b->size)
        return (false);
    shift(stack_a, false);
    shift(stack_b, false);
    write(OUTPUT, "rr\n", 3);
    return (true);
}

// Shift down all elements of stack A by one
bool rra(t_stack *stack_a)
{
	if (!shift(stack_a, true))
		return (false);
	write(OUTPUT, "rra\n", 4);
	return (true);
}

// Shift down all elements of stack B by one
bool	rrb(t_stack *stack_b)
{
	if (!shift(stack_b, true))
		return (false);
	write(OUTPUT, "rrb\n", 4);
	return (true);
}

// rra and rrb at the same time
bool	rrr(t_stack *stack_a, t_stack *stack_b)
{
    if (stack_a->size || !stack_b->size)
        return (false);
    shift(stack_a, true);
    shift(stack_b, true);
    write(OUTPUT, "rrr\n", 4);
    return (true);
}