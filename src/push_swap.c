/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <eesaki@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 16:28:48 by eesaki            #+#    #+#             */
/*   Updated: 2020/02/21 20:05:25 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int ac, char **av)
{
	t_ps		*ps;
	
	if (ac < 2)
		return (0);
	ps = get_ps(av + 1);

	/* if stack_a is sorted circularly, rotate until min is at the top. */
	if (!rotate_only_sort(ps))
	{ /* if FALSE, sort it */
		printf("cannot be sorted just by rotating.\n"); setbuf(stdout, NULL);
		if (ps->a->size == 3)
			sort_3(ps, ps->a);
		else
			median_3_sort();
	}
			print_stacks(ps, ""); // debug purpose
		print_op_list(ps->ops);
	return (0);
}
