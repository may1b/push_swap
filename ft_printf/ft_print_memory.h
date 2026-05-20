/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrass <magrass@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 21:29:36 by magrass           #+#    #+#             */
/*   Updated: 2026/04/26 23:48:34 by magrass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_MEMORY_H
# define FT_PRINT_MEMORY_H
# include <stddef.h>
# include <stdint.h>
# include <unistd.h>
# include <stdbool.h>
# define HEX "0123456789abcdef"
# define COLON :
# define BSIZE 6
# define OUT_FD 1
# define ROW_SIZE 16
# define STR_PTR_SIZE 16 // (sizeof(void *) / 4)

typedef struct s_splitptr {
	uint8_t	mem[8];
}	t_splitptr;

void	*ft_print_memory(void *addr, unsigned int size);
void	as_hex(uint8_t number[], char buf[static 2], uint8_t get4);
char	*ptr_to_string(size_t ptr);
char	*get_mem_row(size_t how_much, const char mem[static how_much]);
void	print_string(size_t str_len, char str[static str_len]);
char	*ft_strupcase(char *str);

#endif
