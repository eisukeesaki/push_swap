/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_or_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 20:07:14 by eesaki            #+#    #+#             */
/*   Updated: 2019/12/18 02:30:25 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h> // debug purpose

int		count_n_elms(t_stack *stack)
{
	int		n;

	n = 0;
	while (stack != NULL)
	{
		n++;
		stack = stack->next;
	}
	return (n);
}

int		get_idx_of_n(t_stack *stack, int n)
{
	int		idx;

	idx = 0;
	while (stack->n != n)
	{
		idx++;
		stack = stack->next;
	}
	return (idx);
}

int		find_min_pos(t_stack *stack_a)
{
	int		min;
	int		pos;
	t_stack	*a;

	a = stack_a;
	min = a->n;
	a = a->next;
	while (a != NULL)
	{
		if (a->n < min)
			min = a->n;
		a = a->next;
	}
	pos = 0;
	while (stack_a->n != min)
	{
		pos++;
		stack_a = stack_a->next;
	}
	return (pos);
}

int		find_max_pos(t_stack *stack_a)
{
	int		max;
	int		pos;
	t_stack	*a;

	a = stack_a;
	max = a->n;
	a = a->next;
	while (a != NULL)
	{
		if (max < a->n)
			max = a->n;
		a = a->next;
	}
	pos = 0;
	while (stack_a->n != max)
	{
		pos++;
		stack_a = stack_a->next;
	}
	return (pos);
}

int		find_max_n(t_stack *stack_a)
{
	int		max;

	max = stack_a->n;
	stack_a = stack_a->next;
	while (stack_a != NULL)
	{
		if (max < stack_a->n)
			max = stack_a->n;
		stack_a = stack_a->next;
	}
	return (max);
}

int		find_min_n(t_stack *stack_a)
{
	int		min;

	min = stack_a->n;
	stack_a = stack_a->next;
	while (stack_a != NULL)
	{
		if (stack_a->n < min)
			min = stack_a->n;
		stack_a = stack_a->next;
	}
	return (min);
}

void	rotate_a(t_stack **stack_a, t_stack **stack_b, int n_elms)
{
	// int		n_elms;
	int		min;
	int		min_pos;

	// n_elms = count_n_elms(*stack_a);
	min = find_min_n(*stack_a);
	min_pos = find_min_pos(*stack_a);
	if (min_pos < n_elms / 2)
	{
		while ((*stack_a)->n != min)
			ra(stack_a, stack_b);
	}
	else
	{
		while ((*stack_a)->n != min)
			rra(stack_a, stack_b);
	}
}

int		count_rotation(t_stack *stack_a, int pos, int direction)
{
	int		n_elms;
	int		count;

	n_elms = count_n_elms(stack_a);
	count = 0;
	if (direction == 1) /* 1 == ra */
	{
		while (0 < pos--)
			count++;
	}
	else if (direction == 0) /* 0 == rra */
	{
		while (pos++ < n_elms)
			count++;
	}
	return (count);
}

void	ra_or_rra(t_stack **stack_a, t_stack **stack_b, int pos)
{
	int		n_elms = count_n_elms(*stack_a);
	int		n_rotation;

	if (pos < (n_elms / 2))
	{
		n_rotation = count_rotation(*stack_a, pos, 1);
		while (0 < n_rotation--)
			ra(stack_a, stack_b);
	}
	else
	{
		n_rotation = count_rotation(*stack_a, pos, 0);
		while (0 < n_rotation--)
			rra(stack_a, stack_b);
	}
}

int		find_pos(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*a;
	int		pos;
	int		min;
	int		max;

	a = *stack_a;
	pos = 0;
	min = find_min_n(*stack_a);
	max = find_max_n(*stack_a);
	if ((*stack_b)->n < min)
		return (get_idx_of_n(*stack_a, min));
	else if (max < (*stack_b)->n)
		return (get_idx_of_n(*stack_a, min));
	while (a->next != NULL)
	{
		pos++;
		if (a->n < (*stack_b)->n && a->next->n > (*stack_b)->n)// TODO:	[] FIX THIS FIRST to pass "3 4 0 1 2"
		{
			return (pos);
		}
		a = a->next;
	}
	printf("could not find pos in find_pos()\n"); // debug purpose
	exit(1);
}

void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	int		pos;

	pos = find_pos(stack_a, stack_b);
	if (pos != 0)
		ra_or_rra(stack_a, stack_b, pos);
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