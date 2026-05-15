/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrass <magrass@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 22:21:47 by magrass           #+#    #+#             */
/*   Updated: 2026/05/15 22:29:05 by magrass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "turk.h"

int	find_smallest(t_stack *s)
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

int	find_largest(t_stack *s)
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

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
