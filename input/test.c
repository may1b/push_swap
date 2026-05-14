/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrass <magrass@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 11:42:05 by ascheufe          #+#    #+#             */
/*   Updated: 2026/05/14 16:29:04 by magrass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool	contains_only_numbers(char *str)
{
	size_t	i;
	bool	space_before;

	i = 0;
	space_before = true;
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
		if (!contains_only_numbers(arr[i]))
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

// ! We will need to add support for the --bench
int	selected_alg(char *argv)
{
	size_t	x;
	char	*arguments[5];

	arguments[0] = "--simple";
	arguments[1] = "--medium";
	arguments[2] = "--complex";
	arguments[3] = "--adaptive";
	arguments[4] = NULL;
	x = 0;
	while (arguments[x])
	{
		if (ft_strnstr(argv, arguments[x], ft_strlen(argv)))
			return (x);
		x++;
	}
	return (-1);
}
