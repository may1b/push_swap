/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascheufe <ascheufe@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 09:58:26 by ascheufe          #+#    #+#             */
/*   Updated: 2026/05/19 12:34:30 by ascheufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#define OUTPUT 1

static bool	swap(t_stack *stack)
{
	int	tmp;

	if (stack->size < 2)
		return (false);
	tmp = stack->arr[stack->size - 1];
	stack->arr[stack->size - 1] = stack->arr[stack->size - 2];
	stack->arr[stack->size - 2] = tmp;
	return (true);
}

static bool	push(t_stack *from, t_stack *to)
{
	if (!from->size)
		return (false);
	to->arr[to->size++] = from->arr[--(from->size)];
	return (true);
}

static bool	shift(t_stack *stack, bool reverse)
{
	int	tmp;

	if (!stack->size)
		return (false);
	if (reverse)
	{
		tmp = stack->arr[0];
		ft_memmove(stack->arr, stack->arr + 1, (stack->size - 1) * sizeof(int));
		stack->arr[stack->size - 1] = tmp;
	}
	else
	{
		tmp = stack->arr[stack->size - 1];
		ft_memmove(stack->arr + 1, stack->arr, (stack->size - 1) * sizeof(int));
		stack->arr[0] = tmp;
	}
	return (true);
}

bool	sa(t_stack *stack_a, t_bench *bench)
{
	if (!swap(stack_a))
		return (false);
	write(OUTPUT, "sa\n", 3);
	bench->sa++;
	return (true);
}

bool	sb(t_stack *stack_b, t_bench *bench)
{
	if (!swap(stack_b))
		return (false);
	write(OUTPUT, "sb\n", 3);
	bench->sb++;
	return (true);
}

bool	ss(t_stack *stack_a, t_stack *stack_b, t_bench *bench)
{
	if (!stack_a->size || !stack_b->size)
		return (false);
	swap(stack_a);
	swap(stack_b);
	write(OUTPUT, "ss\n", 3);
	bench->ss++;
	return (true);
}

bool	pa(t_stack *stack_a, t_stack *stack_b, t_bench *bench)
{
	if (!push(stack_b, stack_a))
		return (false);
	write(OUTPUT, "pa\n", 3);
	bench->pa++;
	return (true);
}

bool	pb(t_stack *stack_a, t_stack *stack_b, t_bench *bench)
{
	if (!push(stack_a, stack_b))
		return (false);
	write(OUTPUT, "pb\n", 3);
	bench->pb++;
	return (true);
}

bool	ra(t_stack *stack_a, t_bench *bench)
{
	if (!shift(stack_a, false))
		return (false);
	write(OUTPUT, "ra\n", 3);
	bench->ra++;
	return (true);
}

bool	rb(t_stack *stack_b, t_bench *bench)
{
	if (!shift(stack_b, false))
		return (false);
	write(OUTPUT, "rb\n", 3);
	bench->rb++;
	return (true);
}

bool	rr(t_stack *stack_a, t_stack *stack_b, t_bench *bench)
{
	if (!stack_a->size || !stack_b->size)
		return (false);
	shift(stack_a, false);
	shift(stack_b, false);
	write(OUTPUT, "rr\n", 3);
	bench->rr++;
	return (true);
}

bool	rra(t_stack *stack_a, t_bench *bench)
{
	if (!shift(stack_a, true))
		return (false);
	write(OUTPUT, "rra\n", 4);
	bench->rra++;
	return (true);
}

bool	rrb(t_stack *stack_b, t_bench *bench)
{
	if (!shift(stack_b, true))
		return (false);
	write(OUTPUT, "rrb\n", 4);
	bench->rrb++;
	return (true);
}

bool	rrr(t_stack *stack_a, t_stack *stack_b, t_bench *bench)
{
	if (!stack_a->size || !stack_b->size)
		return (false);
	shift(stack_a, true);
	shift(stack_b, true);
	write(OUTPUT, "rrr\n", 4);
	bench->rrr++;
	return (true);
}
