/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascheufe <ascheufe@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 09:57:40 by ascheufe          #+#    #+#             */
/*   Updated: 2026/05/08 14:18:30 by ascheufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
	int		*numbers;
	size_t	i;
	size_t	x;

	i = 1;
	x = 0;
	// *Not enough arguments
	if (argc < 2)
		error_fun(EINVAL);
	
	numbers = check_string(argv[i]);
	// ! Might get removed. Unsure of use
	// while (argv[i])
	// {
	// 	numbers = check_string(argv[i]); 
	// 	if(!numbers)
	// 		// TODO: Should check if its a arg
	// 	while (numbers[x])
	// 	{
	// 		stack->arr[i] = numbers[x];
	// 		x++;
	// 		i++;
	// 	}
	// 	x = 0;
	// 	i++;
	// }
	// stack->top = i - 1;
	// printf("%d\n", stack->arr[0]);
	printf("%d", numbers[0]);
}