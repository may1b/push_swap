/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascheufe <ascheufe@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 09:57:40 by ascheufe          #+#    #+#             */
/*   Updated: 2026/05/08 11:13:32 by ascheufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <errno.h>	// We are allowed to use exit() So might as well use proper exitcodes!

bool	strat(char **argv)
{
	size_t	i;
	size_t	x;
	char	*arguments[5];

	arguments[0] = "--simple";
	arguments[1] = "--medium";
	arguments[2] = "--complex";
	arguments[3] = "--adaptive";
	arguments[4] = NULL;

	i = 1;
	while (argv[i])
	{
		x = 0;
		while (arguments[x])
		{
			if (ft_strnstr(argv[i], arguments[x], ft_strlen(argv[i])))
			{
				printf("selected: %s\n", arguments[x]);
				return (true);
			}
			x++;
		}
		i++;
	}
	return (false);
}


bool is_just_num(char *str)
{
	size_t	i;
	bool	space_before;
	
	i = 0;
	space_before = true;
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
	printf("Valid number string\n");
	return (true);
}

bool has_dup(int *numbers)
{
	size_t	i;
	size_t	x;
	
	i = 0;
	x = 0;
	while (numbers[i])
	{
		x = i + 1;
		while (numbers[x])
		{
			if (numbers[i] == numbers[x])
				return (true);
			x++;
		}
		i++;
	}
	return (false);
}

t_stack	*create_stack(char *str)
{
	char	*s;
	int		*numbers;
	size_t	i;
	t_stack	stack_a;

	stack_a.top = -1;
	s = ft_split(str, ' ');				// MEMORY FREE!
	i = 0;
	if (!s)
		exit(ENOMEM);	// Hard exit as we cant recover
	while (s[i])
	{
		stack_a.arr[i] = ft_atoi(s[i]);
		stack_a.top = i++;
	}
	free(s);		// Not needed anymore
	if (has_dup(stack_a.arr))
		exit(EINVAL);
	return (&stack_a);
	
}
bool input_handler(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_putstr_fd("ERROR Input must at least include one argument\n", ERROR_OUT);
		exit(EINVAL);
	}

	if (argc == 2)
	{
		if (!is_just_num(argv[1]))
			exit(EINVAL);
		if (!create_stack(argv[1]))
			return (false);
	}


	
	if (!strat(argv))
		return (false);
	return (true);
}