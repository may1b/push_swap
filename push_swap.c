/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascheufe <ascheufe@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 09:23:42 by ascheufe          #+#    #+#             */
/*   Updated: 2026/05/08 13:25:15 by ascheufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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

	// * THIS IS THE INPUT HANDLER, IT DOES ALL THE INPUT THINGS
	// TODO: It does not return the selected alg yet
	if (!input_handler(argc, argv))
		return (-1);
		
}
