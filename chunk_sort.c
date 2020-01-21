/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 19:07:07 by eesaki            #+#    #+#             */
/*   Updated: 2020/01/20 15:12:35 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			find_min_n_b(t_stack *stack_b)
{
	int		min;

	min = stack_b->n;
	stack_b = stack_b->next;
	while (stack_b != NULL)
	{
		if (stack_b->n < min)
			min = stack_b->n;
		stack_b = stack_b->next;
	}
	return (min);
}

int			find_max_n_b(t_stack *stack_b)
{
	int		max;

	max = stack_b->n;
	stack_b = stack_b->next;
	while (stack_b != NULL)
	{
		if (stack_b->n > max)
			max = stack_b->n;
		stack_b = stack_b->next;
	}
	return (max);
}

int			find_min_pos(t_stack *stack_b, int min_n)
{
	int		pos;

	pos = 0;
	while (stack_b)
	{
		if (stack_b->n == min_n)
			return (pos);
		pos++;
		stack_b = stack_b->next;
	}
	return (pos);
}

int			find_min_pos_b(t_stack **stack_b)
{
	int		min_n;

	min_n = find_min_n_b(*stack_b);
	return (find_min_pos(*stack_b, min_n));
}

void	rb_or_rrb(t_stack **stack_b, int pos)
{
	int		n_elms = count_n_elms(*stack_b);
	int		n_rotation;

	if (pos < (n_elms / 2))
	{
		n_rotation = count_rotation(*stack_b, pos, 1);
		while (0 < n_rotation--)
			rb(NULL, stack_b);
	}
	else
	{
		n_rotation = count_rotation(*stack_b, pos, 0);
		while (0 < n_rotation--)
			rrb(NULL, stack_b);
	}
}

void		move_min_top_b(t_stack **stack_b)
{
	int		pos;

	pos = find_min_pos_b(stack_b);
	rb_or_rrb(stack_b, pos);
}

int			find_pos_pb(t_stack **stack_a, t_stack **stack_b)
{

}

// void		prep_for_pb(t_stack **stack_a, t_stack **stack_b)
// {
// 	int		pos;

// 	if ((*stack_a)->n > find_max_n_b(stack_b))
// 	{
// 		move_min_top_b(stack_b);
// 	}
// 	else
// 	{
// 		pos = find_pos_pb();
// 		rb_or_rrb(stack_b, pos);
// 	}
}