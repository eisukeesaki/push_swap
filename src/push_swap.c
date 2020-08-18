/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <eesaki@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 16:28:48 by eesaki            #+#    #+#             */
/*   Updated: 2020/08/18 21:38:42 by eesaki           ###   ########.fr       */
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

int			main(int ac, char **av)
{
	t_ps	*ps;

	if (ac < 2)
		return (0);
	ps = get_ps(av + 1);
	if (rotate_only_sort(ps) == FALSE)
	{
		if (ps->a->size == 3)
			sort_3(ps, ps->a);
		else if (ps->a->size == 5)
			sort_5(ps);
		else
			sort(ps);
	}
	print_op_list(ps->ops);
	free_ps(ps);
	return (0);
}
