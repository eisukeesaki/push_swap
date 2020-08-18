/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <eesaki@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 17:57:49 by eesaki            #+#    #+#             */
/*   Updated: 2020/08/18 21:05:11 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool		is_sorted_circularly(t_stack *stack, t_elm *min_elm)
{
	int		i;

	i = 0;
	while (++i < stack->size)
	{
		if (min_elm->n > min_elm->next->n)
			return (FALSE);
		min_elm = min_elm->next;
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
			error("duplicate in argument\n");
		elm = elm->next;
		i++;
	}
}
