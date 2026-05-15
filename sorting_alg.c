/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_alg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascheufe <ascheufe@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 11:52:59 by ascheufe          #+#    #+#             */
/*   Updated: 2026/05/15 10:51:24 by ascheufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	bubble_sort_pass(t_stack *a, bool (*rotate)(t_stack *,
		t_bench *), size_t steps, t_bench *bench)
{
	size_t	i;
	size_t	swaps;

	i = 0;
	swaps = 0;
	while (i < steps)
	{
		if (a->arr[a->size - 1] < a->arr[a->size - 2])
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

	pass = 0;
	while (pass < stack_a->size / 2)
	{
		swaps = bubble_sort_pass(stack_a, ra, stack_a->size - 2 - pass, bench);
		swaps += bubble_sort_pass(stack_a, rra, stack_a->size - 2 - pass,
				bench);
		if (!swaps)
			return ;
		pass++;
	}
}
