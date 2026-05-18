/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascheufe <ascheufe@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 11:26:34 by ascheufe          #+#    #+#             */
/*   Updated: 2026/05/18 13:50:14 by ascheufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static size_t  ft_sqrt(size_t n)
{
    size_t  i;

    i = 1;
    while (i * i <= n)
        i++;
    return (i - 1);
}

bool	is_in_range(int rank, int min, int max)
{
	return (rank >= min && rank <= max);
}

static size_t   find_largest_index(t_stack *s)
{
    size_t  i;
    size_t  max_index;

    max_index = 0;
    i = 1;
    while (i < s->size)
    {
        if (s->arr[i] > s->arr[max_index])
            max_index = i;
        i++;
    }
    return (max_index);
}

void chunk_sort(t_stack *stack_a, t_stack *stack_b, t_bench *bench)
{
	size_t	i;
	size_t	j;
	size_t  num_chunks;
	size_t  chunk_size;
	size_t	n;		// 9
	size_t	chunk_start;
	size_t	chunk_end;
	size_t	count;
	size_t	max_index;

	n = stack_a->size;
	num_chunks = ft_sqrt(n);
	chunk_size	= n / num_chunks;
	count = 0;
	i = 0;
	
	while (i < num_chunks)
	{
		count = 0;
		chunk_start = chunk_size * i;
		if (i == num_chunks - 1)
			chunk_end = n - 1;
		else
			chunk_end = chunk_size * (i + 1) - 1;
		while ((i == num_chunks - 1 && stack_a->size > 0) || count < chunk_size)
		{
			if (is_in_range(stack_a->arr[stack_a->size - 1], chunk_start, chunk_end))
			{
				count++;
				pb(stack_a, stack_b, bench);
  				if ((unsigned long)stack_b->arr[stack_b->size - 1] <= ((chunk_start + chunk_end) / 2))
       				rb(stack_b, bench);
			}
			else
				ra(stack_a, bench);
		}
		i++;
	}
	i = 0;
	
	j = 0;
	while (stack_b->size)
	{

		max_index = find_largest_index(stack_b);
		if (max_index <= stack_b->size / 2)
		{
			while (j < max_index)
			{
				rb(stack_b, bench);
				j++;
			}
		}
		else
		{
			while (j < stack_b->size - max_index)
			{
				rrb(stack_b, bench);
				j++;
			}
		}
		j = 0;
		pa(stack_a, stack_b, bench);
	}
	// for (size_t i = 0; i < stack_a->size; i++)
	// {
	// 	ft_printf("%d", stack_b->arr[i]);
	// }
}