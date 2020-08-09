/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 17:28:19 by eesaki            #+#    #+#             */
/*   Updated: 2020/08/09 18:18:11 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_ps *ps)
{
	int		median;
	int		i;
	t_stack	*pb_list;
	t_elm	*a_elm;
	__attribute__((unused)) int		outmost_loop_ct = 0; // debug purpose

	median = 0;
	if (!(pb_list = (t_stack *)ft_memalloc(sizeof(t_stack))))
		ERROR("failed to allocate pb_list");
	while (!is_sorted(ps->a) && ++outmost_loop_ct)
	{
		while (count_unsorted(ps->a) > 3)
		{
			a_elm = ps->a->head;
			median = get_median_in_a(ps->a) - 1;
			i = 0;
			while (ps->a->size > i++)
			{
					if (a_elm->n <= median && a_elm->sorted == FALSE)
						append_node(pb_list, create_node(a_elm->n));
				a_elm = a_elm->next;
			} //if (DBG) print_stack(pb_list, "pb_list:");
			pb_smaller(ps, pb_list);
		} //if (DBG) print_stacks(ps, "before sort_partial()");
		sort_partial(ps->a, ps); // sorts up to 3 elms in stack
		if (ps->b->size > 0)
			process_b(ps);
		else
			break ;
	}
	free(pb_list);
}

void	sort_top_3(t_ps *ps)
{
	int		top;
	int		mid;
	int		btm;

	// top = ps->a->head->n;
	// mid = ps->a->head->next->n;
	// btm = ps->a->head->next->next->n;
	top = 0;
	mid = 0;
	btm = 0;
	update_top_mid_btm(ps->a, &top, &mid, &btm);
	while (1)
	{
		if ((mid < top && top < btm) || (mid < btm && btm < top) || (btm < mid && mid < top))
			perform_op_ntimes(ps, SA, 1);
		// top = ps->a->head->n;
		// mid = ps->a->head->next->n;
		// btm = ps->a->head->next->next->n;
		update_top_mid_btm(ps->a, &top, &mid, &btm);
		if (top < mid && mid < btm)
			break;
		perform_op_ntimes(ps, RA, 1);
		perform_op_ntimes(ps, SA, 1);
		perform_op_ntimes(ps, RRA, 1);
		update_top_mid_btm(ps->a, &top, &mid, &btm);
		// top = ps->a->head->n;
		// mid = ps->a->head->next->n;
		// btm = ps->a->head->next->next->n;
	}
}