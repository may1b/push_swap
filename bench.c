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
	ft_putstr_fd("[bench] disorder:\t", ERROR_OUT);
	bench_putuint((unsigned int)whole);
	ft_putstr_fd(".", ERROR_OUT);
	if (dec < 10)
		ft_putstr_fd("0", ERROR_OUT);
	bench_putuint((unsigned int)dec);
	ft_putstr_fd("%\n", ERROR_OUT);
}

static void	print_bench_op(char *name, unsigned int count, bool end)
{
	ft_putstr_fd(name, ERROR_OUT);
	ft_putstr_fd(":\t", ERROR_OUT);
	bench_putuint(count);
	if (end)
		ft_putstr_fd("\n", ERROR_OUT);
	else
		ft_putstr_fd("\t", ERROR_OUT);
}

static void	print_bench_ops(t_bench bench)
{
	ft_putstr_fd("[bench] ", ERROR_OUT);
	print_bench_op("sa", bench.sa, false);
	print_bench_op("sb", bench.sb, false);
	print_bench_op("ss", bench.ss, false);
	print_bench_op("pa", bench.pa, false);
	print_bench_op("pb", bench.pb, true);
	ft_putstr_fd("[bench] ", ERROR_OUT);
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
	ft_putstr_fd("------------------------------", ERROR_OUT);
	ft_putstr_fd("------------------------------\n", ERROR_OUT);
	print_bench_percent(bench.disorder);
	ft_putstr_fd("[bench] strategy:\t", ERROR_OUT);
	ft_putstr_fd(bench.strategy, ERROR_OUT);
	ft_putstr_fd("\n", ERROR_OUT);
	ft_putstr_fd("[bench] complexity:\t", ERROR_OUT);
	ft_putstr_fd(bench.complexity, ERROR_OUT);
	ft_putstr_fd("\n", ERROR_OUT);
	ft_putstr_fd("[bench] total_ops:\t", ERROR_OUT);
	bench_putuint(bench.total);
	ft_putstr_fd("\n", ERROR_OUT);
	print_bench_ops(bench);
	ft_putstr_fd("------------------------------", ERROR_OUT);
	ft_putstr_fd("------------------------------\n", ERROR_OUT);
}
