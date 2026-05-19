/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrass <magrass@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 00:00:00 by magrass           #+#    #+#             */
/*   Updated: 2026/05/19 00:00:00 by magrass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_sv	next_token(const char *str, size_t *pos)
{
	t_sv	token;

	while (str[*pos] == ' ')
		(*pos)++;
	token.str = str + *pos;
	while (str[*pos] && str[*pos] != ' ')
		(*pos)++;
	token.size = (str + *pos) - token.str;
	return (token);
}

size_t	count_numbers(char **argv, int argc)
{
	size_t	count;
	size_t	i;
	char	*tmp;

	count = 0;
	i = 1;
	while (i < (size_t)argc)
	{
		tmp = argv[i];
		while (*tmp)
		{
			while (*tmp == ' ')
				tmp++;
			if (*tmp)
				count++;
			while (*tmp && *tmp != ' ')
				tmp++;
		}
		i++;
	}
	return (count);
}

static void	copy_original(t_stack *stack, int *original)
{
	size_t	i;

	i = 0;
	while (i < stack->size)
	{
		original[i] = stack->arr[i];
		i++;
	}
}

void	ranking(t_stack *stack)
{
	int		rank;
	size_t	i;
	size_t	j;
	int		*original;

	original = malloc(sizeof(int) * stack->size);
	if (!original)
		error_fun(ENOMEM);
	copy_original(stack, original);
	i = 0;
	while (i < stack->size)
	{
		j = 0;
		rank = 0;
		while (j < stack->size)
		{
			if (original[j] < original[i])
				rank++;
			j++;
		}
		stack->arr[i++] = rank;
	}
	free(original);
}
