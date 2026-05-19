/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::	  */
/*	 better_chunk.c										:+:		 :+:	:+:	  */
/*													  +:+ +:+		  +:+	  */
/*	 By: ascheufe <ascheufe@student.42heilbronn.	+#+	 +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2026/05/19 12:30:00 by ascheufe		   #+#	  #+#			  */
/*	 Updated: 2026/05/19 13:15:00 by ascheufe		  ###	########.fr	  */
/*																			  */
/* ************************************************************************** */

#include "../../push_swap.h"

void	better_chunk_sort(t_stack *stack_a, t_stack *stack_b,
	t_bench *bench)
{
	size_t	n;
	size_t	num_chunks;

	n = stack_a->size;
	if (n <= 1)
		return ;
	if (n <= 10)
		num_chunks = 1;
	else if (n <= 100)
		num_chunks = 5;
	else
		num_chunks = 11;
	push_all_chunks(stack_a, stack_b, num_chunks, bench);
	while (stack_b->size)
		pull_back_stack_b(stack_a, stack_b, bench);
}
