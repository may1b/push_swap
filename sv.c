/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sv.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrass <magrass@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 20:43:49 by magrass           #+#    #+#             */
/*   Updated: 2026/05/12 22:37:50 by magrass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	count_segments(t_sv sv, char delim)
{
	size_t	count;
	size_t	i;
	bool	in_seg;

	count = 0;
	in_seg = false;
	i = 0;
	while (i < sv.size)
	{
		if (sv.str[i] != delim && !in_seg)
		{
			count++;
			in_seg = true;
		}
		else if (sv.str[i] == delim)
			in_seg = false;
		i++;
	}
	return (count);
}

t_sv	sv_slice(t_sv sv, size_t start, size_t len)
{
	t_sv	result;

	result.str = sv.str + start;
	result.size = len;
	return (result);
}

t_sv_da	sv_split(t_sv sv, char delim, t_arena *arena)
{
	t_sv_da	result;
	size_t	i;
	size_t	start;

	result.items = arena_alloc(arena, count_segments(sv, delim) * sizeof(t_sv));
	result.size = 0;
	if (!result.items)
		return (result);
	i = 0;
	while (i <= sv.size)
	{
		if (i < sv.size && sv.str[i] != delim)
		{
			start = i;
			while (i < sv.size && sv.str[i] != delim)
				i++;
			result.items[result.size++] = sv_slice(sv, start, i - start);
		}
		else
			i++;
	}
	return (result);
}
