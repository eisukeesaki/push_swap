/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_manipulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 18:12:27 by eesaki            #+#    #+#             */
/*   Updated: 2020/02/16 19:25:34 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_elm		*create_node(int n)
{
	t_elm	*elm;

	if (!(elm = ft_memalloc(sizeof(t_elm))))
		ERROR("failed to allcoate elm");
	elm->n = n;
	elm->prv = elm;
	elm->nxt = elm;
	return (elm);
}

void		append_node(t_stack *stack, t_elm *node)
{
	if (!stack->head)
		stack->head = node;
	else
	{
		node->prv = stack->head->prv;
		node->nxt = stack->head;
		stack->head->prv->nxt = node;
		stack->head->prv = node;
	}
	stack->size++;
}
