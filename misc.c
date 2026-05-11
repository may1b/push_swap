/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascheufe <ascheufe@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 11:14:14 by ascheufe          #+#    #+#             */
/*   Updated: 2026/05/11 13:47:45 by ascheufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_fun(int error)
{
	ft_putstr_fd("ERROR\n", ERROR_OUT);
	exit(error);
}


size_t	str_arr_len(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void	free_array(void **p, size_t ln)
{
	size_t	i;

	i = 0;
	while (i < ln)
	{
		free(p[i]);
		i++;
	}
	free(p);
}