/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <eesaki@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 17:04:21 by eesaki            #+#    #+#             */
/*   Updated: 2020/08/21 01:26:53 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				get_top_seg(t_stack *b)
{
	int		seg;
	int		i;

	seg = 0;
	i = 0;
	while (i < b->size)
	{
		if (seg < b->head->seg)
			seg = b->head->seg;
		b->head = b->head->next;
		i++;
	}
	return (seg);
}

int				count_unsorted(t_stack *stack)
{
	int		count;
	int		i;
	t_elm	*elm;

	count = 0;
	i = 0;
	elm = stack->head;
	while (i < stack->size)
	{
		if (elm->sorted == FALSE)
			count++;
		elm = elm->next;
		i++;
	}
	return (count);
}

int				get_rotation_count(t_stack *stack, t_elm *dest, t_bool reverse)
{
	int		count;
	t_elm	*elm;

	elm = stack->head;
	count = 0;
	if (reverse == FALSE)
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

t_elm			*find_min(t_stack *stack)
{
	t_elm	*min;
	t_elm	*elm;
	int		i;

	min = stack->head;
	elm = stack->head->next;
	i = 0;
	while (i < stack->size)
	{
		if (min->n > elm->n)
			min = elm;
		elm = elm->next;
		i++;
	}
	return (min);
}
