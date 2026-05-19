/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_helpers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrass <magrass@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 00:00:00 by magrass           #+#    #+#             */
/*   Updated: 2026/05/19 00:00:00 by magrass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

size_t	k_value_index(t_stack *b, int val)
{
	size_t	i;

	i = 0;
	while (i < b->size)
	{
		if (b->arr[i] == val)
			return (i);
		i++;
	}
	return (0);
}

void	k_pull_max(t_stack *a, t_stack *b, t_bench *bench)
{
	size_t	i;

	i = stack_max_index(b);
	if (i <= b->size / 2)
		while (i--)
			rb(b, bench);
	else
		while (i++ < b->size)
			rrb(b, bench);
	pa(a, b, bench);
}

bool	k_pull_pair_if_cheaper(t_stack *a, t_stack *b, t_bench *bench)
{
	int		max_cost;
	int		second_cost;
	size_t	max_i;
	size_t	second_i;

	if (b->size < 2)
		return (false);
	max_i = k_value_index(b, (int)b->size - 1);
	second_i = k_value_index(b, (int)b->size - 2);
	max_cost = ps_cost_to_top(max_i, b->size);
	second_cost = ps_cost_to_top(second_i, b->size);
	if (ps_abs(second_cost) + 2 >= ps_abs(max_cost))
		return (false);
	rotate_b_cost(b, second_cost, bench);
	pa(a, b, bench);
	k_pull_max(a, b, bench);
	sa(a, bench);
	return (true);
}
