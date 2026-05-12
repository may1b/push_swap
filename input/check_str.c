/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascheufe <ascheufe@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 11:42:05 by ascheufe          #+#    #+#             */
/*   Updated: 2026/05/12 09:51:27 by ascheufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


bool only_num_space(char *str)
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

bool has_dup(t_stack numb)
{
	size_t	i;
	size_t	x;
	
	i = 0;
	x = 0;
	while (i < (numb.top + 1))
	{
		x = i + 1;
		while (x < (numb.top + 1))
		{
			if (numb.arr[i] == numb.arr[x])
				return (true);
			x++;
		}
		i++;
	}
	return (false);
}

t_int_arr check_string_and_create(char *argv, int *alg_selected)
{
	t_int_arr	numb;
	char	**arr;
	size_t	i;
	size_t	x;
	static bool was_selected = false;

	i = 0;
	x = 0;
	arr = ft_split(argv, ' ');
	if (!arr)
		error_fun(ENOMEM);
	if (!ft_strchr(argv, ' '))
		numb.ln = 1;
	else
		numb.ln = str_arr_len(arr);
	numb.numbers = malloc(sizeof(int) * numb.ln);
	if (!numb.numbers)
		error_fun(EINVAL);
	while (i < numb.ln)
	{
		if (!only_num_space(arr[i]))
		{
			*alg_selected = selected_alg(arr[i]);
			if ((*alg_selected == ALG_NONE) || !(i == 0 || i == numb.ln - 1) || was_selected)
				error_fun(EINVAL);
			i++;
			was_selected = true;
			continue;
		}
		numb.numbers[x] = ft_atoi(arr[i]);
		x++;
		i++;
	}
	numb.ln = x;
	return (numb);
}
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
		{
			printf("selected: %s\n", arguments[x]);
			return (x);
		}
		x++;
	}
	return (-1);
}