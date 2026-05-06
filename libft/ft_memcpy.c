/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascheufe <ascheufe@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 13:03:48 by ascheufe          #+#    #+#             */
/*   Updated: 2026/04/23 14:06:33 by ascheufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	char	*str_d;
	char	*str_s;
	size_t	i;

	if (!dst && !src)
		return (NULL);
	str_d = (char *)dst;
	str_s = (char *)src;
	i = 0;
	while (i < len)
	{
		str_d[i] = str_s[i];
		i++;
	}
	return (str_d);
}
