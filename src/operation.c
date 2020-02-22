/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <eesaki@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 19:01:56 by eesaki            #+#    #+#             */
/*   Updated: 2020/02/21 18:13:10 by eesaki           ###   ########.fr       */
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
	printf("called push()\n"); setbuf(stdout, NULL); // debug purpose
}

void		swap(t_stack *stack)
{
	t_elm		*bottom;
	// t_elm	*old_top;
	// t_elm	*old_med;
	// t_elm	*old_btm;

	if (stack->size < 2)
		return ;

	bottom = stack->head->next;

	unlink_node(stack, bottom);
	append_node(stack, bottom);
	stack->head = bottom;

	// old_top = stack->head;
	// old_med = stack->head->next;
	// old_btm = stack->head->prev;

	// stack->head = old_med;
	// stack->head->next = old_top;
	// stack->head->prev = old_btm;

	// stack->head->next->next = old_btm;
	// stack->head->next->prev = stack->head;

	// stack->head->prev->next = stack->head;
	// stack->head->prev->prev = old_med;
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
		swap(ps->a);
	if (op == SB || op == SS)
		swap(ps->b);
}

void		perform_op_ntimes(t_ps *ps, int op, int n)
{
				printf("performing op#%d %d time(s)\n", op, n); // debug purpose
	while (n-- > 0)
	{
		dispatch_op(ps, op);
		append_node(ps->ops, create_node(op));
	}
}
