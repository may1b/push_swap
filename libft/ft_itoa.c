/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascheufe <ascheufe@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 15:13:29 by ascheufe          #+#    #+#             */
/*   Updated: 2026/04/22 16:54:15 by ascheufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	get_len(long n)
{
	size_t	i;

	i = 1;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	size_t	i;
	size_t	ln;
	char	*res;
	long	long_n;

	long_n = n;
	i = 0;
	ln = get_len(long_n);
	res = malloc(sizeof(char) * (ln + 1));
	if (!res)
		return (NULL);
	if (long_n < 0)
	{
		long_n = -long_n;
		res[0] = '-';
	}
	while (long_n > 0 || (n == 0 && i == 0))
	{
		res[(ln - 1) - i] = ('0' + (long_n % 10));
		long_n /= 10;
		i++;
	}
	res[ln] = '\0';
	return (res);
}
