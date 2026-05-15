/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrass <magrass@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 22:28:48 by magrass           #+#    #+#             */
/*   Updated: 2026/05/15 22:28:48 by magrass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "turk.h"

t_move	best_push_to_b(t_stack *a, t_stack *b)
{
	t_move	best;
	t_move	cur;
	size_t	b_idx;
	t_cost	cost;
	size_t	i;

	best.total = INT_MAX;
	i = 0;
	while (i < a->size)
	{
		b_idx = target_in_b(b, a->arr[i]);
		cost.a = cost_to_top(i, a->size);
		cost.b = cost_to_top(b_idx, b->size);
		cur = (t_move){.a_idx = i, .b_idx = b_idx,
			.a_cost = cost.a, .b_cost = cost.b,
			.total = combined_cost(cost.a, cost.b) + 1};
		if (cur.total < best.total)
			best = cur;
		i++;
	}
	return (best);
}

void	do_b_push(t_stack *a, t_stack *b, t_move m, t_bench *bench)
{
	int	ac;
	int	bc;

	ac = m.a_cost;
	bc = m.b_cost;
	while (ac > 0 && bc > 0)
	{
		rr(a, b, bench);
		ac--;
		bc--;
	}
	while (ac < 0 && bc < 0)
	{
		rrr(a, b, bench);
		ac++;
		bc++;
	}
	rotate_to_top_a(a, ac, bench);
	rotate_to_top_b(b, bc, bench);
	pb(a, b, bench);
}
