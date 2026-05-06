/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascheufe <ascheufe@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 12:59:23 by ascheufe          #+#    #+#             */
/*   Updated: 2026/04/17 19:40:30 by ascheufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_bzero(void *b, size_t len)
{
	size_t		i;
	char		*str;

	i = 0;
	str = (char *)b;
	while (i < len)
	{
		str[i] = '\0';
		i++;
	}
}
