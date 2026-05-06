/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascheufe <ascheufe@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 10:32:15 by ascheufe          #+#    #+#             */
/*   Updated: 2026/04/22 15:22:11 by ascheufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*t;

	if (!lst || !del || !*lst)
		return ;
	tmp = *lst;
	while (tmp)
	{
		del(tmp->content);
		t = tmp;
		tmp = tmp->next;
		free(t);
	}
	*lst = NULL;
}
