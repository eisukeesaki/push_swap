/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <eesaki@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 03:33:43 by eesaki            #+#    #+#             */
/*   Updated: 2020/08/16 14:54:25 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_ps *ps, t_stack *stack)
{
	int	top;
	int	mid;
	int	btm;

	top = stack->head->n;
	mid = stack->head->next->n;
	btm = stack->head->prev->n;
	if (top < btm && btm < mid)
	{
		perform_op_ntimes(ps, SA, 1);
		perform_op_ntimes(ps, RA, 1);
	}
	else if (mid < top && top < btm)
		perform_op_ntimes(ps, SA, 1);
	else if (btm < top && top < mid)
		perform_op_ntimes(ps, RRA, 1);
	else if (mid < btm && btm < top)
		perform_op_ntimes(ps, RA, 1);
	else if (btm < mid && mid < top)
	{
		perform_op_ntimes(ps, SA, 1);
		perform_op_ntimes(ps, RRA, 1);
	}
}
