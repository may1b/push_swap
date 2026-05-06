/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascheufe <ascheufe@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 14:57:55 by ascheufe          #+#    #+#             */
/*   Updated: 2026/04/17 19:27:06 by ascheufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			total_size;
	size_t			i;
	unsigned char	*char_p;

	if ((nmemb != 0) && size > __SIZE_MAX__ / nmemb)
	{
		return (NULL);
	}
	total_size = nmemb * size;
	char_p = malloc(total_size);
	if (!char_p)
		return (NULL);
	i = 0;
	while (i < total_size)
	{
		char_p[i] = '\0';
		i++;
	}
	return (char_p);
}
