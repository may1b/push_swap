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

/*
** Pushes all values from a to b in chunks of about 1.3 * sqrt(n).
** The 13 / 10 factor keeps this integer-only while widening each chunk
** slightly, which reduces repeated rotations through a. The +1 keeps the
** range non-zero for tiny inputs. For 500+ values, the range is capped at 29
** because wider chunks made large random inputs perform worse in practice.
*/
static void	k_push_to_b(t_stack *a, t_stack *b, t_bench *bench)
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
}

static bool	k_pull_top_pair(t_stack *a, t_stack *b, t_bench *bench)
{
	if (b->size > 1 && b->arr[0] == (int)b->size - 2
		&& b->arr[1] == (int)b->size - 1)
	{
		sb(b, bench);
		pa(a, b, bench);
		pa(a, b, bench);
		return (true);
	}
	return (false);
}

void	k_sort(t_stack *a, t_stack *b, t_bench *bench)
{
	k_push_to_b(a, b, bench);
	while (b->size)
	{
		if (!k_pull_top_pair(a, b, bench))
		{
			if (!k_pull_pair_if_cheaper(a, b, bench))
				k_pull_max(a, b, bench);
		}
	}
}
