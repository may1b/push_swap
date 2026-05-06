/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascheufe <ascheufe@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 11:48:37 by ascheufe          #+#    #+#             */
/*   Updated: 2026/04/23 12:56:46 by ascheufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	x;
	char	*con_s;

	i = 0;
	x = 0;
	if (!s1 || !s2)
		return (NULL);
	con_s = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!con_s)
		return (NULL);
	while (s1[i])
	{
		con_s[i] = s1[i];
		i++;
	}
	while (s2[x])
	{
		con_s[i] = s2[x];
		x++;
		i++;
	}
	con_s[i] = '\0';
	return (con_s);
}
