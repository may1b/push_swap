/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrass <magrass@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 00:00:00 by magrass           #+#    #+#             */
/*   Updated: 2026/05/19 00:00:00 by magrass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int	abs_i(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int	cost_to_top_lis(size_t i, size_t size)
{
	if (i <= size / 2)
		return ((int)i);
	return (-(int)(size - i));
}

static void	rotate_a(t_stack *a, int cost, t_bench *bench)
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

static void	rotate_b(t_stack *b, int cost, t_bench *bench)
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

static void	rotate_both(t_stack *a, t_stack *b, int a_cost, int b_cost,
	t_bench *bench)
{
	while (a_cost > 0 && b_cost > 0)
	{
		rr(a, b, bench);
		a_cost--;
		b_cost--;
	}
	while (a_cost < 0 && b_cost < 0)
	{
		rrr(a, b, bench);
		a_cost++;
		b_cost++;
	}
	rotate_a(a, a_cost, bench);
	rotate_b(b, b_cost, bench);
}

static size_t	find_min_index(t_stack *a)
{
	size_t	i;
	size_t	min_i;

	min_i = 0;
	i = 1;
	while (i < a->size)
	{
		if (a->arr[i] < a->arr[min_i])
			min_i = i;
		i++;
	}
	return (min_i);
}

static size_t	target_successor(t_stack *a, int val)
{
	size_t	i;
	size_t	best_i;
	int		best;

	best_i = find_min_index(a);
	best = MAX_SIZE + 1;
	i = 0;
	while (i < a->size)
	{
		if (a->arr[i] > val && a->arr[i] < best)
		{
			best = a->arr[i];
			best_i = i;
		}
		i++;
	}
	return (best_i);
}

static void	mark_lis(t_stack *a, bool keep[MAX_SIZE])
{
	int		len[MAX_SIZE];
	int		prev[MAX_SIZE];
	size_t	i;
	size_t	j;
	size_t	best_i;

	i = 0;
	best_i = 0;
	while (i < a->size)
	{
		keep[i] = false;
		len[i] = 1;
		prev[i] = -1;
		j = 0;
		while (j < i)
		{
			if (a->arr[j] < a->arr[i] && len[j] + 1 > len[i])
			{
				len[i] = len[j] + 1;
				prev[i] = (int)j;
			}
			j++;
		}
		if (len[i] > len[best_i])
			best_i = i;
		i++;
	}
	while ((int)best_i >= 0)
	{
		keep[best_i] = true;
		if (prev[best_i] < 0)
			break ;
		best_i = (size_t)prev[best_i];
	}
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

static int	move_cost(int a_cost, int b_cost)
{
	if ((a_cost >= 0 && b_cost >= 0) || (a_cost <= 0 && b_cost <= 0))
	{
		if (abs_i(a_cost) > abs_i(b_cost))
			return (abs_i(a_cost));
		return (abs_i(b_cost));
	}
	return (abs_i(a_cost) + abs_i(b_cost));
}

static void	best_insert(t_stack *a, t_stack *b, t_bench *bench)
{
	size_t	i;
	size_t	target;
	int		best;
	int		a_cost;
	int		b_cost;
	int		best_a;
	int		best_b;

	best = MAX_SIZE * 2;
	i = 0;
	while (i < b->size)
	{
		target = target_successor(a, b->arr[i]);
		a_cost = cost_to_top_lis(target, a->size);
		b_cost = cost_to_top_lis(i, b->size);
		if (move_cost(a_cost, b_cost) < best)
		{
			best = move_cost(a_cost, b_cost);
			best_a = a_cost;
			best_b = b_cost;
		}
		i++;
	}
	rotate_both(a, b, best_a, best_b, bench);
	pa(a, b, bench);
}

void	lis_sort(t_stack *a, t_stack *b, t_bench *bench)
{
	bool	keep[MAX_SIZE];

	if (a->size <= 1)
		return ;
	mark_lis(a, keep);
	push_non_lis(a, b, keep, bench);
	while (b->size)
		best_insert(a, b, bench);
	rotate_a(a, cost_to_top_lis(find_min_index(a), a->size), bench);
}
