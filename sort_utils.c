/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrass <magrass@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 00:00:00 by magrass           #+#    #+#             */
/*   Updated: 2026/05/19 00:00:00 by magrass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	ps_cost_to_top(size_t i, size_t size)
{
	if (i <= size / 2)
		return ((int)i);
	return (-(int)(size - i));
}

size_t	stack_min_index(t_stack *a)
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

size_t	stack_max_index(t_stack *a)
{
	size_t	i;
	size_t	max_i;

	max_i = 0;
	i = 1;
	while (i < a->size)
	{
		if (a->arr[i] > a->arr[max_i])
			max_i = i;
		i++;
	}
	return (max_i);
}
