/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 17:28:19 by eesaki            #+#    #+#             */
/*   Updated: 2020/02/18 16:01:32 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			get_rotation_count(t_stack *stack, t_elm *dest, t_bool reverse)
{
	t_elm	*elm;
	int		count;

	elm = stack->head;
	count = 0;
	if (!reverse)
	{
		while (elm != dest)
		{
			count++;
			elm = elm->next;
		}
		return (count);
	}
	else
	{
		while (elm != dest)
		{
			count++;
			elm = elm->prev;
		}
		return (count);
	}
}

void		rotate_til_at_top(t_ps *ps, t_stack *stack, t_elm *dest)
{
	// t_elm	*elm;
	int		r_count;
	int		rr_count;

	// if (stack->head == dest)
	// 	return ;
	// r_count = 0;
	// elm = stack->head;
	// while (elm != dest)
	// {
	// 	r_count++;
	// 	elm = elm->next;
	// }
	// rr_count = 0;
	// elm = stack->head;
	// while (elm != dest)
	// {
	// 	rr_count++;
	// 	elm = elm->prev;
	// }
	r_count = get_rotation_count(stack, dest, FALSE);
	rr_count = get_rotation_count(stack, dest, TRUE);
	if (r_count < rr_count)
		perform_op_ntimes(ps, (stack == ps->a) ? RA : RB, r_count);
	else
		perform_op_ntimes(ps, (stack == ps->a) ? RRA : RRB, rr_count);
}

t_bool		rotate_only_sort(t_ps *ps)
{
	t_elm	*min;

	if (ps->b->size > 0
		|| !is_sorted_circularly((min = find_min(ps->a)), ps->a->size))
		return (FALSE);
	rotate_til_at_top(ps, ps->a, min);
			print_stacks(ps, " sorted just by rotating"); // debug purpose
	return (TRUE);
}
