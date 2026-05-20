/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrass <magrass@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 00:00:00 by magrass           #+#    #+#             */
/*   Updated: 2026/05/20 16:43:00 by magrass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	rotate_min_top(t_stack *a, t_bench *bench)
{
	size_t	i;

	i = stack_min_index(a);
	if (i <= a->size / 2)
		while (i--)
			ra(a, bench);
	else
		while (i++ < a->size)
			rra(a, bench);
}

static void	sort_three_values(t_stack *a, t_bench *bench, int first,
	int second)
{
	int	third;

	third = a->arr[2];
	if (first > second && second < third && first < third)
		sa(a, bench);
	else if (first > second && second > third)
	{
		sa(a, bench);
		rra(a, bench);
	}
	else if (first > second && second < third && first > third)
		ra(a, bench);
	else if (first < second && second > third && first < third)
	{
		sa(a, bench);
		ra(a, bench);
	}
	else if (first < second && second > third && first > third)
		rra(a, bench);
}

static void	sort_three(t_stack *a, t_bench *bench)
{
	if (a->size < 2)
		return ;
	if (a->size == 2)
	{
		if (a->arr[0] > a->arr[1])
			sa(a, bench);
		return ;
	}
	sort_three_values(a, bench, a->arr[0], a->arr[1]);
}

void	small_sort(t_stack *a, t_stack *b, t_bench *bench)
{
	while (a->size > 3)
	{
		rotate_min_top(a, bench);
		pb(a, b, bench);
	}
	sort_three(a, bench);
	while (b->size)
		pa(a, b, bench);
}
