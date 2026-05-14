/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sv.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrass <magrass@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 20:43:49 by magrass           #+#    #+#             */
/*   Updated: 2026/05/12 22:37:50 by magrass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_sv	sv_from_cstr(const char *str)
{
	return ((t_sv){str, ft_strlen(str)});
}

bool	sv_eq(t_sv a, const char *b)
{
	size_t	len;

	len = ft_strlen(b);
	if (a.size != len)
		return (false);
	return (ft_strncmp(a.str, b, len) == 0);
}
