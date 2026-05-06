/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascheufe <ascheufe@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 14:45:04 by ascheufe          #+#    #+#             */
/*   Updated: 2026/04/23 12:41:46 by ascheufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>

static bool	is_char(char comp, const char *c)
{
	size_t	i;

	i = 0;
	while (c[i])
	{
		if (comp == c[i])
			return (true);
		i++;
	}
	return (false);
}

int	ft_atoi(const char *str)
{
	int				i;
	long int		conv_int;
	int				sign;

	conv_int = 0;
	sign = 1;
	i = 0;
	while (str[i] && is_char(str[i], " \n\t\r\v\f"))
		i++;
	if (is_char(str[i], "-+"))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		conv_int = conv_int * 10 + (str[i] - '0');
		i++;
	}
	return (conv_int * sign);
}
