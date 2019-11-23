/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 12:04:50 by eesaki            #+#    #+#             */
/*   Updated: 2019/11/23 00:09:29 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h> // debug purpose

size_t	count_nodes(t_stack *stack)
{
	size_t	nnodes;

	nnodes = 0;
	while (stack != NULL)
	{
		nnodes++;
		stack = stack->next;
	}
	return (nnodes);
}

void	sa(t_stack **stack_a, t_stack **stack_b __attribute__((unused)))
{
	size_t	nnodes;
	t_stack	*a_2nd;

	if ((nnodes = count_nodes(*stack_a)) < 2)
		return ;
	a_2nd = (*stack_a)->next;
	if (nnodes > 2)
		a_2nd->next->prev = *stack_a;
	(*stack_a)->prev = a_2nd;
	(*stack_a)->next = a_2nd->next;
	a_2nd->prev = NULL;
	a_2nd->next = *stack_a;
	*stack_a = a_2nd;
}

void	sb(t_stack **stack_a __attribute__((unused)), t_stack **stack_b)
{
	size_t	nnodes;
	t_stack	*b_2nd;

	if ((nnodes = count_nodes(*stack_b)) < 2)
		return ;
	b_2nd = (*stack_b)->next;
	if (nnodes > 2)
		b_2nd->next->prev = *stack_b;
	(*stack_b)->prev = b_2nd;
	(*stack_b)->next = b_2nd->next;
	b_2nd->prev = NULL;
	b_2nd->next = *stack_b;
	*stack_b = b_2nd;
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(stack_a, stack_b);
	sb(stack_a, stack_b);
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*b;
	t_stack *tmp;

	if (*stack_b == NULL)
		return ;
	b = *stack_b;
	if (*stack_a == NULL)
		*stack_a = newdnode((*stack_b)->n);
	else
	{
		tmp = newdnode((*stack_b)->n);
		link_dnode_head(stack_a, tmp);
	}
	*stack_b = (*stack_b)->next;
	if (*stack_b != NULL)
		(*stack_b)->prev = NULL;
	free(b);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*a;
	t_stack *tmp;

	if (*stack_a == NULL)
		return ;
	a = *stack_a;
	if (*stack_b == NULL)
		*stack_b = newdnode((*stack_a)->n);
	else
	{
		tmp = newdnode((*stack_a)->n);
		link_dnode_head(stack_b, tmp);
	}
	*stack_a = (*stack_a)->next;
	if (*stack_a != NULL)
		(*stack_a)->prev = NULL;
	free(a);
}

// shift up all elements of stack a by 1. The first element becomes the last one.
/**
 * change next of Nth node to NULL
 * change next of last node to previous head node
 * change prev of head node to last node
 * change head to (N+1)th node
 * change prev of new head node to NULL
**/
void	ra(t_stack **stack_a, t_stack **stack_b __attribute__((unused)))
{
	int		i;
	int		by;
	t_stack	*tmp;
	t_stack	*byth;

	i = 1;
	by = 1; // how many nodes to shfit "by"
	tmp = *stack_a;
	while (i < by)
	{
		tmp = tmp->next;
		i++;
	}
	byth = tmp;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = *stack_a;
	(*stack_a)->prev = tmp;
	*stack_a = byth->next;
	(*stack_a)->prev = NULL;
	byth->next = NULL;
}

// shift up all elements of stack b by 1. The first element becomes the last one.
void	rb(t_stack **stack_a __attribute__((unused)), t_stack **stack_b)
{
	int		i;
	int		by;
	t_stack	*tmp;
	t_stack	*byth;

	i = 1;
	by = 1; // how many nodes to shfit "by"
	tmp = *stack_b;
	while (i < by)
	{
		tmp = tmp->next;
		i++;
	}
	byth = tmp;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = *stack_b;
	(*stack_b)->prev = tmp;
	*stack_b = byth->next;
	(*stack_b)->prev = NULL;
	byth->next = NULL;
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a, stack_b);
	rb(stack_a, stack_b);
}

// shift down all elements of stack a by 1. The last element becomes the first one.
void	rra(t_stack **stack_a, t_stack **stack_b __attribute__((unused)))
{
	t_stack	*tmp;
	t_stack	*new_tail;

	if (count_nodes(*stack_a) < 2)
		return ;
	tmp = *stack_a;
	while (tmp->next != NULL)
		tmp = tmp->next;
	new_tail = tmp->prev;
	new_tail->next = NULL;
	(*stack_a)->prev = tmp;
	tmp->next = *stack_a;
	*stack_a = tmp;
	(*stack_a)->prev = NULL;
}

// shift down all elements of stack b by 1. The last element becomes the first one.
void	rrb(t_stack **stack_a __attribute__((unused)), t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*new_tail;

	if (count_nodes(*stack_b) < 2)
		return ;
	tmp = *stack_b;
	while (tmp->next != NULL)
		tmp = tmp->next;
	new_tail = tmp->prev;
	new_tail->next = NULL;
	(*stack_b)->prev = tmp;
	tmp->next = *stack_b;
	*stack_b = tmp;
	(*stack_b)->prev = NULL;
}

// void	rrr(t_stack **stack_a, t_stack **stack_b)
// {
// 	printf("rrr called\n");
// 	setbuf(stdout, NULL);
// /**
//  * call rra()
//  * call rrb()
// **/
// }
