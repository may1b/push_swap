/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrass <magrass@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 01:53:55 by magrass           #+#    #+#             */
/*   Updated: 2026/04/28 09:19:17 by magrass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print_memory.h"
#include "ft_printf.h"
#include <unistd.h>

#define NULL_STR "(null)"
#define NULL_PTR_STR "(nil)"

int	ft_print_string(char *str)
{
	if (!str)
		return (write(1, NULL_STR, ft_strlen(NULL_STR)));
	return (write(1, str, ft_strlen(str)));
}

int	ft_print_ptr(size_t ptr)
{
	if (!ptr)
		return (write(1, NULL_PTR_STR, ft_strlen(NULL_PTR_STR)));
	return (ft_print_string(ptr_to_string(ptr)));
}
