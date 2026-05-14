/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrass <magrass@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 00:00:00 by magrass           #+#    #+#             */
/*   Updated: 2026/05/14 20:32:33 by magrass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int	find_smallest(t_stack *s)
{
	int		min;
	size_t	i;

	min = s->arr[0];
	i = 1;
	while (i < s->size)
	{
		if (s->arr[i] < min)
			min = s->arr[i];
		i++;
	}
	return (min);
}

static int	find_largest(t_stack *s)
{
	int		max;
	size_t	i;

	max = s->arr[0];
	i = 1;
	while (i < s->size)
	{
		if (s->arr[i] > max)
			max = s->arr[i];
		i++;
	}
	return (max);
}

static int	cost_to_top(size_t i, size_t size)
{
	int	fwd;
	int	rev;

	fwd = (int)(size - 1 - i);
	rev = -(int)i;
	if (fwd <= -rev)
		return (fwd);
	return (rev);
}

static size_t	target_in_b(t_stack *b, int val)
{
	int		best;
	size_t	best_idx;
	size_t	i;

	if (!b->size)
		return (0);
	best = INT_MIN;
	best_idx = 0;
	i = 0;
	while (i < b->size)
	{
		if (b->arr[i] > val && b->arr[i] > best)
		{
			best = b->arr[i];
			best_idx = i;
		}
		i++;
	}
	if (best == INT_MIN)
	{
		if (find_largest(b) == b->arr[b->size - 1])
			return (0);
		return (b->size - 1);
	}
	return (best_idx);
}

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

static int	combined_cost(int a_cost, int b_cost)
{
	bool	same_direction;

	same_direction = (a_cost >= 0 && b_cost >= 0)
		|| (a_cost <= 0 && b_cost <= 0);
	if (same_direction)
		return (ft_max(ft_abs(a_cost), ft_abs(b_cost)));
	return (ft_abs(a_cost) + ft_abs(b_cost));
}

typedef struct s_move {
	size_t	a_idx;
	size_t	b_idx;
	int		a_cost;
	int		b_cost;
	int		total;
}	t_move;

static t_move	best_push_to_b(t_stack *a, t_stack *b)
{
	t_move	best;
	t_move	cur;
	size_t	b_idx;
	int		a_cost;
	int		b_cost;
	size_t	i;

	best.total = INT_MAX;
	i = 0;
	while (i < a->size)
	{
		b_idx = target_in_b(b, a->arr[i]);
		a_cost = cost_to_top(i, a->size);
		b_cost = cost_to_top(b_idx, b->size);
		cur = (t_move){.a_idx = i, .b_idx = b_idx, .a_cost = a_cost, .b_cost = b_cost, .total = combined_cost(a_cost, b_cost) + 1};
		if (cur.total < best.total)
			best = cur;
		i++;
	}
	return (best);
}

static void	rotate_to_top_a(t_stack *a, int cost)
{
	while (cost > 0)
	{
		ra(a); 
		cost--;
	}
	while (cost < 0)
	{
		rra(a); 
		cost++;
	}
}

static void	rotate_to_top_b(t_stack *b, int cost)
{
	while (cost > 0)
	{
		rb(b); 
		cost--;
	}
	while (cost < 0)
	{
		rrb(b);
		cost++;
	}
}

static void	do_b_push(t_stack *a, t_stack *b, t_move m)
{
	int	ac;
	int	bc;

	ac = m.a_cost;
	bc = m.b_cost;
	while (ac > 0 && bc > 0)
	{ 
		rr(a, b);
		ac--;
		bc--; 
	}
	while (ac < 0 && bc < 0)
	{ 
		rrr(a, b);
		ac++;
		bc++;

	}
	rotate_to_top_a(a, ac);
	rotate_to_top_b(b, bc);
	pb(a, b);
}

static void	find_which_best_to_push_to_b_and_then_do_that(t_stack *a, t_stack *b)
{
	t_move	m;

	while (a->size > 2)
	{
		m = best_push_to_b(a, b);
		do_b_push(a, b, m);
	}
	if (a->arr[a->size - 1] > a->arr[a->size - 2])
		sa(a);
}

/*
** For phase 2: find where in A (descending top→bottom after sorting) val goes.
** A is being rebuilt ascending top→bottom, so we want val above the first
** element smaller than val.
*/
static size_t	target_in_a(t_stack *a, int val)
{
	int		best_contender_for_pushing;
	size_t	best_i;
	size_t	i;

	best_contender_for_pushing = INT_MAX;
	best_i = 0;
	i = 0;
	while (i < a->size)
	{
		if (a->arr[i] < val && a->arr[i] > best_contender_for_pushing)
		{
			best_contender_for_pushing = a->arr[i];
			best_i = i;
		}
		i++;
	}
	if (best_contender_for_pushing == INT_MAX)
	{
		if (find_smallest(a) == a->arr[a->size - 1])
			return (0);
		return (a->size - 1);
	}
	return (best_i);
}

static void	pull_back_to_b_in_sorted_order(t_stack *a, t_stack *b)
{
	size_t	tgt;
	int		cost;

	while (b->size)
	{
		tgt = target_in_a(a, b->arr[b->size - 1]);
		cost = cost_to_top(tgt, a->size);
		rotate_to_top_a(a, cost);
		pa(a, b);
	}
}

/*
** Final rotation: put the minimum element on top of A.
*/
static void	rotate_min_to_top(t_stack *a)
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
	rotate_to_top_a(a, cost);
}

void	turk_sort(t_stack *a, t_stack *b)
{
	if (a->size <= 1)
		return ;
	if (a->size == 2)
	{
		if (a->arr[a->size - 1] > a->arr[a->size - 2])
			sa(a);
		return ;
	}
	find_which_best_to_push_to_b_and_then_do_that(a, b);
	pull_back_to_b_in_sorted_order(a, b);
	rotate_min_to_top(a);
}
