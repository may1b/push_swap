/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrass <magrass@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 09:46:46 by ascheufe          #+#    #+#             */
/*   Updated: 2026/05/16 19:06:21 by magrass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	print_bench_report(t_bench bench)
{
	bench.total = bench.pa + bench.pb + bench.ra + bench.rb + bench.rr
		+ bench.rra + bench.rrb + bench.rrr + bench.sa + bench.sb + bench.ss;
	// ! Replace with own printf
	printf("------------------------------------------------------------------------------------------------\n");
	printf("[bench] disorder:	%.2f%%\n", bench.disorder * 100);
	printf("[bench] strategy:	%s\n", bench.strategy);
	printf("[bench] total_ops:	%u\n", bench.total);
	printf("[bench] sa:	%u\tsb:	%u\tss:	%u\tpa:	%u\tpb:	%u\n", bench.sa,
			bench.sb, bench.ss, bench.pa, bench.pb);
	printf("[bench] ra:	%u\trb:	%u\trr:	%u\trra:	%u\trrb:	%u\trrr:	\
		%u\n", bench.ra, bench.rb, bench.rr, bench.rra, bench.rrb, bench.rrr);
	printf("------------------------------------------------------------------------------------------------\n");
}
