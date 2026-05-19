/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_cost.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrass <magrass@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 00:00:00 by magrass           #+#    #+#             */
/*   Updated: 2026/05/19 00:00:00 by magrass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a_cost(t_stack *a, int cost, t_bench *bench)
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

void	rotate_b_cost(t_stack *b, int cost, t_bench *bench)
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
