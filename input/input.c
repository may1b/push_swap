/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascheufe <ascheufe@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 09:57:40 by ascheufe          #+#    #+#             */
/*   Updated: 2026/05/11 15:54:29 by ascheufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	selected_alg(char *argv)
{
	size_t	x;
	char	*arguments[5];

	arguments[0] = "--simple";
	arguments[1] = "--medium";
	arguments[2] = "--complex";
	arguments[3] = "--adaptive";
	arguments[4] = NULL;

	x = 0;
	while (arguments[x])
	{
		if (ft_strnstr(argv, arguments[x], ft_strlen(argv)))
		{
			printf("selected: %s\n", arguments[x]);
			return (x);
		}
		x++;
	}
	return (-1);
}

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
		num = check_string(argv[i], alg_selected); 
		if(num.ln == 0)			// * This gets used when it didnt match the normal number input
		{
			if ((i == argc - 1) && !was_selected)
				return (was_selected = true, stack);
			else if (i == 1 && !was_selected)
			{
				was_selected = true;
				i++;
				continue;
			}
			error_fun(EINVAL);
		}
		while (x < num.ln)
		{
			stack.arr[r] = num.numbers[x];
			stack.top++;
			x++;
			r++;
		}
		free(num.numbers);
		x = 0;
		i++;
	}
	return (stack);			// Only here when no alg selected
}