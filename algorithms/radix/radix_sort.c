/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrass <magrass@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 00:00:00 by magrass           #+#    #+#             */
/*   Updated: 2026/05/20 16:42:57 by magrass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static size_t	radix_bits(size_t n)
{
	size_t	bits;

	bits = 0;
	while ((n - 1) >> bits)
		bits++;
	return (bits);
}

static bool	has_bit(int value, size_t bit)
{
	return (((value >> bit) & 1) != 0);
}

void	radix_sort(t_stack *a, t_stack *b, t_bench *bench)
{
	size_t	bits;
	size_t	bit;
	size_t	i;
	size_t	n;

	n = a->size;
	if (n <= 1)
		return ;
	bits = radix_bits(n);
	bit = 0;
	while (bit < bits)
	{
		i = 0;
		while (i++ < n)
		{
			if (has_bit(a->arr[0], bit))
				ra(a, bench);
			else
				pb(a, b, bench);
		}
		while (b->size)
			pa(a, b, bench);
		bit++;
	}
}
