/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascheufe <ascheufe@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 09:23:42 by ascheufe          #+#    #+#             */
/*   Updated: 2026/05/07 14:51:04 by ascheufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>



// Check input
// --alg must be either at the start or the end or nowhere
// It is only allowed to be defiend once no duplicates

// Simple thing: firstly check if it is anywhere at all




















bool	strat(char **argv)
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
				return (true);
			}
			x++;
		}
		i++;
	}
	return (false);
}





int	main(int argc, char **argv)
{
	
	t_stack stack_a;
	t_stack stack_b;
	char	**numbers;
	size_t	i;

	stack_a.top = -1;
	stack_b.top = -1;
	numbers = NULL;
	i = 0;

	if (argc < 2)
	{
		printf("ERROR\n");
		return (-1);
	}
	if (!strat(argv))
		return (-1);
	// Need to handle input checking. For now IGNORE

	// We expect a input of a string like this: "9 8 7 6 5 4 3 2 1"
	// We do NOT expect input of bigger numbers than 9 for now
	numbers = ft_split(argv[1], ' ');
	while (numbers[i])
	{
		stack_a.arr[i] = numbers[i][0] - '0';
		stack_a.top = i;
		i++;
	}
	printf("%d\n", stack_a.arr[0]);

	
}
