/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrass <magrass@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 20:48:02 by magrass           #+#    #+#             */
/*   Updated: 2026/04/27 02:28:33 by magrass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print_memory.h"

void	print_string(size_t str_len, char str[static str_len])
{
	static char	buffer[ROW_SIZE];
	size_t		i;

	i = 0;
	if (str_len > ROW_SIZE)
		str_len = ROW_SIZE;
	while (i < str_len)
	{
		if (str[i] >= 32 && str[i] <= 126)
			buffer[i] = str[i];
		else
			buffer[i] = '.';
		i++;
	}
	while (i < ROW_SIZE)
		buffer[i++] = ' ';
	write(OUT_FD, buffer, ROW_SIZE);
}

/*
* HORRIBLE CODE DO NOT LOOK
*/
void	as_hex(uint8_t number[], char buf[static 2], uint8_t get4)
{
	buf[0] = HEX[(number[0] & 0xF0) / 0x10];
	buf[1] = HEX[number[0] & 0x0F];
	if (get4 == 1)
	{
		buf[2] = HEX[(number[1] & 0xF0) / 0x10];
		buf[3] = HEX[number[1] & 0x0F];
		buf[4] = ' ';
	}
	if (get4 == 3)
	{
		buf[2] = '0';
		buf[3] = '0';
		buf[4] = ' ';
	}
}

char	*get_mem_row(size_t how_much, const char mem[static how_much])
{
	static char	buffer[ROW_SIZE / 2][5];
	size_t		i;
	int32_t		j;
	uint8_t		yes;

	if (how_much > ROW_SIZE)
		how_much = ROW_SIZE;
	i = 0;
	j = 0;
	while (i < how_much)
	{
		if (how_much == 1)
			yes = 3;
		else
			yes = true;
		as_hex((uint8_t *)&mem[i], buffer[j++], yes);
		i += 2;
	}
	while (j++ < ROW_SIZE / 2)
	{
		i = 0;
		while (i < 5)
			buffer[j - 1][i++] = ' ';
	}
	return ((char *)buffer);
}

char	*ptr_to_string(const size_t ptr)
{
	t_splitptr	splitptr;
	static char	str[8][2];
	size_t		i;
	size_t		j;

	splitptr = *(t_splitptr *)&ptr;
	i = 0;
	j = (STR_PTR_SIZE / 2) - 1;
	while (i < STR_PTR_SIZE / 2)
	{
		as_hex(&splitptr.mem[i], str[j], false);
		i++;
		j--;
	}
	i = 0;
	while (((char *)str)[i] == '0')
		i++;
	if (ptr == 0)
		i--;
	((char *)str)[--i] = 'x';
	((char *)str)[--i] = '0';
	return ((char *)str + i);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	size_t	increment_by;

	while (size > 0)
	{
		if (size < ROW_SIZE)
			increment_by = size;
		else
			increment_by = ROW_SIZE;
		write(OUT_FD, ptr_to_string((size_t)addr), ROW_SIZE);
		write(OUT_FD, ": ", 2);
		write(1, get_mem_row(increment_by, addr), 40);
		print_string(increment_by, addr);
		write(1, "\n", 1);
		addr += increment_by;
		size -= increment_by;
	}
	return (addr);
}
