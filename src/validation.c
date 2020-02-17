/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 17:57:49 by eesaki            #+#    #+#             */
/*   Updated: 2020/02/16 19:57:48 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		elm = elm->nxt;
		i++;
	}
}