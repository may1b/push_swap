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

static t_arg	choose_sort(t_data *d)
{
	t_arg	alg;

	alg = d->args.algorithm;
	if (alg != ARG_NONE)
		return (alg);
	if (d->stack_a.size <= 5)
		return (ARG_SIMPLE);
	if (d->bench.disorder < 0.35f)
		return (ARG_ADAPTIVE);
	return (ARG_MEDIUM);
}

static void	run_sort(t_data *d)
{
	t_arg	alg;

	d->bench.disorder = disorder(&d->stack_a);
	if (d->bench.disorder == 0.0f)
		return ;
	alg = choose_sort(d);
	if (alg == ARG_SIMPLE)
	{
		if (d->stack_a.size <= 5)
			small_sort(&d->stack_a, &d->stack_b, &d->bench);
		else
			bubble_sort(&d->stack_a, &d->bench);
	}
	else if (alg == ARG_ADAPTIVE)
		lis_sort(&d->stack_a, &d->stack_b, &d->bench);
	else
		k_sort(&d->stack_a, &d->stack_b, &d->bench);
}

int	main(int argc, char **argv)
{
	t_data	d;

	d = (t_data){0};
	d.stack_a = parse_input(argc, argv, &d.args);
	if (has_dup(&d.stack_a))
		error_fun(EINVAL);
	ranking(&d.stack_a);
	run_sort(&d);
	if (d.args.bench_on)
		print_bench_report(d.bench);
	return (0);
}
