/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascheufe <ascheufe@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 17:05:29 by magrass           #+#    #+#             */
/*   Updated: 2026/05/18 10:58:17 by ascheufe         ###   ########.fr       */
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

static int	parse_int(t_sv token)
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
		error_fun(ERANGE);
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

static t_sv	next_token(const char *str, size_t *pos)
{
	t_sv	token;

	while (str[*pos] == ' ')
		(*pos)++;
	token.str = str + *pos;
	while (str[*pos] && str[*pos] != ' ')
		(*pos)++;
	token.size = (str + *pos) - token.str;
	return (token);
}

static void	push_token(t_sv token, t_stack *stack, t_args *args)
{
	int	alg;

	if (sv_is_number(token))
		stack->arr[stack->size++] = parse_int(token);
	else
	{
		// ! Added dup check of arg
		// alg = sv_parse_alg(token);
		// if (alg == ARG_NONE)
		// 	error_fun(EINVAL);
		// if (alg == ARG_BENCH)				// * ADDED BENCH SUPPORT
		// 	args->bench_on = true;
		// else
		// 	args->algorithm = alg;

		alg = sv_parse_alg(token);
		if (alg == ARG_NONE)
			error_fun(EINVAL);
		if (((alg == ARG_BENCH && args->bench_on) ||
			(alg != ARG_BENCH && args->algorithm != ARG_NONE)))
			error_fun(EINVAL);
		if (alg == ARG_BENCH)				// * ADDED BENCH SUPPORT
			args->bench_on = true;
		else
			args->algorithm = alg;
	}
}

// GLORIOS Input parsing with 0 allocations
t_stack	parse_input(int argc, char **argv, t_args *args)
{
	t_stack	stack;
	t_sv	token;
	size_t	i;
	size_t	j;

	stack = (t_stack){0};
	if (argc < 2)
		error_fun(EINVAL);
	i = 1;
	while (i < (size_t)argc)
	{
		j = 0;
		while (argv[i][j])
		{
			token = next_token(argv[i], &j);
			if (token.size)
				push_token(token, &stack, args);
		}
		i++;
	}
	return (stack);
}

size_t  count_numbers(char **argv, int argc)
{
    size_t  count;
    size_t  i;
    char    *tmp;

    count = 0;
    i = 1;
    while (i < (size_t)argc)
    {
        tmp = argv[i];
        while (*tmp)
        {
            while (*tmp == ' ') tmp++;
            if (*tmp) count++;
            while (*tmp && *tmp != ' ') tmp++;
        }
        i++;
    }
    return (count);
}

void	ranking(t_stack *stack)
{
	int	rank;
	size_t	i;
	size_t	j;
	int		*original;

	original = malloc(sizeof(int) * stack->size + 1);
	if (!original)
		error_fun(ENOMEM);
	i = 0;
	while (i < stack->size)
	{
		original[i] = stack->arr[i];
		i++;
	}
	i = 0;
	while (i < stack->size)
	{
		j = 0;
		rank = 0;
		while (j < stack->size)
		{
			if (original[j] < original[i])
				rank++;
			j++;
		}
		stack->arr[i] = rank;
		i++;
	}
	free(original);
}