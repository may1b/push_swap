/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascheufe <ascheufe@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 17:58:52 by ascheufe          #+#    #+#             */
/*   Updated: 2026/04/27 17:33:30 by ascheufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	int_len(int sel)
{
	int	i;

	i = 0;
	while (sel != 0)
	{
		if (sel > 0)
			i++;
		else
			i--;
		sel = sel / 10;
	}
	if (i < 0)
		return (i * -1);
	return (i);
}

static int	power(int base, int index)
{
	int	res;

	if (index == 0)
		return (0);
	res = 1;
	index--;
	while (index-- > 0)
	{
		res = res * base;
	}
	return (res);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		ln;
	char	int_conv;

	if (n == 0)
		write(fd, "0", 1);
	ln = int_len(n);
	if (n < 0)
	{
		write(fd, "-", 1);
	}
	while (ln)
	{
		if (n < 0)
			int_conv = '0' - (n / power(10, ln) % 10);
		else
			int_conv = '0' + (n / power(10, ln) % 10);
		write(fd, &int_conv, 1);
		ln--;
	}
}
