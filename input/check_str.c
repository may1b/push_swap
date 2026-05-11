/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascheufe <ascheufe@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 11:42:05 by ascheufe          #+#    #+#             */
/*   Updated: 2026/05/11 16:43:27 by ascheufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


bool only_num_space(char *str)
{
	size_t	i;
	bool	space_before;
	
	i = 0;
	space_before = true;
	if (str[0] == '-')
		str++;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			space_before = false;
		else if (str[i] == ' ' && !space_before && str[i + 1])
			space_before = true;
		else
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

t_int_arr create_num_arr(char *str)
{
	size_t	i;
	char	**arr;
	t_int_arr	numb;
	
	i = 0;
	arr = ft_split(str, ' ');
	if (!arr)
		error_fun(ENOMEM);
	if (!ft_strchr(str, ' '))
		numb.ln = 1;
	else
		numb.ln = str_arr_len(arr);
	numb.numbers = malloc(sizeof(int) * numb.ln);
	if (!numb.numbers)
	{
		free_array((void **)arr, numb.ln + 1);
		error_fun(ENOMEM);
	}
	while (i < numb.ln)
	{
		numb.numbers[i] = ft_atoi(arr[i]);
		i++;
	}
	free_array((void **)arr, numb.ln);
	return (numb);
}

t_int_arr check_string_and_create(char *argv, int *alg_selected)
{
	t_int_arr	numb;
	
	if (!only_num_space(argv))		// ! If you have negative numbers it wont work anymore :(
	{
		*alg_selected = selected_alg(argv);
		if (*alg_selected == ALG_NONE)
			error_fun(EINVAL);
		numb.ln = 0;
		return (numb);
	}
	numb = create_num_arr(argv);
	if (!numb.numbers)
		error_fun(EINVAL);
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