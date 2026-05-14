/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrass <magrass@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 17:05:29 by magrass           #+#    #+#             */
/*   Updated: 2026/05/14 17:35:22 by magrass          ###   ########.fr       */
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
		return (ALG_SIMPLE);
	if (sv_eq(t, "--medium"))
		return (ALG_MEDIUM);
	if (sv_eq(t, "--complex"))
		return (ALG_COMPLEX);
	if (sv_eq(t, "--adaptive"))
		return (ALG_ADAPTIVE);
	return (ALG_NONE);
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

static void	push_token(t_sv token, t_stack *stack, t_alg *alg_selected)
{
	int	alg;

	if (sv_is_number(token))
		stack->arr[stack->size++] = parse_int(token);
	else
	{
		alg = sv_parse_alg(token);
		if (alg == ALG_NONE)
			error_fun(EINVAL);
		*alg_selected = alg;
	}
}

// GLORIOS Input parsing with 0 allocations
t_stack	parse_input(int argc, char **argv, t_alg *alg_selected)
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
				push_token(token, &stack, alg_selected);
		}
		i++;
	}
	return (stack);
}
