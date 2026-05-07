/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_alg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascheufe <ascheufe@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 11:52:59 by ascheufe          #+#    #+#             */
/*   Updated: 2026/05/07 12:03:35 by ascheufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void bubble_sort(t_stack *stack_a, t_stack *stack_b)
{
	size_t	i;
	size_t	offset;
	size_t	swap_count;
	size_t operation_count;

	swap_count = 0;
	i = 0;
	offset = 0;
	operation_count = 0;
	
	while (((stack_a->top + 1) / 2) != offset)
	{

		// Down loop
		while ((i + offset + 1) < (stack_a->top))
		{
			operation_count++;
			if (stack_a->arr[stack_a->top] < stack_a->arr[stack_a->top - 1])
			{
				swap_count++;
				operation_count++;
				sa(stack_a);
			}
			ra(stack_a);
			i++;
		}
		i = 0;
		printf("----------------------\n");
		while ((i + offset + 1) < (stack_a->top))
		{
			operation_count++;
			if (stack_a->arr[stack_a->top] < stack_a->arr[stack_a->top - 1])
			{
				swap_count++;
				operation_count++;
				sa(stack_a);
			}
			i++;
			rra(stack_a);
		}
		i = 0;
		offset++;
		printf("----------------------\n");

		
		if (swap_count == 0)
		{
			swap_count = 0;
			int	i;
			i = 0;
			printf("START OF PRINT\n");
			while (i < stack_a->top + 1)
			{
				printf("%d\n", stack_a->arr[i]);
				i++;
			}
			printf("How many operations where done: %d\n", operation_count);	
			return ;
		}
	}
	swap_count = 0;
	int	i;
	i = 0;
	printf("START OF PRINT\n");
	while (i < stack_a->top + 1)
	{
		printf("%d\n", stack_a->arr[i]);
		i++;
	}
	printf("How many operations where done: %d\n", operation_count);
}


int	main(void)
{
	t_stack stack_a;
	t_stack stack_b;


	// stack_a.arr[0] = 3;
	// stack_a.arr[1] = 6;
	// stack_a.arr[2] = 4;
	// stack_a.arr[3] = 1;
	// stack_a.arr[4] = 2;
	// stack_a.arr[5] = 5;

	stack_a.arr[0] = 6;
	stack_a.arr[1] = 5;
	stack_a.arr[2] = 4;
	stack_a.arr[3] = 3;
	stack_a.arr[4] = 2;
	stack_a.arr[5] = 1;

	// stack_a.arr[0] = 1;
	// stack_a.arr[1] = 2;
	// stack_a.arr[2] = 3;
	// stack_a.arr[3] = 4;
	// stack_a.arr[4] = 5;
	// stack_a.arr[5] = 6;
	
	// ra(&stack_a);
	// ra(&stack_a);
	// ra(&stack_a);
	// ra(&stack_a);
	// ra(&stack_a);
	
	// printf("%d", stack_a.arr[stack_a.top]);
	stack_a.top = 5;
	bubble_sort(&stack_a, &stack_b);
}