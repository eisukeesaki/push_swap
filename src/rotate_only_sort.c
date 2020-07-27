/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_only_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 03:58:59 by eesaki            #+#    #+#             */
/*   Updated: 2020/07/28 03:59:08 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool		rotate_only_sort(t_ps *ps)
{
	t_elm	*min;

	min = find_min(ps->a);
	if (ps->b->size > 0 || !is_sorted_circularly(ps->a, min)) /* if there's even one elm in sb, sa is not sorted */
		return (FALSE);
	if (DBG) printf("can be sorted just by rotating\n");
	rotate_til_at_top(ps, ps->a, min);
	if (DBG) print_stacks(ps, " sorted just by rotating"); // debug purpose
	return (TRUE);
}
