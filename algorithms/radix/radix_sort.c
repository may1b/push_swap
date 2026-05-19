/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrass <magrass@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 00:00:00 by magrass           #+#    #+#             */
/*   Updated: 2026/05/19 00:00:00 by magrass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	radix_sort(t_stack *a, t_stack *b, t_bench *bench)
{
	size_t	bit;
	size_t	i;
	size_t	n;
	size_t	max;

	n = a->size;
	max = n - 1;
	bit = 0;
	while ((max >> bit) != 0)
	{
		i = 0;
		while (i < n)
		{
			if (((a->arr[0] >> bit) & 1) == 0)
				pb(a, b, bench);
			else
				ra(a, bench);
			i++;
		}
		while (b->size)
			pa(a, b, bench);
		bit++;
	}
}
