/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrass <magrass@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 00:00:00 by magrass           #+#    #+#             */
/*   Updated: 2026/05/24 00:00:00 by magrass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_data(t_data *d, int error)
{
	free(d->stack_a.arr);
	free(d->stack_b.arr);
	error_fun(error);
}

void	init_data(t_data *d, int argc, char **argv)
{
	*d = (t_data){0};
	d->stack_a = parse_input(argc, argv, &d->args);
	if (d->stack_a.size)
		d->stack_b.arr = malloc(sizeof(int) * d->stack_a.size);
	if (d->stack_a.size && !d->stack_b.arr)
		free_data(d, ENOMEM);
	if (has_dup(&d->stack_a))
		free_data(d, EINVAL);
	if (!ranking(&d->stack_a))
		free_data(d, ENOMEM);
}

void	destroy_data(t_data *d)
{
	free(d->stack_a.arr);
	free(d->stack_b.arr);
}
