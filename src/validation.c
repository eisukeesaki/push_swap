/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <eesaki@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 17:57:49 by eesaki            #+#    #+#             */
/*   Updated: 2020/02/20 20:23:40 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool		is_sorted_circularly(t_elm *elm, int stack_size)
{
	int		i;

	i = 0;
	while (++i < stack_size)
	{
		if (elm->n > elm->next->n)
			return (FALSE);
		elm = elm->next;
	}
	return (TRUE);
}

void		vali_dup(t_stack *stack, int n)
{
	t_elm	*elm;
	int		i;

	elm = stack->head;
	i = 0;
	while (i++ < stack->size)
	{
		if (n == elm->n)
			ERROR("duplicate in argument");
		elm = elm->next;
	}
}