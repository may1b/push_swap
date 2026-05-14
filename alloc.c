/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrass <magrass@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 16:30:49 by magrass           #+#    #+#             */
/*   Updated: 2026/05/14 16:30:49 by magrass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_arena_block	*new_block(size_t capacity)
{
	t_arena_block	*block;

	block = malloc(sizeof(t_arena_block) + capacity);
	if (!block)
		return (NULL);
	block->next = NULL;
	block->capacity = capacity;
	block->used = 0;
	return (block);
}

t_arena	*arena_new(size_t capacity)
{
	t_arena	*a;

	a = malloc(sizeof(t_arena));
	if (!a)
		return (NULL);
	a->head = new_block(capacity);
	if (!a->head)
		return (free(a), NULL);
	a->default_capacity = capacity;
	return (a);
}

void	*arena_alloc(t_arena *a, size_t size)
{
	t_arena_block	*block;
	size_t			cap;

	size = (size + 7) & ~(size_t)7;
	if (a->head->used + size > a->head->capacity)
	{
		cap = a->default_capacity;
		if (size > cap)
			cap = size;
		block = new_block(cap);
		if (!block)
			return (NULL);
		block->next = a->head;
		a->head = block;
	}
	block = a->head;
	block->used += size;
	return ((char *)(block + 1) + block->used - size);
}

void	arena_destroy(t_arena *a)
{
	t_arena_block	*block;
	t_arena_block	*next;

	block = a->head;
	while (block)
	{
		next = block->next;
		free(block);
		block = next;
	}
	free(a);
}
