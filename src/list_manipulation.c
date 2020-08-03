/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_manipulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 18:12:27 by eesaki            #+#    #+#             */
/*   Updated: 2020/08/03 08:38:43 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		free_elms(t_stack *stack)
{
	t_elm	*tmp;

	if (stack->head == NULL || stack->tail == NULL)
		return ;
	while (1)
	{
		tmp = stack->head;
		stack->head = stack->head->next;
		free(tmp);
		stack->size--;
		if (stack->size <= 0)
		{
			stack->head = NULL;
			stack->tail = NULL;
			break ;
		}
	}
}

void		free_ps(t_ps *ps)
{
	free_stack(ps, ps->a);
	free_stack(ps, ps->b);
	free_stack(ps, ps->ops);
	free(ps);
}

void		free_stack(t_ps *ps, t_stack *stack)
{
	t_elm	*tmp;
	if (stack == ps->b && (stack->head != NULL || stack->tail != NULL))
		error("stack_b is not NULL at the end of program");
	else if (stack != ps->b)
	{
		while (1)
		{
			tmp = stack->head;
			stack->head = stack->head->next;
			free(tmp);
			stack->size--;
			if (stack->size <= 0)
			{
				stack->head = NULL;
				stack->tail = NULL;
				break ;
			}
		}
	}
	free(stack);
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

t_elm		*create_node(int n)
{
	t_elm	*elm;

	// if (DBG) printf("sizeof(t_elm):%lu\n", sizeof(t_elm));
	if (!(elm = ft_memalloc(sizeof(t_elm))))
		ERROR("failed to allcoate elm");
	elm->n = n;
	elm->seg = 0;
	elm->sorted = FALSE;
	elm->prev = elm;
	elm->next = elm;
	return (elm);
}
