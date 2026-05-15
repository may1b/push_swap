/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrass <magrass@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 22:20:58 by magrass           #+#    #+#             */
/*   Updated: 2026/05/15 22:21:39 by magrass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TURK_H
# define TURK_H

# include "../../push_swap.h"

typedef struct s_move
{
	size_t	a_idx;
	size_t	b_idx;
	int		a_cost;
	int		b_cost;
	int		total;
}	t_move;

typedef struct s_cost
{
	int	a;
	int	b;
}	t_cost;

int		cost_to_top(size_t i, size_t size);
int		combined_cost(int a_cost, int b_cost);
void	rotate_to_top_a(t_stack *a, int cost, t_bench *bench);
void	rotate_to_top_b(t_stack *b, int cost, t_bench *bench);
size_t	target_in_b(t_stack *b, int val);
size_t	target_in_a(t_stack *a, int val);
t_move	best_push_to_b(t_stack *a, t_stack *b);
void	do_b_push(t_stack *a, t_stack *b, t_move m, t_bench *bench);
int		find_smallest(t_stack *s);
int		find_largest(t_stack *s);
int		ft_abs(int n);
int		ft_max(int a, int b);

#endif
