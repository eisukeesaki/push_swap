/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 18:04:49 by eesaki            #+#    #+#             */
/*   Updated: 2020/02/18 17:31:24 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_elm		*find_min(t_stack *stack)
{
	t_elm	*min;
	t_elm	*elm;
	int		i;

	elm = stack->head;
	min = NULL;
	i = 0;
	while (i++ < stack->size)
	{
		if (!min || elm->n < min->n)
			min = elm;
		elm = elm->next;
	}
	return (min);
}
