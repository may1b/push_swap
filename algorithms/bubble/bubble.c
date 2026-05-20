/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascheufe <ascheufe@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 11:52:59 by ascheufe          #+#    #+#             */
/*   Updated: 2026/05/19 14:46:17 by ascheufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	fix_rotation(t_stack *stack_a, t_bench *bench)
{
	size_t	i;
	size_t	min_index;

	min_index = 0;
	i = 1;
	while (i < stack_a->size)
	{
		if (stack_a->arr[i] < stack_a->arr[min_index])
			min_index = i;
		i++;
	}
	if (min_index <= stack_a->size / 2)
	{
		while (min_index--)
			ra(stack_a, bench);
	}
	else
	{
		while (min_index++ < stack_a->size)
			rra(stack_a, bench);
	}
}

static size_t	bubble_sort_pass(t_stack *a, bool (*rotate)(t_stack *,
		t_bench *), size_t steps, t_bench *bench)
{
	size_t	i;
	size_t	swaps;

	i = 0;
	swaps = 0;
	while (i < steps)
	{
		if (a->arr[0] > a->arr[1])
		{
			sa(a, bench);
			swaps++;
		}
		rotate(a, bench);
		i++;
	}
	return (swaps);
}

void	bubble_sort(t_stack *stack_a, t_bench *bench)
{
	size_t	pass;
	size_t	swaps;
	size_t	i;

	pass = 0;
	i = 0;
	while (i < stack_a->size / 2)
	{
		swaps = bubble_sort_pass(stack_a, ra, stack_a->size - 1 - pass, bench);
		if (swaps == 0)
		{
			fix_rotation(stack_a, bench);
			return ;
		}
		pass++;
		swaps = bubble_sort_pass(stack_a, rra, stack_a->size - 1 - pass, bench);
		if (swaps == 0)
		{
			fix_rotation(stack_a, bench);
			return ;
		}
		pass++;
		i++;
	}
	fix_rotation(stack_a, bench);
}
