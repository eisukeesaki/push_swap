/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 16:41:46 by eesaki            #+#    #+#             */
/*   Updated: 2020/01/17 16:44:42 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_stack **stack_a, t_stack **stack_b)
{
	int		top;
	int		bottom;

	top = (*stack_a)->n;
	bottom = (*stack_a)->next->n;
	if (top > bottom)
		sa(stack_a, stack_b);
}

void	sort_4(t_stack **stack_a, t_stack **stack_b, int n_elms)
{	
	pb(stack_a, stack_b);
	sort_3(stack_a, stack_b);
	push_a(stack_a, stack_b);
	pa(stack_a, stack_b);
	rotate_a(stack_a, stack_b, n_elms);
}

void	sort_small(t_stack **stack_a, t_stack **stack_b, int n_elms)
{
	if (n_elms == 2)
		sort_2(stack_a, stack_b);
	else if (n_elms == 4)
		sort_4(stack_a, stack_b, n_elms);
	else // if (n_elms == 3 || n_elms == 5)
		sort_3_or_5(stack_a, stack_b, n_elms);
}