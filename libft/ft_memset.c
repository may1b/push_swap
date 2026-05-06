/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascheufe <ascheufe@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 12:37:07 by ascheufe          #+#    #+#             */
/*   Updated: 2026/04/16 15:57:16 by ascheufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *b, int c, size_t n)
{
	char			*str;
	unsigned char	chr;
	size_t			i;

	str = (char *)b;
	chr = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		str[i] = chr;
		i++;
	}
	return (str);
}
