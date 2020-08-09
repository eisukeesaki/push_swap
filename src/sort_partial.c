/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_partial.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 20:02:12 by eesaki            #+#    #+#             */
/*   Updated: 2020/08/09 18:03:54 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mark_as_sorted(t_stack *stack)
{
	int		i;
	t_elm	*head;

	i = 0;
	head = stack->head;
	while (i++ < stack->size)
	{
		if (head->sorted == FALSE)
			head->sorted = TRUE;
		head = head->next;
	}
}

void	sort_2_or_3(t_ps *ps)
{
	if (ps->a->head->next->next->sorted == TRUE)
	{
		perform_op_ntimes(ps, SA, 1);
		return ;
	}
	sort_3(ps, ps->a);
}

void	sort_partial(t_stack *a, t_ps *ps)
{
	t_elm	*min;
	int		i;
	t_elm	*elm;

	min = find_min(a);
	if (is_sorted_circularly(a, min) == FALSE)
		sort_top_3(ps);
		// sort_3(ps, a);
	else
	{
		if (a->size == 2)
			perform_op_ntimes(ps, SA, 1);
		else
		{
			rotate_til_at_top(ps, a, min);
			i = 0;
			elm = a->head;
		}
	}
	mark_as_sorted(a);
}

// void	handle_msl(t_ps *ps)
// {
// 	perform_op_ntimes(ps, SA, 1);
// }

// void	handle_mls(t_ps *ps)
// {
// 	perform_op_ntimes(ps, RRA, 1);
// }

// void	handle_lsm(t_ps *ps)
// {
// 	perform_op_ntimes(ps, RA, 1);
// }

// void	handle_lms(t_ps *ps)
// {
// 	perform_op_ntimes(ps, SA, 1);
// 	perform_op_ntimes(ps, RRA, 1);
// }

// void	handle_slm(t_ps *ps)
// {
// 	perform_op_ntimes(ps, SA, 1);
// 	perform_op_ntimes(ps, RA, 1);
// }

// void	func_to_sort_stack_of_3(t_ps *ps)
// {
// 	// int		top;
// 	// int		med;
// 	// int		btm;

// 	// top = ps->a->head->n;
// 	// med = ps->a->head->next->n;
// 	// btm = ps->a->head->next->next->n;
// 	// if (top < med && med > btm && top < btm)
// 	// 	// handle_slm(ps);
// 	// {
// 	// 	perform_op_ntimes(ps, SA, 1);
// 	// 	perform_op_ntimes(ps, RA, 1);
// 	// }
// 	// else if (top > med && med < btm && top < btm)
// 	// 	perform_op_ntimes(ps, SA, 1);
// 	// 	// handle_msl(ps);
// 	// else if (top < med && med > btm && top > btm)
// 	// 	perform_op_ntimes(ps, RRA, 1);
// 	// 	// handle_mls(ps);
// 	// else if (top > med && med < btm && top > btm)
// 	// 	perform_op_ntimes(ps, RA, 1);
// 	// 	// handle_lsm(ps);
// 	// else if (top > med && med > btm && top > btm)
// 	// {
// 	// 	perform_op_ntimes(ps, SA, 1);
// 	// 	perform_op_ntimes(ps, RRA, 1);
// 	// }
// 	// 	// handle_lms(ps);
// 	// else
// 	// 	printf("something went wrong in sort_2_or_3()\n");  // debug purpose
// }