/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_remaining_unsorteds_in_a.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <eesaki@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 20:02:12 by eesaki            #+#    #+#             */
/*   Updated: 2020/08/18 21:09:45 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		bring_unsorted_to_top(t_ps *ps, int unsorted_ct)
{
	int		i;
	int		rra_ct;
	t_elm	*a_t;

	i = 0;
	rra_ct = 0;
	a_t = ps->a->tail;
	if (a_t->sorted == FALSE)
	{
		while (i < unsorted_ct)
		{
			if (a_t->sorted == FALSE)
				rra_ct++;
			a_t = a_t->prev;
			i++;
		}
		perform_op_ntimes(ps, RRA, rra_ct);
	}
}

void		mark_as_sorted(t_stack *stack)
{
	int		i;
	t_elm	*elm;

	i = 0;
	elm = stack->head;
	while (i < stack->size)
	{
		if (elm->sorted == FALSE)
			elm->sorted = TRUE;
		elm = elm->next;
		i++;
	}
}

void		sort_2_or_3(t_ps *ps)
{
	if (ps->a->head->next->next->sorted == TRUE)
	{
		perform_op_ntimes(ps, SA, 1);
		return ;
	}
	sort_3(ps, ps->a);
}

void		sort_remaining_unsorteds_in_a(t_stack *a, t_ps *ps)
{
	t_elm	*min;
	int		unsorted_ct;

	min = find_min(a);
	unsorted_ct = count_unsorted(a);
	if (is_sorted_circularly(a, min) == FALSE)
	{
		bring_unsorted_to_top(ps, unsorted_ct);
		if (unsorted_ct == 2)
			perform_op_ntimes(ps, SA, 1);
		else if (unsorted_ct == 3)
			sort_top_3(ps);
		else
			error("unexpected amount of unsorted elms were found "
				"during sort_remaining_unsorteds_in_a()\n");
	}
	else
	{
		if (a->size == 2 && a->head->n > a->head->next->n)
			perform_op_ntimes(ps, SA, 1);
		else
			rotate_til_at_top(ps, a, min);
	}
	mark_as_sorted(a);
}
