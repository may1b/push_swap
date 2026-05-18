/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascheufe <ascheufe@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 11:14:14 by ascheufe          #+#    #+#             */
/*   Updated: 2026/05/18 09:47:41 by ascheufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_fun(int error)
{
	ft_putstr_fd("ERROR\n", ERROR_OUT);
	exit(error);
}

bool	has_dup(t_stack *numb)
{
	size_t	i;
	size_t	x;

	i = 0;
	while (i < numb->size)
	{
		x = i + 1;
		while (x < numb->size)
		{
			if (numb->arr[i] == numb->arr[x])
				return (true);
			x++;
		}
		i++;
	}
	return (false);
}
float	disorder(t_stack *stack)
{
	size_t	i;
	size_t	x;
	int		mistakes;
	int		total_pairs;

	if (stack->size < 2)
		return (0.0f);
	mistakes = 0;
	total_pairs = 0;
	i = 0;
	while (i < stack->size - 1)
	{
		x = i + 1;
		while (x < stack->size)
		{
			if (stack->arr[i] > stack->arr[x])
				mistakes++;
			total_pairs++;
			x++;
		}
		i++;
	}
	return ((float)mistakes / total_pairs);
}

