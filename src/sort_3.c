/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 03:33:43 by eesaki            #+#    #+#             */
/*   Updated: 2020/08/15 19:37:48 by eesaki           ###   ########.fr       */
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
	if (top < btm && btm < mid) // 1,3,2 => sa,ra
	{
		perform_op_ntimes(ps, SA, 1);
		perform_op_ntimes(ps, RA, 1);
	}
	else if (mid < top && top < btm) // 2,1,3 => sa
		perform_op_ntimes(ps, SA, 1);
	else if (btm < top && top < mid) // 2,3,1 => rra
		perform_op_ntimes(ps, RRA, 1);
	else if (mid < btm && btm < top) // 3,1,2 => ra
		perform_op_ntimes(ps, RA, 1);
	else if (btm < mid && mid < top) // 3,2,1 => sa,rra
	{
		perform_op_ntimes(ps, SA, 1);
		perform_op_ntimes(ps, RRA, 1);
	}
}
