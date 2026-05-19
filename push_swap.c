/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascheufe <ascheufe@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 09:23:42 by ascheufe          #+#    #+#             */
/*   Updated: 2026/05/19 13:31:21 by ascheufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	run_sort(t_data *d)
{
	t_arg	alg;

	d->bench.disorder = disorder(&d->stack_a);
	if (d->bench.disorder == 0.0f)
		return ;
	alg = d->args.algorithm;
	if (alg == ARG_NONE)
	{
		if (d->bench.disorder < 0.2f)
			alg = ARG_SIMPLE;
		else
			alg = ARG_COMPLEX;
	}
	if (alg == ARG_SIMPLE)
		bubble_sort(&d->stack_a, &d->bench);
	else if (alg == ARG_MEDIUM)
		better_chunk_sort(&d->stack_a, &d->stack_b, &d->bench);
	else
		turk_sort(&d->stack_a, &d->stack_b, &d->bench);
}

int	main(int argc, char **argv)
{
	t_data	d;

	d = (t_data){0};
	d.stack_a = parse_input(argc, argv, &d.args);
	// d.stack_b.arr = malloc(sizeof(int) * d.stack_a.size);
	if (has_dup(&d.stack_a))
		error_fun(EINVAL);
	ranking(&d.stack_a);
	// chunk_sort(&d.stack_a, &d.stack_b, &d.bench);
	// better_chunk_sort(&d.stack_a, &d.stack_b, &d.bench);
	run_sort(&d);
	if (d.args.bench_on)
		print_bench_report(d.bench);

	return (0);
}
