/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrass <magrass@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 00:00:00 by magrass           #+#    #+#             */
/*   Updated: 2026/05/19 00:00:00 by magrass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	rrr(t_stack *stack_a, t_stack *stack_b, t_bench *bench)
{
	if (!stack_a->size || !stack_b->size)
		return (false);
	stack_shift(stack_a, true);
	stack_shift(stack_b, true);
	write(1, "rrr\n", 4);
	bench->rrr++;
	return (true);
}
