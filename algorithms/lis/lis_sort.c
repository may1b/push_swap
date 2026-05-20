/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrass <magrass@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 00:00:00 by magrass           #+#    #+#             */
/*   Updated: 2026/05/20 16:42:54 by magrass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	apply_insert(t_stack *a, t_stack *b, int cost[2], t_bench *bench)
{
	while (cost[0] > 0 && cost[1] > 0)
	{
		rr(a, b, bench);
		cost[0]--;
		cost[1]--;
	}
	while (cost[0] < 0 && cost[1] < 0)
	{
		rrr(a, b, bench);
		cost[0]++;
		cost[1]++;
	}
	rotate_a_cost(a, cost[0], bench);
	rotate_b_cost(b, cost[1], bench);
}

static void	push_non_lis(t_stack *a, t_stack *b, bool keep[MAX_SIZE],
	t_bench *bench)
{
	size_t	i;
	size_t	n;

	n = a->size;
	i = 0;
	while (i < n)
	{
		if (keep[i])
			ra(a, bench);
		else
			pb(a, b, bench);
		i++;
	}
}

static void	best_insert(t_stack *a, t_stack *b, t_bench *bench)
{
	size_t	i;
	int		best;
	int		a_cost;
	int		b_cost;
	int		best_pair[2];

	best = MAX_SIZE * 2;
	i = 0;
	while (i < b->size)
	{
		a_cost = ps_cost_to_top(lis_target_successor(a, b->arr[i]), a->size);
		b_cost = ps_cost_to_top(i, b->size);
		if (lis_move_cost(a_cost, b_cost) < best)
		{
			best = lis_move_cost(a_cost, b_cost);
			best_pair[0] = a_cost;
			best_pair[1] = b_cost;
		}
		i++;
	}
	apply_insert(a, b, best_pair, bench);
	pa(a, b, bench);
}

void	lis_sort(t_stack *a, t_stack *b, t_bench *bench)
{
	bool	keep[MAX_SIZE];

	if (a->size <= 1)
		return ;
	lis_mark(a, keep);
	push_non_lis(a, b, keep, bench);
	while (b->size)
		best_insert(a, b, bench);
	rotate_a_cost(a, ps_cost_to_top(stack_min_index(a), a->size), bench);
}
