/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 16:28:48 by eesaki            #+#    #+#             */
/*   Updated: 2020/02/18 15:47:27 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int ac, char **av)
{
	t_ps		*ps;
	
	if (ac < 2)
		return (0);
	ps = get_ps(av + 1);

	// is stack_a already sorted circularly?
	if (!rotate_only_sort(ps)) // if true, rotate stack_a until min is at the top
	{
		// if false, use sort_3() or median_3 algo
		printf("cannot be sorted just by rotating\n");
	}

	return (0);
}
