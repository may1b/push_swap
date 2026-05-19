/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrass <magrass@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 00:00:00 by magrass           #+#    #+#             */
/*   Updated: 2026/05/19 00:00:00 by magrass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static size_t	ft_sqrt_k(size_t n)
{
	size_t	i;

	i = 1;
	while (i * i <= n)
		i++;
	return (i - 1);
}

static size_t	max_index(t_stack *b)
{
	size_t	i;
	size_t	max_i;

	max_i = 0;
	i = 1;
	while (i < b->size)
	{
		if (b->arr[i] > b->arr[max_i])
			max_i = i;
		i++;
	}
	return (max_i);
}

static int	abs_k(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int	cost_to_top(size_t i, size_t size)
{
	if (i <= size / 2)
		return ((int)i);
	return (-(int)(size - i));
}

static size_t	value_index(t_stack *b, int val)
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

static void	rotate_b_to_top(t_stack *b, int cost, t_bench *bench)
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

static void	pull_max(t_stack *a, t_stack *b, t_bench *bench)
{
	size_t	i;

	i = max_index(b);
	if (i <= b->size / 2)
		while (i--)
			rb(b, bench);
	else
		while (i++ < b->size)
			rrb(b, bench);
	pa(a, b, bench);
}

static bool	pull_pair_if_cheaper(t_stack *a, t_stack *b, t_bench *bench)
{
	size_t	max_i;
	size_t	second_i;
	int		max_cost;
	int		second_cost;

	if (b->size < 2)
		return (false);
	max_i = value_index(b, (int)b->size - 1);
	second_i = value_index(b, (int)b->size - 2);
	max_cost = cost_to_top(max_i, b->size);
	second_cost = cost_to_top(second_i, b->size);
	if (abs_k(second_cost) + 2 >= abs_k(max_cost))
		return (false);
	rotate_b_to_top(b, second_cost, bench);
	pa(a, b, bench);
	pull_max(a, b, bench);
	sa(a, bench);
	return (true);
}

void	k_sort(t_stack *a, t_stack *b, t_bench *bench)
{
	size_t	range;
	size_t	limit;

	range = ft_sqrt_k(a->size) * 13 / 10 + 1;
	if (a->size >= 500)
		range = 29;
	while (a->size)
	{
		limit = b->size + range;
		if (a->arr[0] <= (int)b->size)
		{
			pb(a, b, bench);
			rb(b, bench);
		}
		else if (a->arr[0] <= (int)limit)
			pb(a, b, bench);
		else
			ra(a, bench);
	}
	while (b->size)
	{
		if (b->size > 1 && b->arr[0] == (int)b->size - 2
			&& b->arr[1] == (int)b->size - 1)
		{
			sb(b, bench);
			pa(a, b, bench);
			pa(a, b, bench);
		}
		else
		{
			if (!pull_pair_if_cheaper(a, b, bench))
				pull_max(a, b, bench);
		}
	}
}
