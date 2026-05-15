/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrass <magrass@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 00:00:00 by magrass           #+#    #+#             */
/*   Updated: 2026/05/15 22:28:48 by magrass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "turk.h"

static void	find_which_best_to_push_to_b_and_then_do_that(
	t_stack *a,
	t_stack *b,
	t_bench *bench
)
{
	t_move	m;

	while (a->size > 2)
	{
		m = best_push_to_b(a, b);
		do_b_push(a, b, m, bench);
	}
	if (a->arr[a->size - 1] > a->arr[a->size - 2])
		sa(a, bench);
}

static void	pull_back_to_b_in_sorted_order(
	t_stack *a,
	t_stack *b,
	t_bench *bench
)
{
	size_t	tgt;
	int		cost;

	while (b->size)
	{
		tgt = target_in_a(a, b->arr[b->size - 1]);
		cost = cost_to_top(tgt, a->size);
		rotate_to_top_a(a, cost, bench);
		pa(a, b, bench);
	}
}

static void	rotate_min_to_top(t_stack *a, t_bench *bench)
{
	int		min;
	size_t	min_idx;
	size_t	i;
	int		cost;

	min = a->arr[0];
	min_idx = 0;
	i = 1;
	while (i < a->size)
	{
		if (a->arr[i] < min)
		{
			min = a->arr[i];
			min_idx = i;
		}
		i++;
	}
	cost = cost_to_top(min_idx, a->size);
	rotate_to_top_a(a, cost, bench);
}

void	turk_sort(t_stack *a, t_stack *b, t_bench *bench)
{
	if (a->size <= 1)
		return ;
	if (a->size == 2)
	{
		if (a->arr[a->size - 1] > a->arr[a->size - 2])
			sa(a, bench);
		return ;
	}
	find_which_best_to_push_to_b_and_then_do_that(a, b, bench);
	pull_back_to_b_in_sorted_order(a, b, bench);
	rotate_min_to_top(a, bench);
}
