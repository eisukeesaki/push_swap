/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <eesaki@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 19:01:56 by eesaki            #+#    #+#             */
/*   Updated: 2020/08/18 16:57:03 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		rotate_up(t_stack *stack)
{
	if (stack->size < 2)
		return ;
	stack->tail = stack->head;
	stack->head = stack->tail->next;
}

void		rotate_down(t_stack *stack)
{
	if (stack->size < 2)
		return ;
	stack->head = stack->tail;
	stack->tail = stack->head->prev;
}

void		push(t_stack *from, t_stack *to)
{
	t_elm		*to_push;

	if (from->size < 1)
		return ;
	to_push = from->head;
	unlink_node(from, from->head);
	append_node(to, to_push);
	rotate_down(to);
}

void		swap(t_stack *stack)
{
	t_elm		*bottom;

	if (stack->size < 2)
		return ;
	bottom = stack->head->next;
	unlink_node(stack, bottom);
	append_node(stack, bottom);
	stack->tail = bottom->prev;
	stack->head = bottom;
}
