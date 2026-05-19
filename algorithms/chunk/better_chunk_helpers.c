/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::	  */
/*	 better_chunk_helpers.c								:+:		 :+:	:+:	  */
/*													  +:+ +:+		  +:+	  */
/*	 By: ascheufe <ascheufe@student.42heilbronn.	+#+	 +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2026/05/19 13:30:00 by ascheufe		   #+#	  #+#			  */
/*	 Updated: 2026/05/19 13:30:00 by ascheufe		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "../../push_swap.h"

size_t	find_best_chunk_index(t_stack *stack, size_t min, size_t max)
{
	size_t	offset;
	size_t	top_idx;
	size_t	bot_idx;

	offset = 0;
	while ((size_t)offset < stack->size)
	{
		top_idx = offset;
		bot_idx = stack->size - 1 - offset;
		if (stack->arr[top_idx] >= (int)min
			&& stack->arr[top_idx] <= (int)max)
			return (top_idx);
		if (stack->arr[bot_idx] >= (int)min
			&& stack->arr[bot_idx] <= (int)max)
			return (bot_idx);
		offset++;
	}
	return (SIZE_MAX);
}

void	rotate_stack_a_to_top(t_stack *stack_a, size_t index,
	t_bench *bench)
{
	size_t	ra_cost;
	size_t	rra_cost;

	if (index == 0)
		return ;
	ra_cost = index;
	rra_cost = stack_a->size - index;
	if (ra_cost <= rra_cost)
		while (ra_cost--)
			ra(stack_a, bench);
	else
		while (rra_cost--)
			rra(stack_a, bench);
}

void	push_chunk_range(t_stack *stack_a, t_stack *stack_b,
	t_chunk_range range, t_bench *bench)
{
	size_t	target_count;
	size_t	index;
	size_t	chunk_mid;

	if (range.end < range.start)
		return ;
	target_count = range.end - range.start + 1;
	while (target_count-- && stack_a->size)
	{
		index = find_best_chunk_index(stack_a, range.start, range.end);
		if (index == SIZE_MAX)
			break ;
		rotate_stack_a_to_top(stack_a, index, bench);
		pb(stack_a, stack_b, bench);
		if (stack_b->size > 1)
		{
			chunk_mid = range.start + (range.end - range.start) / 2;
			if (stack_b->arr[0] <= (int)chunk_mid)
				rb(stack_b, bench);
		}
	}
}

void	push_all_chunks(t_stack *stack_a, t_stack *stack_b,
	size_t num_chunks, t_bench *bench)
{
	size_t			n;
	size_t			chunk_size;
	size_t			chunk_start;
	t_chunk_range		range;

	n = stack_a->size;
	chunk_size = (n + num_chunks - 1) / num_chunks;
	chunk_start = 0;
	while (chunk_start < n)
	{
		range.start = chunk_start;
		range.end = chunk_start + chunk_size - 1;
		if (range.end >= n)
			range.end = n - 1;
		push_chunk_range(stack_a, stack_b, range, bench);
		chunk_start = range.end + 1;
	}
}

void	pull_back_stack_b(t_stack *stack_a, t_stack *stack_b,
	t_bench *bench)
{
	size_t	max_index;
	size_t	i;
	size_t	ra_cost;
	size_t	rra_cost;

	max_index = 0;
	i = 1;
	while (i < stack_b->size)
	{
		if (stack_b->arr[i] > stack_b->arr[max_index])
			max_index = i;
		i++;
	}
	if (max_index != 0)
	{
		ra_cost = max_index;
		rra_cost = stack_b->size - max_index;
		if (ra_cost <= rra_cost)
			while (ra_cost--)
				rb(stack_b, bench);
		else
			while (rra_cost--)
				rrb(stack_b, bench);
	}
	pa(stack_a, stack_b, bench);
}
