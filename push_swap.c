/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrass <magrass@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 09:23:42 by ascheufe          #+#    #+#             */
/*   Updated: 2026/05/14 19:45:33 by magrass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct {
	t_stack	stack_a;
	t_stack	stack_b;
	t_alg	alg_selected;
}	t_data;

static void	run_sort(t_data *d)
{
	float	the_disorder;
	t_alg	alg;

	the_disorder = disorder(&d->stack_a);
	if (the_disorder == 0.0f)
		return ;
	alg = d->alg_selected;
	if (alg == ALG_NONE)
	{
		if (the_disorder < 0.2f)
			alg = ALG_SIMPLE;
		else
			alg = ALG_COMPLEX;
	}
	if (alg == ALG_SIMPLE)
		bubble_sort(&d->stack_a);
	else
		turk_sort(&d->stack_a, &d->stack_b);
}

int	main(int argc, char **argv)
{
	t_data	d;

	d = (t_data){0};
	d.stack_a = parse_input(argc, argv, &d.alg_selected);
	if (has_dup(&d.stack_a))
		error_fun(EINVAL);
	run_sort(&d);
	return (0);
}
