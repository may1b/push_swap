/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascheufe <ascheufe@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 09:58:26 by ascheufe          #+#    #+#             */
/*   Updated: 2026/05/19 13:46:56 by ascheufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	sa(t_stack *stack_a, t_bench *bench)
{
	if (!stack_swap(stack_a))
		return (false);
	write(1, "sa\n", 3);
	bench->sa++;
	return (true);
}

bool	sb(t_stack *stack_b, t_bench *bench)
{
	if (!stack_swap(stack_b))
		return (false);
	write(1, "sb\n", 3);
	bench->sb++;
	return (true);
}

bool	ss(t_stack *stack_a, t_stack *stack_b, t_bench *bench)
{
	if (!stack_a->size || !stack_b->size)
		return (false);
	stack_swap(stack_a);
	stack_swap(stack_b);
	write(1, "ss\n", 3);
	bench->ss++;
	return (true);
}

bool	pa(t_stack *stack_a, t_stack *stack_b, t_bench *bench)
{
	if (!stack_push(stack_b, stack_a))
		return (false);
	write(1, "pa\n", 3);
	bench->pa++;
	return (true);
}

bool	pb(t_stack *stack_a, t_stack *stack_b, t_bench *bench)
{
	if (!stack_push(stack_a, stack_b))
		return (false);
	write(1, "pb\n", 3);
	bench->pb++;
	return (true);
}
