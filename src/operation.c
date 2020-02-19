/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 19:01:56 by eesaki            #+#    #+#             */
/*   Updated: 2020/02/17 19:55:42 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		rotate_up(t_stack *stack)
{
	if (stack->size < 2)
		return ;
	stack->head = stack->head->next;
}

void		rotate_down(t_stack *stack)
{
	if (stack->size < 2)
		return ;
	stack->head = stack->head->prev;
}

void		push()
{
	printf("called push()\n"); setbuf(stdout, NULL);
}

void		swap()
{
	printf("called swap()\n"); setbuf(stdout, NULL);
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
	if (op == PA || op == PB)
		push();
	if (op == PB)
		push();
	if (op == SA || op == SS)
		swap();
	if (op == SB || op == SS)
		swap();
}

void		perform_op_ntimes(t_ps *ps, int op, int n)
{
	while (n > 0)
	{
		dispatch_op(ps, op);
		append_node(ps->ops, create_node(op));
		n--;
	}
}
