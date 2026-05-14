/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrass <magrass@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 09:23:42 by ascheufe          #+#    #+#             */
/*   Updated: 2026/05/14 17:39:51 by magrass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

typedef struct {
	char	**numbers;
	t_stack	stack_b;
	t_stack	stack_a;
	t_alg	alg_selected;
}	t_data;


int	main(int argc, char **argv)
{
	size_t	i;
	t_data	this;

	i = 0;
	this = (t_data){0};

	this.stack_a = parse_input(argc, argv, &this.alg_selected);
	printf("%f", disorder(&this.stack_a));
	if (has_dup(&this.stack_a))
		error_fun(EINVAL);
	while (i < this.stack_a.size)
	{
		printf("NUMBER: %d\n", this.stack_a.arr[i++]);
	}
	printf("---------------------------\n");
	bubble_sort(&this.stack_a);
	i = 0;
	while (i < this.stack_a.size)
	{
		printf("NUMBER: %d\n", this.stack_a.arr[i++]);
	}
}
