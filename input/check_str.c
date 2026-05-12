/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrass <magrass@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 11:42:05 by ascheufe          #+#    #+#             */
/*   Updated: 2026/05/12 22:12:32 by magrass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// FIXME: overflow checking
bool	contains_only_numbers_and_spaces(char *str)
{
	size_t	i;

	i = 0;
	if (str[0] == '-' && str[1])
		str++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

char	**norm(char *argv, t_int_arr *numb)
{
	char	**arr;

	arr = ft_split(argv, ' ');
	if (!arr)
		error_fun(ENOMEM);
	if (!ft_strchr(argv, ' '))
		numb->ln = 1;
	else
		numb->ln = str_arr_len(arr);
	numb->numbers = malloc(sizeof(int) * numb->ln);
	if (!numb->numbers)
		error_fun(EINVAL);
	return (arr);
}

// ! We will need to add support for the --bench
t_int_arr	check_string_and_create(char *argv, int *alg_selected)
{
	t_int_arr	numb;
	char		**arr;
	size_t		i;
	size_t		x;
	static bool	was_selected = false;

	i = 0;
	x = 0;
	arr = norm(argv, &numb);
	while (i < numb.ln)
	{
		if (!contains_only_numbers_and_spaces(arr[i]))
		{
			*alg_selected = selected_alg(arr[i]);
			if ((*alg_selected == ALG_NONE) || !(i == 0 || i == numb.ln - 1)
				|| was_selected)
				error_fun(EINVAL);
			i++;
			was_selected = true;
			continue ;
		}
		numb.numbers[x++] = ft_atoi(arr[i++]);
	}
	numb.ln = x;
	return (numb);
}

#define ARG_COUNT 4

// ! We will need to add support for the --bench
int	selected_alg(char *argv)
{
	size_t	i;
	char	*arguments[ARG_COUNT];

	arguments[0] = "--simple";
	arguments[1] = "--medium";
	arguments[2] = "--complex";
	arguments[3] = "--adaptive";
	i = 0;
	while (i < ARG_COUNT)
	{
		if (ft_strnstr(argv, arguments[i], ft_strlen(argv)))
		{
			printf("selected: %s\n", arguments[i]);
			return (i);
		}
		i++;
	}
	return (-1);
}
