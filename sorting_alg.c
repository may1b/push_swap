/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_alg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrass <magrass@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 11:52:59 by ascheufe          #+#    #+#             */
/*   Updated: 2026/05/14 17:04:01 by magrass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	bubble_sort_pass(t_stack *a, bool (*rotate)(t_stack *), size_t steps)
{
	size_t	i;
	size_t	swaps;

	i = 0;
	swaps = 0;
	while (i < steps)
	{
		if (a->arr[a->size - 1] < a->arr[a->size - 2])
		{
			sa(a);
			swaps++;
		}
		rotate(a);
		i++;
	}
	return (swaps);
}

void	bubble_sort(t_stack *stack_a)
{
	size_t	pass;
	size_t	swaps;

	pass = 0;
	while (pass < stack_a->size / 2)
	{
		swaps = bubble_sort_pass(stack_a, ra, stack_a->size - 2 - pass);
		swaps += bubble_sort_pass(stack_a, rra, stack_a->size - 2 - pass);
		if (!swaps)
			return ;
		pass++;
	}
}
