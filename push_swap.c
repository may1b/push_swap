/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascheufe <ascheufe@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 09:23:42 by ascheufe          #+#    #+#             */
/*   Updated: 2026/05/11 15:35:56 by ascheufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		alg_selected;
	t_stack stack_a;
	t_stack stack_b;
	char	**numbers;
	size_t	i;

	alg_selected = -1;
	stack_a.top = -1;
	stack_b.top = -1;
	numbers = NULL;
	i = 0;

	// * THIS IS THE INPUT HANDLER, IT DOES ALL THE INPUT THINGS
	// TODO: It does not return the selected alg yet
	stack_a = input_handler(argc, argv, &alg_selected);

	while (i <= stack_a.top)
	{
		printf("NUMBER: %d\n", stack_a.arr[i++]);
	}
	// if (!input_handler(argc, argv))
		// return (-1);
		
}
