/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_target.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascheufe <ascheufe@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 22:28:48 by magrass           #+#    #+#             */
/*   Updated: 2026/05/19 13:23:59 by ascheufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "turk.h"

size_t	target_in_b(t_stack *b, int val)
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
		if (find_largest(b) == b->arr[0])
			return (0);
		return (b->size - 1);
	}
	return (best_idx);
}

size_t	target_in_a(t_stack *a, int val)
{
	int		best;
	size_t	best_i;
	size_t	i;

	best = INT_MIN;
	best_i = 0;
	i = 0;
	while (i < a->size)
	{
		if (a->arr[i] < val && a->arr[i] > best)
		{
			best = a->arr[i];
			best_i = i;
		}
		i++;
	}
	if (best == INT_MAX)
	{
		if (find_smallest(a) == a->arr[0])
			return (0);
		return (a->size - 1);
	}
	return (best_i);
}
