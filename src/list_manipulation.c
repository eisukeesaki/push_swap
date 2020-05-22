/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_manipulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 18:12:27 by eesaki            #+#    #+#             */
/*   Updated: 2020/05/23 03:36:39 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_elm		*create_node(int n)
{
	t_elm	*elm;

	if (!(elm = ft_memalloc(sizeof(t_elm))))
		ERROR("failed to allcoate elm");
	elm->n = n;
	elm->segment = 0;
	elm->prev = elm;
	elm->next = elm;
	return (elm);
}

void		append_node(t_stack *stack, t_elm *node)
{
	if (!stack->head)
	{
		stack->head = node;
		stack->tail = node;
	}
	else
	{
		node->prev = stack->tail;
		node->next = stack->head;
		stack->tail->next = node;
		stack->head->prev = node;
		stack->tail = node;
	}
	stack->size++;
}

/* fucking norm... */
void		ft_unlink(t_stack *stack, t_elm *node)
{
	if (stack->size == 1)
	{
		stack->head = NULL;
		stack->tail = NULL;
	}
	else
	{
		if (node == stack->head)
		{
			stack->head = stack->head->next;
			stack->tail->next = stack->head;
			stack->head->prev = stack->tail;
		}
		else if (node == stack->tail)
		{
			stack->tail = stack->tail->prev;
			stack->head->prev = stack->tail;
			stack->tail->next = stack->head;
		}
		else
		{
			node->prev->next = node->next;
			node->next->prev = node->prev;
		}
	}
}

void		unlink_node(t_stack *stack, t_elm *node)
{
	if (stack->size < 1)
		return ;
	ft_unlink(stack, node);
	stack->size--;
	node->next = node;
	node->prev = node;
}
