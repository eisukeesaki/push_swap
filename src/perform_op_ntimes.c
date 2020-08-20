/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_op_ntimes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <eesaki@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 16:55:27 by eesaki            #+#    #+#             */
/*   Updated: 2020/08/21 01:23:10 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	dispatch_op(t_ps *ps, int op)
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
