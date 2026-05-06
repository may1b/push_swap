/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascheufe <ascheufe@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 13:12:53 by ascheufe          #+#    #+#             */
/*   Updated: 2026/04/17 11:11:07 by ascheufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*str_d;
	const char	*str_s;
	size_t		i;

	str_d = dst;
	str_s = (const char *)src;
	i = 0;
	if (str_d < str_s)
	{
		while (i < len)
		{
			str_d[i] = str_s[i];
			i++;
		}
	}
	else if (str_d > str_s)
	{
		while (len > 0)
		{
			len--;
			str_d[len] = str_s[len];
		}
	}
	return (str_d);
}
