/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascheufe <ascheufe@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 09:23:42 by ascheufe          #+#    #+#             */
/*   Updated: 2026/05/06 12:05:54 by ascheufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	printf("%d\n", stack_a.arr[1]);

	
}
