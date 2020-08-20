/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_top_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <eesaki@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 21:56:46 by eesaki            #+#    #+#             */
/*   Updated: 2020/08/21 01:19:58 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	update_top_mid_btm(t_stack *a, int *top, int *mid, int *btm)
{
	*top = a->head->n;
	*mid = a->head->next->n;
	*btm = a->head->next->next->n;
}

void		sort_top_3(t_ps *ps)
{
	int	top;
	int	mid;
	int	btm;

	top = 0;
	mid = 0;
	btm = 0;
	update_top_mid_btm(ps->a, &top, &mid, &btm);
	while (1)
	{
		if ((mid < top && top < btm) || (mid < btm && btm < top)
			|| (btm < mid && mid < top))
			perform_op_ntimes(ps, SA, 1);
		update_top_mid_btm(ps->a, &top, &mid, &btm);
		if (top < mid && mid < btm)
			break ;
		perform_op_ntimes(ps, RA, 1);
		perform_op_ntimes(ps, SA, 1);
		perform_op_ntimes(ps, RRA, 1);
		update_top_mid_btm(ps->a, &top, &mid, &btm);
	}
}
