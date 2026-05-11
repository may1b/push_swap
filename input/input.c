/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascheufe <ascheufe@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 09:57:40 by ascheufe          #+#    #+#             */
/*   Updated: 2026/05/11 16:59:32 by ascheufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack input_handler(int argc, char **argv, int *alg_selected)
{
	t_stack	stack;
	t_int_arr	num;
	size_t	i;
	size_t	x;
	size_t	r;
	static bool was_selected = false;

	i = 1;
	x = 0;
	r = 0;
	stack.top = -1;

	if (argc < 2)
		error_fun(EINVAL);
	while (i < argc)
	{
		num = check_string_and_create(argv[i], alg_selected); 
		if(num.ln == 0)			// * Alg got selected
		{
			if ((i == argc - 1) && !was_selected)
				return (stack);
			else if (i == 1)
				was_selected = true;
			else
				error_fun(EINVAL);
		}
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