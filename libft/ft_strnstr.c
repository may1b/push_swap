/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascheufe <ascheufe@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 15:41:38 by ascheufe          #+#    #+#             */
/*   Updated: 2026/04/17 12:07:52 by ascheufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *big, const char *little, size_t size)
{
	size_t	i;
	size_t	y;
	size_t	size_little;

	i = 0;
	y = 0;
	size_little = 0;
	if (!little[0])
		return ((char *)big);
	while (little[size_little])
		size_little++;
	while (size - y >= size_little && big[y])
	{
		i = 0;
		while (i < size_little && y + i < size)
		{
			if (big[y + i] != little[i])
				break ;
			i++;
			if (size_little == i)
				return ((char *)(big + y));
		}
		y++;
	}
	return (NULL);
}
