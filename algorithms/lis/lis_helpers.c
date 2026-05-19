/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrass <magrass@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 00:00:00 by magrass           #+#    #+#             */
/*   Updated: 2026/05/19 00:00:00 by magrass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

size_t	lis_target_successor(t_stack *a, int val)
{
	size_t	i;
	size_t	best_i;
	int		best;

	best_i = stack_min_index(a);
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

int	lis_move_cost(int a_cost, int b_cost)
{
	if ((a_cost >= 0 && b_cost >= 0) || (a_cost <= 0 && b_cost <= 0))
	{
		if (ps_abs(a_cost) > ps_abs(b_cost))
			return (ps_abs(a_cost));
		return (ps_abs(b_cost));
	}
	return (ps_abs(a_cost) + ps_abs(b_cost));
}

static void	init_lis_row(t_stack *a, bool keep[MAX_SIZE], int len[MAX_SIZE],
	int prev[MAX_SIZE])
{
	size_t	i;

	i = 0;
	while (i < a->size)
	{
		keep[i] = false;
		len[i] = 1;
		prev[i] = -1;
		i++;
	}
}

static void	fill_lis(t_stack *a, int len[MAX_SIZE], int prev[MAX_SIZE],
	size_t *best_i)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < a->size)
	{
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
		if (len[i] > len[*best_i])
			*best_i = i;
		i++;
	}
}

void	lis_mark(t_stack *a, bool keep[MAX_SIZE])
{
	int		len[MAX_SIZE];
	int		prev[MAX_SIZE];
	size_t	best_i;

	best_i = 0;
	init_lis_row(a, keep, len, prev);
	fill_lis(a, len, prev, &best_i);
	while ((int)best_i >= 0)
	{
		keep[best_i] = true;
		if (prev[best_i] < 0)
			break ;
		best_i = (size_t)prev[best_i];
	}
}
