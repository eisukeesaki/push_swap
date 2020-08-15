/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_only_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 03:58:59 by eesaki            #+#    #+#             */
/*   Updated: 2020/08/15 19:36:13 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool		rotate_only_sort(t_ps *ps)
{
	t_elm	*min;

	min = find_min(ps->a);
	if (ps->b->size > 0 || !is_sorted_circularly(ps->a, min))
		return (FALSE);
	rotate_til_at_top(ps, ps->a, min);
	return (TRUE);
}
