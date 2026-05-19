/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrass <magrass@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 00:00:00 by magrass           #+#    #+#             */
/*   Updated: 2026/05/19 00:00:00 by magrass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	stack_swap(t_stack *stack)
{
	int	tmp;

	if (stack->size < 2)
		return (false);
	tmp = stack->arr[0];
	stack->arr[0] = stack->arr[1];
	stack->arr[1] = tmp;
	return (true);
}

bool	stack_push(t_stack *from, t_stack *to)
{
	if (!from->size)
		return (false);
	ft_memmove(to->arr + 1, to->arr, to->size * sizeof(int));
	to->arr[0] = from->arr[0];
	to->size++;
	ft_memmove(from->arr, from->arr + 1, (from->size - 1) * sizeof(int));
	from->size--;
	return (true);
}

bool	stack_shift(t_stack *stack, bool reverse)
{
	int	tmp;

	if (!stack->size)
		return (false);
	if (!reverse)
	{
		tmp = stack->arr[0];
		ft_memmove(stack->arr, stack->arr + 1, (stack->size - 1) * sizeof(int));
		stack->arr[stack->size - 1] = tmp;
	}
	else
	{
		tmp = stack->arr[stack->size - 1];
		ft_memmove(stack->arr + 1, stack->arr, (stack->size - 1) * sizeof(int));
		stack->arr[0] = tmp;
	}
	return (true);
}
