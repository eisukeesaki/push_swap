/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <eesaki@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 16:49:13 by eesaki            #+#    #+#             */
/*   Updated: 2020/08/18 16:50:36 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		free_output_and_ops(char *output, char **ops)
{
	int		i;

	free(output);
	i = 0;
	while (ops[i])
	{
		free(ops[i]);
		i++;
	}
	free(ops);
}

void		free_elms(t_stack *stack)
{
	t_elm	*tmp;

	if (stack->head == NULL || stack->tail == NULL)
		return ;
	while (0 < stack->size)
	{
		tmp = stack->head;
		if (1 < stack->size)
			stack->head = stack->head->next;
		unlink_node(stack, tmp);
		free(tmp);
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
		error("stack_b is not NULL after sorting is complete\n");
	else if (stack != ps->b)
	{
		while (0 < stack->size)
		{
			tmp = stack->head;
			if (1 < stack->size)
				stack->head = stack->head->next;
			unlink_node(stack, tmp);
			free(tmp);
		}
	}
	free(stack);
}
