/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascheufe <ascheufe@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 14:09:09 by ascheufe          #+#    #+#             */
/*   Updated: 2026/04/23 13:44:11 by ascheufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *b, int d, size_t len)
{
	unsigned char	c;
	unsigned char	*s;
	size_t			i;

	c = (unsigned char)d;
	i = 0;
	s = (unsigned char *)b;
	while (i < len)
	{
		if (s[i] == c)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}
