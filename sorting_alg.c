/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_alg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascheufe <ascheufe@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 11:52:59 by ascheufe          #+#    #+#             */
/*   Updated: 2026/05/12 10:29:03 by ascheufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int operate_count;

operate_count = 0;

// iterates trough the stack and sorts for biggest up
size_t static swap_and_push(t_stack *stack_a, bool(*r)(t_stack *), size_t offset)
{
	size_t	i;
	size_t	swap_count;

	i = 0;
	swap_count = 0;
	while ((i + offset + 1) < (stack_a->top))
	{
		if (stack_a->arr[stack_a->top] < stack_a->arr[stack_a->top - 1])
		{
			operate_count++;
			swap_count++;
			sa(stack_a);
		}
		operate_count++;
		r(stack_a);
		i++;
	}
	return (swap_count);
}

void bubble_sort_new(t_stack *stack_a, t_stack *stack_b)
{
	size_t	i;
	size_t	offset;
	size_t	swap_count;
	
	swap_count = 0;
	i = 0;
	offset = 0;	
	while (((stack_a->top + 1) / 2) != offset)
	{
		swap_count += swap_and_push(stack_a, ra, offset);
		swap_count += swap_and_push(stack_a, rra, offset);
		offset++;
		if (swap_count == 0)
			return ;
		swap_count = 0;
	}
}
















// void bubble_sort_legecy(t_stack *stack_a, t_stack *stack_b)
// {
// 	size_t	i;
// 	size_t	offset;
// 	size_t	swap_count;
	
// 	swap_count = 0;
// 	i = 0;
// 	offset = 0;	
// 	while (((stack_a->top + 1) / 2) != offset)
// 	{
// 		while ((i + offset + 1) < (stack_a->top))
// 		{
// 			if (stack_a->arr[stack_a->top] < stack_a->arr[stack_a->top - 1])
// 			{
// 				swap_count++;
// 				sa(stack_a);
// 			}
// 			ra(stack_a);
// 			i++;
// 		}
// 		i = 0;
// 		while ((i + offset + 1) < (stack_a->top))
// 		{
// 			if (stack_a->arr[stack_a->top] < stack_a->arr[stack_a->top - 1])
// 			{
// 				swap_count++;
// 				sa(stack_a);
// 			}
// 			i++;
// 			rra(stack_a);
// 		}
// 		i = 0;
// 		offset++;
// 		if (swap_count == 0)
// 			return ;
// 	}
// }


// int	main(void)
// {
// 	t_stack stack_a;
// 	t_stack stack_b;


// 	// stack_a.arr[0] = 3;
// 	// stack_a.arr[1] = 6;
// 	// stack_a.arr[2] = 4;
// 	// stack_a.arr[3] = 1;
// 	// stack_a.arr[4] = 2;
// 	// stack_a.arr[5] = 5;
// 	// stack_a.arr[6] = 7;


	
// 	stack_a.arr[0] = 6;
// 	stack_a.arr[1] = 5;
// 	stack_a.arr[2] = 4;
// 	stack_a.arr[3] = 3;
// 	stack_a.arr[4] = 2;
// 	stack_a.arr[5] = 1;
// 	stack_a.arr[6] = 0;

// 	// stack_a.arr[0] = 1;
// 	// stack_a.arr[1] = 2;
// 	// stack_a.arr[2] = 3;
// 	// stack_a.arr[3] = 4;
// 	// stack_a.arr[4] = 5;
// 	// stack_a.arr[5] = 6;
// 	// stack_a.arr[6] = 7;
	
// 	// ra(&stack_a);
// 	// ra(&stack_a);
// 	// ra(&stack_a);
// 	// ra(&stack_a);
// 	// ra(&stack_a);


// // 	stack_a.arr[0] = 13;
// // stack_a.arr[1] = 78;
// // stack_a.arr[2] = 62;
// // stack_a.arr[3] = 17;
// // stack_a.arr[4] = 80;
// // stack_a.arr[5] = 43;
// // stack_a.arr[6] = 64;
// // stack_a.arr[7] = 24;
// // stack_a.arr[8] = 54;
// // stack_a.arr[9] = 68;
// // stack_a.arr[10] = 97;
// // stack_a.arr[11] = 21;
// // stack_a.arr[12] = 46;
// // stack_a.arr[13] = 93;
// // stack_a.arr[14] = 45;
// // stack_a.arr[15] = 87;
// // stack_a.arr[16] = 77;
// // stack_a.arr[17] = 23;
// // stack_a.arr[18] = 52;
// // stack_a.arr[19] = 98;
// // stack_a.arr[20] = 7;
// // stack_a.arr[21] = 84;
// // stack_a.arr[22] = 38;
// // stack_a.arr[23] = 81;
// // stack_a.arr[24] = 86;
// // stack_a.arr[25] = 41;
// // stack_a.arr[26] = 36;
// // stack_a.arr[27] = 92;
// // stack_a.arr[28] = 61;
// // stack_a.arr[29] = 22;
// // stack_a.arr[30] = 3;
// // stack_a.arr[31] = 49;
// // stack_a.arr[32] = 40;
// // stack_a.arr[33] = 79;
// // stack_a.arr[34] = 70;
// // stack_a.arr[35] = 63;
// // stack_a.arr[36] = 26;
// // stack_a.arr[37] = 19;
// // stack_a.arr[38] = 60;
// // stack_a.arr[39] = 56;
// // stack_a.arr[40] = 100;
// // stack_a.arr[41] = 53;
// // stack_a.arr[42] = 66;
// // stack_a.arr[43] = 11;
// // stack_a.arr[44] = 30;
// // stack_a.arr[45] = 71;
// // stack_a.arr[46] = 72;
// // stack_a.arr[47] = 31;
// // stack_a.arr[48] = 28;
// // stack_a.arr[49] = 16;
// // stack_a.arr[50] = 1;
// // stack_a.arr[51] = 9;
// // stack_a.arr[52] = 76;
// // stack_a.arr[53] = 15;
// // stack_a.arr[54] = 82;
// // stack_a.arr[55] = 29;
// // stack_a.arr[56] = 91;
// // stack_a.arr[57] = 35;
// // stack_a.arr[58] = 73;
// // stack_a.arr[59] = 65;
// // stack_a.arr[60] = 69;
// // stack_a.arr[61] = 89;
// // stack_a.arr[62] = 88;
// // stack_a.arr[63] = 90;
// // stack_a.arr[64] = 37;
// // stack_a.arr[65] = 14;
// // stack_a.arr[66] = 51;
// // stack_a.arr[67] = 12;
// // stack_a.arr[68] = 58;
// // stack_a.arr[69] = 95;
// // stack_a.arr[70] = 99;
// // stack_a.arr[71] = 94;
// // stack_a.arr[72] = 20;
// // stack_a.arr[73] = 25;
// // stack_a.arr[74] = 39;
// // stack_a.arr[75] = 74;
// // stack_a.arr[76] = 75;
// // stack_a.arr[77] = 8;
// // stack_a.arr[78] = 57;
// // stack_a.arr[79] = 34;
// // stack_a.arr[80] = 32;
// // stack_a.arr[81] = 85;
// // stack_a.arr[82] = 2;
// // stack_a.arr[83] = 6;
// // stack_a.arr[84] = 44;
// // stack_a.arr[85] = 96;
// // stack_a.arr[86] = 83;
// // stack_a.arr[87] = 33;
// // stack_a.arr[88] = 18;
// // stack_a.arr[89] = 5;
// // stack_a.arr[90] = 59;
// // stack_a.arr[91] = 47;
// // stack_a.arr[92] = 4;
// // stack_a.arr[93] = 67;
// // stack_a.arr[94] = 42;
// // stack_a.arr[95] = 50;
// // stack_a.arr[96] = 48;
// // stack_a.arr[97] = 55;
// // stack_a.arr[98] = 10;
// // stack_a.arr[99] = 27;
// // stack_a.top = 99;
	
// 	// printf("%d", stack_a.arr[stack_a.top]);
// 	stack_a.top = 6;
// 	bubble_sort_new(&stack_a, &stack_b);
	
// 	int i = 0;
// 	// while (i < stack_a.top + 1)
// 	// {
// 	// 	printf("%d\n", stack_a.arr[i]);
// 	// 	i++;
// 	// }
// 	printf("Operations: %d\n", operate_count);
// }