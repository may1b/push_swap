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

static void	bench_putstr(char *str)
{
	ft_putstr_fd(str, ERROR_OUT);
}

static void	bench_putuint(unsigned int n)
{
	if (n >= 10)
		bench_putuint(n / 10);
	ft_putchar_fd((n % 10) + '0', ERROR_OUT);
}

static void	print_bench_percent(float disorder)
{
	int	whole;
	int	dec;

	whole = (int)(disorder * 100);
	dec = (int)(((disorder * 100) - whole) * 100 + 0.5f);
	if (dec == 100)
	{
		whole++;
		dec = 0;
	}
	bench_putstr("[bench] disorder:\t");
	bench_putuint((unsigned int)whole);
	bench_putstr(".");
	if (dec < 10)
		bench_putstr("0");
	bench_putuint((unsigned int)dec);
	bench_putstr("%\n");
}

static void	print_bench_op(char *name, unsigned int count, bool end)
{
	bench_putstr(name);
	bench_putstr(":\t");
	bench_putuint(count);
	if (end)
		bench_putstr("\n");
	else
		bench_putstr("\t");
}

static void	print_bench_ops(t_bench bench)
{
	bench_putstr("[bench] ");
	print_bench_op("sa", bench.sa, false);
	print_bench_op("sb", bench.sb, false);
	print_bench_op("ss", bench.ss, false);
	print_bench_op("pa", bench.pa, false);
	print_bench_op("pb", bench.pb, true);
	bench_putstr("[bench] ");
	print_bench_op("ra", bench.ra, false);
	print_bench_op("rb", bench.rb, false);
	print_bench_op("rr", bench.rr, false);
	print_bench_op("rra", bench.rra, false);
	print_bench_op("rrb", bench.rrb, false);
	print_bench_op("rrr", bench.rrr, true);
}

void	print_bench_report(t_bench bench)
{
	bench.total = bench.pa + bench.pb + bench.ra + bench.rb + bench.rr
		+ bench.rra + bench.rrb + bench.rrr + bench.sa + bench.sb + bench.ss;
	bench_putstr("------------------------------------------------------------\n");
	print_bench_percent(bench.disorder);
	bench_putstr("[bench] strategy:\t");
	bench_putstr(bench.strategy);
	bench_putstr("\n");
	bench_putstr("[bench] complexity:\t");
	bench_putstr(bench.complexity);
	bench_putstr("\n");
	bench_putstr("[bench] total_ops:\t");
	bench_putuint(bench.total);
	bench_putstr("\n");
	print_bench_ops(bench);
	bench_putstr("------------------------------------------------------------\n");
}
