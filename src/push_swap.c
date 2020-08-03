/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 16:28:48 by eesaki            #+#    #+#             */
/*   Updated: 2020/08/03 08:17:08 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int ac, char **av)
{
	t_ps		*ps;
	
	if (ac < 2)
		return (0);
	ps = get_ps(av + 1);
	if (DBG) print_stacks(ps, "init");

	if (!rotate_only_sort(ps))
	{ /* if FALSE, sort it */
		// if (DBG) printf("cannot be sorted just by rotating.\n"); setbuf(stdout, NULL); // debug purpose
		if (ps->a->size == 3)
			sort_3(ps, ps->a);
		else
			sort(ps);
	}
	if (DBG) print_stacks(ps, "after sort"); // debug purpose
	print_op_list(ps->ops);
	free_ps(ps);
	// system("leaks push_swap");
	return (0);
}
