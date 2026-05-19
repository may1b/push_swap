/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascheufe <ascheufe@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 09:46:46 by ascheufe          #+#    #+#             */
/*   Updated: 2026/05/18 10:13:59 by ascheufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_bench_ops(t_bench bench)
{
	ft_printf("[bench] sa:\t%u\tsb:\t%u\tss:\t%u\tpa:\t%u\tpb:\t%u\n",
		bench.sa, bench.sb, bench.ss, bench.pa, bench.pb);
	ft_printf("[bench] ra:\t%u\trb:\t%u\trr:\t%u\t"
		"rra:\t%u\trrb:\t%u\trrr:\t%u\n",
		bench.ra, bench.rb, bench.rr, bench.rra, bench.rrb, bench.rrr);
}

void	print_bench_report(t_bench bench)
{
	int	whole;
	int	dec;

	whole = (int)(bench.disorder * 100);
	dec = (int)(((bench.disorder * 100) - whole) * 100 + 0.5f);
	bench.total = bench.pa + bench.pb + bench.ra + bench.rb + bench.rr
		+ bench.rra + bench.rrb + bench.rrr + bench.sa + bench.sb + bench.ss;
	ft_printf("------------------------------------------------------------\n");
	ft_printf("[bench] disorder:\t");
	if (dec < 10)
		ft_printf("%d.0%d%%\n", whole, dec);
	else
		ft_printf("%d.%d%%\n", whole, dec);
	ft_printf("[bench] strategy:\t%s\n", bench.strategy);
	ft_printf("[bench] total_ops:\t%u\n", bench.total);
	print_bench_ops(bench);
	ft_printf("------------------------------------------------------------\n");
}
