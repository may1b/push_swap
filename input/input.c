/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrass <magrass@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 09:57:40 by ascheufe          #+#    #+#             */
/*   Updated: 2026/05/12 22:14:18 by magrass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool	has_dup(t_stack *numb)
{
	size_t	i;
	size_t	x;

	i = 0;
	while (i < numb->size)
	{
		x = i + 1;
		while (x < numb->size)
		{
			if (numb->arr[i] == numb->arr[x])
				return (true);
			x++;
		}
		i++;
	}
	return (false);
}
 // ! guard against top being 0
float disorder(t_stack *stack)
{
	size_t	i;
	size_t	x;
	int		mistake;
	int		total_pairs;

	mistake = 0;
	total_pairs = 0;
	i = 0;
	while (i < stack->top)
	{
		x = i + 1;
		while (x <= stack->top)
		{
			if (stack->arr[i] > stack->arr[x])
				mistake++;
			total_pairs++;
			x++;
		}
		i++;
	}
	return ((float)mistake / total_pairs);
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
