/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascheufe <ascheufe@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 16:12:52 by ascheufe          #+#    #+#             */
/*   Updated: 2026/05/08 13:52:29 by ascheufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>

static void	free_array(void **p, size_t ln)
{
	size_t	i;

	i = 0;
	while (i < ln)
	{
		free(p[i]);
		i++;
	}
	free(p);
}

static	size_t	word_len(const char *s, const char c)
{
	size_t	ln;

	ln = 0;
	while (s[ln] != c && s[ln])
		ln++;
	return (ln);
}

static char	*fill_array(const char *s, const char c)
{
	size_t	i;
	size_t	ln;
	char	*split_str;

	ln = word_len(s, c);
	i = 0;
	split_str = malloc(sizeof(char) * (ln + 1));
	if (!split_str)
		return (NULL);
	while (i < ln)
	{
		split_str[i] = s[i];
		i++;
	}
	split_str[i] = '\0';
	return (split_str);
}

static size_t	count_set(char const *s, char c)
{
	size_t	i;
	size_t	count;
	bool	was_c;

	i = 0;
	count = 0;
	was_c = true;
	while (s[i])
	{
		if (s[i] == c)
			was_c = true;
		else if (s[i] != c && was_c)
		{
			count++;
			was_c = false;
		}
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**split_str;
	size_t	x;

	x = 0;
	if (!s)
		return (NULL);
	split_str = malloc(sizeof(char *) * (count_set(s, c) + 1));
	if (!split_str)
		return (NULL);
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			split_str[x] = fill_array(s, c);
			if (!split_str[x])
				return (free_array((void **)split_str, x), NULL);
			x++;
			s += word_len(s, c);
		}
	}
	split_str[x] = NULL;
	return (split_str);
}
