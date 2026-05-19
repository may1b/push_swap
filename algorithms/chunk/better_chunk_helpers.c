/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   better_chunk_helpers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrass <magrass@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 00:00:00 by magrass           #+#    #+#             */
/*   Updated: 2026/05/19 00:00:00 by magrass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

size_t	chunk_sqrt(size_t n)
{
	size_t	i;

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
	while (fwd < (int)sz && !(s->arr[fwd] >= (int)lo
			&& s->arr[fwd] <= (int)hi))
		fwd++;
	rev = 0;
	while (rev < (int)sz && !(s->arr[sz - 1 - rev] >= (int)lo
			&& s->arr[sz - 1 - rev] <= (int)hi))
		rev++;
	if (fwd <= rev)
		return (1);
	return (-1);
}

void	set_chunk(t_chunk_state *chunk, size_t i, size_t num_chunks)
{
	chunk->start = i * chunk->size;
	if (i == num_chunks - 1)
		chunk->end = chunk->n - 1;
	else
		chunk->end = (i + 1) * chunk->size - 1;
	chunk->mid = (chunk->start + chunk->end) / 2;
}

void	push_one_chunk(t_stack *a, t_stack *b, t_chunk_state chunk,
	t_bench *bench)
{
	size_t	pushed;
	int		dir;

	pushed = 0;
	while (pushed < chunk.end - chunk.start + 1)
	{
		if (a->arr[0] >= (int)chunk.start && a->arr[0] <= (int)chunk.end)
		{
			pb(a, b, bench);
			if (b->arr[0] <= (int)chunk.mid)
				rb(b, bench);
			pushed++;
		}
		else
		{
			dir = find_match_dir(a, chunk.start, chunk.end);
			if (dir > 0)
				ra(a, bench);
			else
				rra(a, bench);
		}
	}
}
