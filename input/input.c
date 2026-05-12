/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascheufe <ascheufe@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 09:57:40 by ascheufe          #+#    #+#             */
/*   Updated: 2026/05/12 10:05:49 by ascheufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool	has_dup(t_stack numb)
{
	size_t	i;
	size_t	x;

	i = 0;
	x = 0;
	while (i < (numb.top + 1))
	{
		x = i + 1;
		while (x < (numb.top + 1))
		{
			if (numb.arr[i] == numb.arr[x])
				return (true);
			x++;
		}
		i++;
	}
	return (false);
}

t_stack	input_handler(int argc, char **argv, int *alg_selected)
{
	t_stack		stack;
	t_int_arr	num;
	size_t		i;
	size_t		x;
	size_t		r;

	i = 1;
	x = 0;
	r = 0;
	stack.top = -1;
	if (argc < 2)
		error_fun(EINVAL);
	while (i < argc)
	{
		num = check_string_and_create(argv[i], alg_selected);
		while (x < num.ln)
		{
			stack.arr[r++] = num.numbers[x++];
			stack.top++;
		}
		free(num.numbers);
		x = 0;
		i++;
	}
	return (stack);
}
