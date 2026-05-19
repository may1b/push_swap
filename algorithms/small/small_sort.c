/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrass <magrass@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 00:00:00 by magrass           #+#    #+#             */
/*   Updated: 2026/05/19 00:00:00 by magrass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static size_t	min_index(t_stack *a)
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

static void	rotate_min_top(t_stack *a, t_bench *bench)
{
	size_t	i;

	i = min_index(a);
	if (i <= a->size / 2)
		while (i--)
			ra(a, bench);
	else
		while (i++ < a->size)
			rra(a, bench);
}

static void	sort_three(t_stack *a, t_bench *bench)
{
	int	first;
	int	second;
	int	third;

	if (a->size < 2)
		return ;
	if (a->size == 2)
	{
		if (a->arr[0] > a->arr[1])
			sa(a, bench);
		return ;
	}
	first = a->arr[0];
	second = a->arr[1];
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
