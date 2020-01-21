/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subroutines_sort_small_0.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 16:28:55 by eesaki            #+#    #+#             */
/*   Updated: 2020/01/20 18:29:17 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int		find_min_pos(t_stack *stack)
{
	int		min;
	int		pos;
	t_stack	*a;

	a = stack;
	min = a->n;
	a = a->next;
	while (a != NULL)
	{
		if (a->n < min)
			min = a->n;
		a = a->next;
	}
	pos = 0;
	while (stack->n != min)
	{
		pos++;
		stack = stack->next;
	}
	return (pos);
}

int		find_max_pos(t_stack *stack)
{
	int		max;
	int		pos;
	t_stack	*a;

	a = stack;
	max = a->n;
	a = a->next;
	while (a != NULL)
	{
		if (max < a->n)
			max = a->n;
		a = a->next;
	}
	pos = 0;
	while (stack->n != max)
	{
		pos++;
		stack = stack->next;
	}
	return (pos);
}

int		find_max_n(t_stack *stack)
{
	int		max;

	max = stack->n;
	stack = stack->next;
	while (stack != NULL)
	{
		if (max < stack->n)
			max = stack->n;
		stack = stack->next;
	}
	return (max);
}

int		find_min_n(t_stack *stack)
{
	int		min;

	min = stack->n;
	stack = stack->next;
	while (stack != NULL)
	{
		if (stack->n < min)
			min = stack->n;
		stack = stack->next;
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

int		count_rotation(t_stack *stack, int pos, int direction)
{
	int		n_elms;
	int		count;

	n_elms = count_n_elms(stack);
	count = 0;
	if (direction == 1) /* 1 == r */
	{
		while (0 < pos--)
			count++;
	}
	else if (direction == 0) /* 0 == rr */
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
	if ((*stack_b)->n < min || max < (*stack_b)->n)
		return (get_idx_of_n(*stack_a, min));
	while (a->next != NULL)
	{
		pos++;
		if (a->n < (*stack_b)->n && a->next->n > (*stack_b)->n)
			return (pos);
		a = a->next;
	}
	return (pos + 1); // index of bottom
}

void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	int		pos;

	pos = find_pos(stack_a, stack_b);
	if (pos != 0)
		ra_or_rra(stack_a, stack_b, pos);
}
