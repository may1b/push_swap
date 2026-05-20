/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrass <magrass@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 21:12:55 by magrass           #+#    #+#             */
/*   Updated: 2026/04/28 10:15:37 by magrass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stddef.h>

typedef union u_arg {
	int		c;
	char	buf[1000];
	char	*str;
	size_t	ptr;
}	t_arg;

int		ft_printf(const char *fmt, ...) __attribute__((format(printf, 1, 2)));

size_t	ft_strlen(const char *s);

int		ft_print_string(char *str);

int		ft_print_ptr(size_t ptr);

#endif
