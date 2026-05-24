/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_dispatch.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrass <magrass@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 00:00:00 by magrass           #+#    #+#             */
/*   Updated: 2026/05/24 00:00:00 by magrass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_arg	choose_sort(t_data *d)
{
	t_arg	alg;

	alg = d->args.algorithm;
	if (alg != ARG_NONE && alg != ARG_ADAPTIVE)
		return (alg);
	if (d->stack_a.size <= 5)
		return (ARG_SIMPLE);
	if (d->bench.disorder < 0.2f)
		return (ARG_ADAPTIVE);
	if (d->stack_a.size >= 1750 && d->bench.disorder >= 0.45f)
		return (ARG_COMPLEX);
	return (ARG_MEDIUM);
}

static void	set_bench_strategy(t_data *d, t_arg alg)
{
	if (alg == ARG_SIMPLE && d->stack_a.size <= 5)
	{
		d->bench.strategy = "small sort";
		d->bench.complexity = "O(1)";
	}
	else if (alg == ARG_SIMPLE)
	{
		d->bench.strategy = "bubble sort";
		d->bench.complexity = "O(n^2)";
	}
	else if (alg == ARG_ADAPTIVE)
	{
		d->bench.strategy = "lis sort";
		d->bench.complexity = "O(n^2)";
	}
	else if (alg == ARG_COMPLEX)
	{
		d->bench.strategy = "radix sort";
		d->bench.complexity = "O(n log n)";
	}
	else if (alg == ARG_MEDIUM)
	{
		d->bench.strategy = "k sort";
		d->bench.complexity = "O(n sqrt(n)) average";
	}
}

void	run_sort(t_data *d)
{
	t_arg	alg;

	d->bench.disorder = disorder(&d->stack_a);
	if (d->bench.disorder == 0.0f)
	{
		d->bench.strategy = "already sorted";
		d->bench.complexity = "O(n^2) disorder check";
		return ;
	}
	alg = choose_sort(d);
	set_bench_strategy(d, alg);
	if (alg == ARG_SIMPLE)
	{
		if (d->stack_a.size <= 5)
			small_sort(&d->stack_a, &d->stack_b, &d->bench);
		else
			bubble_sort(&d->stack_a, &d->bench);
	}
	else if (alg == ARG_ADAPTIVE)
		lis_sort(&d->stack_a, &d->stack_b, &d->bench);
	else if (alg == ARG_COMPLEX)
		radix_sort(&d->stack_a, &d->stack_b, &d->bench);
	else
		k_sort(&d->stack_a, &d->stack_b, &d->bench);
}
