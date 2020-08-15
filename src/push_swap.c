/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 16:28:48 by eesaki            #+#    #+#             */
/*   Updated: 2020/08/15 20:00:54 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			main(int ac, char **av)
{
	t_ps	*ps;
	
	if (ac < 2)
		return (0);
	ps = get_ps(av + 1);
	if (!rotate_only_sort(ps))
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
	// system("leaks push_swap");  // debug purpose
	return (0);
}
