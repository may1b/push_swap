/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrass <magrass@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 21:12:37 by magrass           #+#    #+#             */
/*   Updated: 2026/04/28 10:15:46 by magrass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>
#include "ft_printf.h"
#include "ft_print_memory.h"

static char	*ft_itoa_buf(long n, char *buf)
{
	int		len;
	long	tmp;

	len = (n < 0);
	if (!len)
		n = -n;
	tmp = n;
	if (tmp == 0)
		tmp = -1;
	while (tmp != 0 && ++len)
		tmp /= 10;
	buf[len] = '\0';
	if (n == 0)
		return (buf[0] = '0', buf);
	if (len != (n < 0))
		buf[0] = '-';
	while (n != 0)
	{
		buf[--len] = '0' - (n % 10);
		n /= 10;
	}
	return (buf);
}

static int	print_fmt(char fmt_specifier, va_list *args)
{
	t_arg	arg;

	if (fmt_specifier == 'c')
		return (write(STDOUT_FILENO, (arg.c = va_arg(*args, int), &arg.c), 1));
	else if (fmt_specifier == 's')
		return (ft_print_string((char *)va_arg(*args, size_t)));
	else if (fmt_specifier == 'i' || fmt_specifier == 'd')
		return (ft_print_string(ft_itoa_buf(va_arg(*args, int), arg.buf)));
	else if (fmt_specifier == 'u')
		return (write(1, ft_itoa_buf(va_arg(*args, unsigned int), arg.buf),
				ft_strlen(arg.buf)));
	else if (fmt_specifier == 'p')
		return (ft_print_ptr(va_arg(*args, size_t)));
	else if (fmt_specifier == 'x')
		return (write(1, arg.str = ptr_to_string(va_arg(*args, unsigned int))
				+ 2, ft_strlen(arg.str)));
	else if (fmt_specifier == 'X')
		return (write(1, arg.str
				= ft_strupcase(ptr_to_string(va_arg(*args, unsigned int))) + 2,
				ft_strlen(arg.str)));
	else if (fmt_specifier == '%')
		return (ft_print_string("%"));
	return (-1);
}

static int	ft_print(const char *fmt, size_t *i, int *count, va_list *args)
{
	int	result;

	while (fmt[*i])
	{
		if (fmt[*i] == '%')
		{
			result = print_fmt((++(*i), fmt[(*i)++]), args);
			if (result == -1)
				return (-1);
			*count += result;
		}
		else
		{
			result = write(1, &fmt[(*i)++], 1);
			if (result == -1)
				return (-1);
			*count += result;
		}
	}
	return (*count);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	size_t	i;
	int		count;

	va_start(args, fmt);
	i = 0;
	count = 0;
	count = ft_print(fmt, &i, &count, &args);
	va_end(args);
	return (count);
}
