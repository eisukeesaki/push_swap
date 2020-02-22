/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_manipulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <eesaki@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 18:12:27 by eesaki            #+#    #+#             */
/*   Updated: 2020/02/21 18:30:01 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_elm		*create_node(int n)
{
	t_elm	*elm;

	if (!(elm = ft_memalloc(sizeof(t_elm))))
		ERROR("failed to allcoate elm");
	elm->n = n;
	elm->prev = elm;
	elm->next = elm;
	return (elm);
}

void		append_node(t_stack *stack, t_elm *node)
{
	if (!stack->head)
		stack->head = node;
	else
	{
		node->prev = stack->head->prev;
		node->next = stack->head;
		stack->head->prev->next = node;
		stack->head->prev = node;
	}
	stack->size++;
}

void		unlink_node(t_stack *stack, t_elm *node) /* might not work when (stack->size > 3) */
{
	if (stack->head == node)
		stack->head = NULL;
	else
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}
	stack->size--;
	node->next = node;
	node->prev = node;
}
