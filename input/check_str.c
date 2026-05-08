/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascheufe <ascheufe@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 11:42:05 by ascheufe          #+#    #+#             */
/*   Updated: 2026/05/08 14:26:14 by ascheufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


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
	return (true);
}

bool has_dup(int *numbers, size_t ln)
{
	size_t	i;
	size_t	x;
	
	i = 0;
	x = 0;
	while (i < ln)
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


// TODO: This could be changed to **str to handle string input and 2D string input
int	*create_num_arr(char *str)
{
	char	**s;
	int		*numbers;
	size_t	i;
	size_t	str_ln;
	size_t	s_ln;

	i = 0;
	str_ln = ft_strlen(str);
	if (ft_strchr(str, ' '))
	{
		s = ft_split(str, ' ');		// ! MEMORY FREE!
		if (!s)
			error_fun(ENOMEM);
		s_ln = ft_strlen(*s);
		printf(" STR LN: %d\n");
		numbers = malloc(sizeof(int) * s_ln);
		if (!numbers)
			error_fun(ENOMEM);
	}
	else
	{
		numbers = malloc(sizeof(int));
		if (!numbers)
			error_fun(ENOMEM);
		s_ln = 1;
	}
	while (i < s_ln)
	{
		numbers[i] = ft_atoi(s[i]);
		i++;
	}
	// ! DOES NOT FREE PROPER CONTENTS
	// free(s);
	if (has_dup(numbers, s_ln))
		return (NULL);
		//exit(EINVAL);
	printf("%d\n", numbers[1]);
	return (numbers);
	
}

// t_stack	*create_stack_bak(char *str)
// {
// 	char	*s;
// 	int		*numbers;
// 	size_t	i;
// 	t_stack	stack_a;

// 	stack_a.top = -1;
// 	s = ft_split(str, ' ');				// MEMORY FREE!
// 	i = 0;
// 	if (!s)
// 		error_fun(ENOMEM);
// 	while (s[i])
// 	{
// 		stack_a.arr[i] = ft_atoi(s[i]);
// 		stack_a.top = i++;
// 	}
// 	free(s);		// Not needed anymore
// 	if (has_dup(stack_a.arr))			// Not sure if we should quit here instant or return false and then quit
// 		return (NULL);
// 		//exit(EINVAL);
// 	return (&stack_a);
	
// }
int	*check_string(char *argv)
{
	int	*numbers;
	
	if (!is_just_num(argv))
		error_fun(EINVAL);
	numbers = create_num_arr(argv);
	if (!numbers)
		error_fun(EINVAL);
	return (numbers);
}