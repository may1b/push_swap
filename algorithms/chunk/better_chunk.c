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

static size_t   ft_sqrt(size_t n)
{
    size_t  i;

    i = 1;
    while (i * i <= n)
        i++;
    return (i - 1);
}

static int	find_match_dir(t_stack *s, size_t lo, size_t hi)
{
	size_t	sz;
	int		fwd;
	int		rev;

	sz = s->size;
	fwd = 0;
	while (fwd < (int)sz && !(s->arr[fwd] >= (int)lo && s->arr[fwd] <= (int)hi))
		fwd++;
	rev = 0;
	while (rev < (int)sz
		&& !(s->arr[sz - 1 - rev] >= (int)lo && s->arr[sz - 1 - rev] <= (int)hi))
		rev++;
	if (fwd <= rev)
		return (1);
	return (-1);
}

void    push_all_chunks(t_stack *stack_a, t_stack *stack_b,
		size_t num_chunks, t_bench *bench)
{
	size_t  n;
	size_t  chunk_size;
	size_t  i;
	size_t  chunk_start;
	size_t  chunk_end;
	size_t  chunk_mid;
	size_t  pushed;
	int		dir;

	n = stack_a->size;
	chunk_size = n / num_chunks;
	i = 0;
	while (i < num_chunks)
	{
		chunk_start = i * chunk_size;
		chunk_end = (i == num_chunks - 1) ? n - 1 : (i + 1) * chunk_size - 1;
		chunk_mid = (chunk_start + chunk_end) / 2;
		pushed = 0;
		while (pushed < chunk_end - chunk_start + 1)
		{
			if (stack_a->arr[0] >= (int)chunk_start
				&& stack_a->arr[0] <= (int)chunk_end)
			{
				pb(stack_a, stack_b, bench);
				if (stack_b->arr[0] <= (int)chunk_mid)
					rb(stack_b, bench);
				pushed++;
			}
			else
			{
				dir = find_match_dir(stack_a, chunk_start, chunk_end);
				if (dir > 0)
					ra(stack_a, bench);
				else
					rra(stack_a, bench);
			}
		}
		i++;
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


void    better_chunk_sort(t_stack *stack_a, t_stack *stack_b,
		t_bench *bench, float disorder)
{
	size_t  n;
	size_t  num_chunks;

	n = stack_a->size;
	if (n <= 1)
		return ;
	(void)disorder;
	num_chunks = ft_sqrt(n);
	push_all_chunks(stack_a, stack_b, num_chunks, bench);
	while (stack_b->size)
		pull_back_stack_b(stack_a, stack_b, bench);
}
