/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 17:57:49 by eesaki            #+#    #+#             */
/*   Updated: 2020/02/18 15:59:11 by eesaki           ###   ########.fr       */
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
		i++;
	}
	return (TRUE);
}

void		vali_dup(t_stack *stack, int n)
{
	t_elm	*elm;
	int		i;

	elm = stack->head;
	i = 0;
	while (i < stack->size)
	{
		if (n == elm->n)
			ERROR("duplicate in argument");
		elm = elm->next;
		i++;
	}
}