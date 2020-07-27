/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 19:01:56 by eesaki            #+#    #+#             */
/*   Updated: 2020/07/28 04:45:44 by eesaki           ###   ########.fr       */
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
	if (DBG) printf("executing push()...\n"); setbuf(stdout, NULL);
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

void		dispatch_op(t_ps *ps, int op)
{
	if (op == RA || op == RR)
		rotate_up(ps->a);
	if (op == RB || op == RR)
		rotate_up(ps->b);
	if (op == RRA || op == RRR)
		rotate_down(ps->a);
	if (op == RRB || op == RRR)
		rotate_down(ps->b);
	if (op == PA)
		push(ps->b, ps->a);
	if (op == PB)
		push(ps->a, ps->b);
	if (op == SA || op == SS)
		swap(ps->a);
	if (op == SB || op == SS)
		swap(ps->b);
}

void		perform_op_ntimes(t_ps *ps, int op, int n)
{
	while (n-- > 0)
	{
		dispatch_op(ps, op);
		append_node(ps->ops, create_node(op));
	}
}
