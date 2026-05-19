/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   better_chunk.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrass <magrass@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 00:00:00 by magrass           #+#    #+#             */
/*   Updated: 2026/05/19 00:00:00 by magrass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	push_all_chunks(t_stack *stack_a, t_stack *stack_b,
	size_t num_chunks, t_bench *bench)
{
	t_chunk_state	chunk;
	size_t			i;

	chunk.n = stack_a->size;
	chunk.size = chunk.n / num_chunks;
	i = 0;
	while (i < num_chunks)
	{
		set_chunk(&chunk, i, num_chunks);
		push_one_chunk(stack_a, stack_b, chunk, bench);
		i++;
	}
}

void	pull_back_stack_b(t_stack *stack_a, t_stack *stack_b,
	t_bench *bench)
{
	int	cost;

	cost = ps_cost_to_top(stack_max_index(stack_b), stack_b->size);
	rotate_b_cost(stack_b, cost, bench);
	pa(stack_a, stack_b, bench);
}

void	better_chunk_sort(t_stack *stack_a, t_stack *stack_b,
	t_bench *bench, float disorder)
{
	size_t	n;
	size_t	num_chunks;

	n = stack_a->size;
	if (n <= 1)
		return ;
	(void)disorder;
	num_chunks = chunk_sqrt(n);
	push_all_chunks(stack_a, stack_b, num_chunks, bench);
	while (stack_b->size)
		pull_back_stack_b(stack_a, stack_b, bench);
}
