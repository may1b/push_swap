/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascheufe <ascheufe@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 17:05:29 by magrass           #+#    #+#             */
/*   Updated: 2026/05/19 13:46:56 by ascheufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	parse_input(int argc, char **argv, t_args *args)
{
	t_stack	stack;
	size_t	count;

	stack = (t_stack){0};
	if (argc < 2)
		error_fun(EINVAL);
	count = count_numbers(argv, argc);
	if (!count)
		error_fun(EINVAL);
	stack.arr = malloc(sizeof(int) * count);
	if (!stack.arr)
		error_fun(ENOMEM);
	parse_tokens(argv, argc, &stack, args);
	return (stack);
}
