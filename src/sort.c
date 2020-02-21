/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <eesaki@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 17:28:19 by eesaki            #+#    #+#             */
/*   Updated: 2020/02/20 20:23:37 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	median_3_sort(void)
{
	printf("median_3_sort() called\n");
}

void	sort_3(t_ps *ps, t_stack *stack)
{
	int		top;
	int		mid;
	int		btm;

	top = stack->head->n;
	mid = stack->head->next->n;
	btm = stack->head->prev->n;
	if (top < btm && btm < mid) // 1,3,2 => sa,ra
	{
		perform_op_ntimes(ps, SA, 1);
		perform_op_ntimes(ps, RA, 1);
	}
	else if (mid < top && top < btm) // 2,1,3 => sa
		perform_op_ntimes(ps, SA, 1);
	else if (btm < top && top < mid) // 2,3,1 => rra
		perform_op_ntimes(ps, RRA, 1);
	else if (mid < btm && btm < top) // 3,1,2 => ra
		perform_op_ntimes(ps, RA, 1);
	else if (btm < mid && mid < top) // 3,2,1 => sa,rra
	{
		perform_op_ntimes(ps, SA, 1);
		perform_op_ntimes(ps, RRA, 1);
	}
}

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
	int		r_count;
	int		rr_count;

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
