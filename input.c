/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascheufe <ascheufe@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 17:05:29 by magrass           #+#    #+#             */
/*   Updated: 2026/05/19 13:46:56 by ascheufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	sv_is_number(t_sv token)
{
	size_t	i;

	if (token.size == 0)
		return (false);
	i = 0;
	if (token.str[0] == '-' && token.size > 1)
		i = 1;
	while (i < token.size)
		if (!ft_isdigit(token.str[i++]))
			return (false);
	return (true);
}

static int	parse_int(t_sv token, t_stack *stack)
{
	long	n;
	int		sign;
	size_t	i;

	n = 0;
	sign = 1;
	i = 0;
	if (token.str[0] == '-')
	{
		sign = -1;
		i++;
	}
	while (i < token.size)
		n = n * 10 + (token.str[i++] - '0');
	n *= sign;
	if (n > INT_MAX || n < INT_MIN)
	{
		free(stack->arr);
		error_fun(ERANGE);
	}
	return ((int)n);
}

static int	sv_parse_alg(t_sv t)
{
	if (sv_eq(t, "--simple"))
		return (ARG_SIMPLE);
	if (sv_eq(t, "--medium"))
		return (ARG_MEDIUM);
	if (sv_eq(t, "--complex"))
		return (ARG_COMPLEX);
	if (sv_eq(t, "--adaptive"))
		return (ARG_ADAPTIVE);
	if (sv_eq(t, "--bench"))
		return (ARG_BENCH);
	return (ARG_NONE);
}

void	push_token(t_sv token, t_stack *stack, t_args *args)
{
	int	alg;

	if (sv_is_number(token))
		stack->arr[stack->size++] = parse_int(token, stack);
	else
	{
		alg = sv_parse_alg(token);
		if (alg == ARG_NONE)
		{
			free(stack->arr);
			error_fun(EINVAL);
		}
		if (((alg == ARG_BENCH && args->bench_on)
				|| (alg != ARG_BENCH && args->algorithm != ARG_NONE)))
		{
			free(stack->arr);
			error_fun(EINVAL);
		}
		if (alg == ARG_BENCH)
			args->bench_on = true;
		else
			args->algorithm = alg;
	}
}

t_stack	parse_input(int argc, char **argv, t_args *args)
{
	t_stack	stack;
	size_t	count;

	stack = (t_stack){0};
	if (argc < 2)
		error_fun(EINVAL);
	count = count_numbers(argv, argc);
	if (!count)
		error_fun(EINVAL);
	stack.arr = malloc(sizeof(int) * count);
	if (!stack.arr)
		error_fun(ENOMEM);
	parse_tokens(argv, argc, &stack, args);
	return (stack);
}
