/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrass <magrass@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 00:00:00 by magrass           #+#    #+#             */
/*   Updated: 2026/05/19 00:00:00 by magrass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ra(t_stack *stack_a, t_bench *bench)
{
	if (!stack_shift(stack_a, false))
		return (false);
	write(1, "ra\n", 3);
	bench->ra++;
	return (true);
}

bool	rb(t_stack *stack_b, t_bench *bench)
{
	if (!stack_shift(stack_b, false))
		return (false);
	write(1, "rb\n", 3);
	bench->rb++;
	return (true);
}

bool	rr(t_stack *stack_a, t_stack *stack_b, t_bench *bench)
{
	if (!stack_a->size || !stack_b->size)
		return (false);
	stack_shift(stack_a, false);
	stack_shift(stack_b, false);
	write(1, "rr\n", 3);
	bench->rr++;
	return (true);
}

bool	rra(t_stack *stack_a, t_bench *bench)
{
	if (!stack_shift(stack_a, true))
		return (false);
	write(1, "rra\n", 4);
	bench->rra++;
	return (true);
}

bool	rrb(t_stack *stack_b, t_bench *bench)
{
	if (!stack_shift(stack_b, true))
		return (false);
	write(1, "rrb\n", 4);
	bench->rrb++;
	return (true);
}
