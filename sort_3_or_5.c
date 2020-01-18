/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_or_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 20:07:14 by eesaki            #+#    #+#             */
/*   Updated: 2020/01/17 16:45:04 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h> // debug purpose

void	sort_3(t_stack **stack_a, t_stack **stack_b)
{
	int		top;
	int		mid;
	int		btm;

	top = (*stack_a)->n;
	mid = (*stack_a)->next->n;
	btm = (*stack_a)->next->next->n;
	if (top < btm && btm < mid) // 1,3,2 => sa,ra
	{
		sa(stack_a, stack_b);
		ra(stack_a, stack_b);
	}
	else if (mid < top && top < btm) // 2,1,3 => sa
		sa(stack_a, stack_b);
	else if (btm < top && top < mid) // 2,3,1 => rra
		rra(stack_a, stack_b);
	else if (mid < btm && btm < top) // 3,1,2 => ra
		ra(stack_a, stack_b);
	else if (btm < mid && mid < top) // 3,2,1 => sa,rra
	{
		sa(stack_a, stack_b);
		rra(stack_a, stack_b);
	}
}

void	sort_5(t_stack **stack_a, t_stack **stack_b, int n_elms)
{
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	sort_3(stack_a, stack_b);
	while (*stack_b != NULL)
	{
		push_a(stack_a, stack_b);
		pa(stack_a, stack_b);
	}
	rotate_a(stack_a, stack_b, n_elms);
}

void	sort_3_or_5(t_stack **stack_a, t_stack **stack_b, int n_elms)
{
	if (n_elms == 3)
		sort_3(stack_a, stack_b);
	else if (n_elms == 5)
		sort_5(stack_a, stack_b, n_elms);
}

/* 

1,2,3 => already sorted
1,3,2 => sa,ra
2,1,3 => sa
2,3,1 => rra
3,1,2 => ra
3,2,1 => sa,rra

*/