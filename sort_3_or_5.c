/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_or_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 20:07:14 by eesaki            #+#    #+#             */
/*   Updated: 2019/12/12 23:46:38 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h> // debug purpose

int		find_max(t_stack *stack_a)
{
	while (stack_a->next != NULL)
		stack_a = stack_a->next;
	return (stack_a->n);
}

int		ra_or_rra(t_stack *stack_a __attribute__((unused)), t_stack *stack_b __attribute__((unused)), int n_elms, int pos)
{
	 if (pos < n_elms / 5)
	 	return (1);
	else
		return (0);
}

int		find_pos(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*a;
	int		pos;
	int		min;
	int		max;

	a = *stack_a;
	pos = 0;
	min = (*stack_a)->n;
	max = find_max(*stack_a);
	while (a->next != NULL)
	{
		if (a->n < (*stack_b)->n && a->next->n > (*stack_b)->n)// TODO:	[] fix this
			return (pos);
		pos++;
		a = a->next;
	}
	printf("could not find pos in find_pos()\n"); // debug purpose
	exit(1);
}

void	push_a(t_stack **stack_a, t_stack **stack_b, int n_elms)
{
	int		pos;

	pos = find_pos(stack_a, stack_b);
	if (ra_or_rra(*stack_a, *stack_b, n_elms, pos)) // 1 == ra | 0 == rra
	{
		printf("ra called from push_a()\n");
		// while (/* correct pos is NOT at top of A */)
		// 	ra();
	}
	else
	{
		printf("rra called from push_a()\n");
		// while (/* correct pos is NOT at top of A */)
		// 	rra();
	}
	// pa();
}

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
		push_a(stack_a, stack_b, n_elms);
		*stack_b = (*stack_b)->next;
	}
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