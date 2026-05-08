/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascheufe <ascheufe@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 09:57:40 by ascheufe          #+#    #+#             */
/*   Updated: 2026/05/08 12:26:16 by ascheufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	selected_alg(char **argv)
{
	size_t	i;
	size_t	x;
	char	*arguments[5];

	arguments[0] = "--simple";
	arguments[1] = "--medium";
	arguments[2] = "--complex";
	arguments[3] = "--adaptive";
	arguments[4] = NULL;

	i = 1;
	while (argv[i])
	{
		x = 0;
		while (arguments[x])
		{
			if (ft_strnstr(argv[i], arguments[x], ft_strlen(argv[i])))
			{
				printf("selected: %s\n", arguments[x]);
				return (x);
			}
			x++;
		}
		i++;
	}
	return (-1);
}



t_stack *input_handler(int argc, char **argv)
{
	t_stack	*stack;
	size_t	i;

	i = 1;
	
	// *Not enough arguments
	if (argc < 2)
		error_fun(EINVAL);
	
	// ! Might get removed. Unsure of use
	while (argv[i])
	{
		if(!check_string(argv[i]))
			// TODO: Should check if its a arg
		stack->arr[i]
		i++;
	}
}