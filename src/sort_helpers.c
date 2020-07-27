/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 17:04:21 by eesaki            #+#    #+#             */
/*   Updated: 2020/07/28 04:16:25 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_top_seg(t_stack *b)
{
	int		seg;
	int		i;

	seg = 0;
	i = 0;
	while (i++ < b->size)
	{
		if (seg < b->head->seg)
			seg = b->head->seg;
		b->head = b->head->next;
	}
	return (seg);
}

// checked order

int		count_unsorted(t_stack *stack) // returns num of unsorted elms in stack_a
{
	int		count;
	int		i;
	t_elm	*head;

	count = 0;
	i = 0;
	head = stack->head;
	while (i++ < stack->size)
	{
		if (head->sorted == FALSE)
			count++;
		head = head->next;
	}
	return (count);
}

t_bool	is_sorted(t_stack *stack) // checks if unsorted segment exists in stack_a
{
	int		i;
	t_elm	*head;

	i = 0;
	head = stack->head;
	while (i++ < stack->size)
	{
		if (stack->head->sorted == FALSE)
			return (FALSE);
		head = head->next;
	}
	return (TRUE);
}

int			get_rotation_count(t_stack *stack, t_elm *dest, t_bool reverse)
{
	t_elm	*elm;
	int		count;

	elm = stack->head;
	count = 0;
	if (!reverse)
	{
		while (elm != dest)
		{
			count++;
			elm = elm->next;
		}
		return (count);
	}
	else
	{
		while (elm != dest)
		{
			count++;
			elm = elm->prev;
		}
		return (count);
	}
}

t_elm		*find_min(t_stack *stack)
{
	t_elm	*min;
	t_elm	*elm;
	int		i;

	min = stack->head;
	elm = stack->head->next;
	i = 0;
	while (i++ < stack->size)
	{
		if (min->n > elm->n)
			min = elm;
		elm = elm->next;
	}
	return (min);
}

// t_bool	is_sorted(t_stack *stack) // checks if stack is COMPLETELY sorted or not
// {
// 	int		i;

// 	i = 0;
// 	while (++i < stack->size)
// 	{
// 		if (stack->head->n > stack->head->next->n)
// 			return (FALSE);
// 		stack->head = stack->head->next;
// 	}
// 	return (TRUE);
// }

// t_bool	unsorted_elm_exist_a(t_stack *a)
// {
// 	int		i;

// 	i = 0;
// 	while (++i < a->size)
// 	{
// 		if (a->head->seg != 0)
// 			return (TRUE);
// 		a->head = a->head->next;
// 	}
// 	return (FALSE);
// }
