/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrass <magrass@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 22:28:48 by magrass           #+#    #+#             */
/*   Updated: 2026/05/15 22:28:48 by magrass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "turk.h"

int	cost_to_top(size_t i, size_t size)
{
	int	fwd;
	int	rev;

	fwd = (int)(size - 1 - i);
	rev = -(int)i;
	if (fwd <= -rev)
		return (fwd);
	return (rev);
}

int	combined_cost(int a_cost, int b_cost)
{
	bool	same_direction;

	same_direction = (a_cost >= 0 && b_cost >= 0);
	if (!same_direction)
		same_direction = (a_cost <= 0 && b_cost <= 0);
	if (same_direction)
		return (ft_max(ft_abs(a_cost), ft_abs(b_cost)));
	return (ft_abs(a_cost) + ft_abs(b_cost));
}

void	rotate_to_top_a(t_stack *a, int cost, t_bench *bench)
{
	while (cost > 0)
	{
		ra(a, bench);
		cost--;
	}
	while (cost < 0)
	{
		rra(a, bench);
		cost++;
	}
}

void	rotate_to_top_b(t_stack *b, int cost, t_bench *bench)
{
	while (cost > 0)
	{
		rb(b, bench);
		cost--;
	}
	while (cost < 0)
	{
		rrb(b, bench);
		cost++;
	}
}
