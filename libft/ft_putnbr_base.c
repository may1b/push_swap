/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascheufe <ascheufe@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:56:08 by ascheufe          #+#    #+#             */
/*   Updated: 2026/04/27 17:33:14 by ascheufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stddef.h>
#include <stdbool.h>

size_t				int_len(int sel);
int					check_for_dup(char *str);
int					is_char(char comp, char *c);

size_t	int_len(int sel)
{
	size_t	i;

	i = 0;
	while (sel != 0)
	{
		i++;
		sel = sel / 10;
	}
	return (i);
}

int	recursive_alg(unsigned long nbr, char *base, int ln_base, int bytes_printed)
{
	if (nbr == 0)
		return (bytes_printed);
	bytes_printed = recursive_alg(nbr / ln_base, base, ln_base, bytes_printed);
	if (bytes_printed == -1)
		return (-1);
	if (write(1, &base[nbr % ln_base], 1) == -1)
		return (-1);
	bytes_printed++;
	return (bytes_printed);
}

int	ft_putnbr_base(long nbr, char *base, bool is_unsigned)
{
	unsigned long		copy_nb;		
	size_t				ln_base;
	int					bytes_printed;

	bytes_printed = 0;
	ln_base = 0;
	while (base[ln_base])
		ln_base++;
	if (check_for_dup(base) || ln_base < 2)
		return (-1);
	if (nbr == 0)
		return (write(1, &base[0], 1));
	if (!is_unsigned && nbr < 0)
	{
		write(1, "-", 1);
		bytes_printed++;
		copy_nb = (unsigned long)(-(nbr + 1)) + 1;
	}
	else
		copy_nb = (unsigned long)nbr;
	return (recursive_alg(copy_nb, base, ln_base, bytes_printed));
}

int	check_for_dup(char *str)
{
	int	i;
	int	x;

	i = 0;
	while (str[i])
	{
		x = i + 1;
		if (is_char(str[i], "+- "))
			return (1);
		while (str[x])
		{
			if (str[i] == str[x])
				return (1);
			x++;
		}
		i++;
	}
	return (0);
}

int	is_char(char comp, char *c)
{
	int	i;
	int	ln;

	ln = 0;
	i = 0;
	while (c[ln])
		ln++;
	while (i < ln)
	{
		if (comp == c[i])
			return (1);
		i++;
	}
	return (0);
}
