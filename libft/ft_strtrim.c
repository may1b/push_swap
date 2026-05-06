/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascheufe <ascheufe@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 12:05:04 by ascheufe          #+#    #+#             */
/*   Updated: 2026/04/23 13:18:04 by ascheufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>

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

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	char	*original;
	size_t	offset_start;
	size_t	offset_end;

	offset_end = 0;
	offset_start = 0;
	if (!s1)
		return (NULL);
	while (s1[offset_end])
		offset_end++;
	while (s1[offset_start] && is_char(s1[offset_start], set))
		offset_start++;
	while (offset_start != offset_end && is_char(s1[offset_end - 1], set))
		offset_end--;
	trimmed = malloc(offset_end - offset_start + 1);
	if (!trimmed)
		return (NULL);
	original = trimmed;
	while (offset_start < offset_end)
		*trimmed++ = s1[offset_start++];
	*trimmed = '\0';
	return (original);
}
