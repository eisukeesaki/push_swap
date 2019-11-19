/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 12:04:50 by eesaki            #+#    #+#             */
/*   Updated: 2019/11/18 19:47:36 by eesaki           ###   ########.fr       */
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
	t_stack	*a_2nd;

	if (count_nodes(*stack_a) < 2)
		return ;

	a_2nd = (*stack_a)->next;
	(*stack_a)->prev = a_2nd;
	(*stack_a)->next = a_2nd->next;
	a_2nd->prev = NULL;
	a_2nd->next = *stack_a;
	*stack_a = a_2nd;

	// print_stacks(*stack_a, *stack_b); // debug purpose
}

void	sb(t_stack **stack_a __attribute__((unused)), t_stack **stack_b)
{
	t_stack	*b_2nd;

	if (count_nodes(*stack_b) < 2)
		return ;

	b_2nd = (*stack_b)->next;
	(*stack_b)->prev = b_2nd;
	(*stack_b)->next = b_2nd->next;
	b_2nd->prev = NULL;
	b_2nd->next = *stack_b;
	*stack_b = b_2nd;

	// print_stacks(*stack_a, *stack_b); // debug purpose
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(stack_a, stack_b);
	sb(stack_a, stack_b);
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*b;
	t_stack	*tmp;

	b = *stack_b;
	if (*stack_b == NULL)
		return ;
	tmp = newdnode(b->n);
	link_dnode_head(*stack_a, tmp);
	*stack_a = tmp; // do this in link_dnode_head()?
	*stack_b = b->next;
	free(b);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*a;
	t_stack *tmp;

	a = *stack_a;
	if (*stack_a == NULL)
		return ;
	if (*stack_b == NULL)
		*stack_b = newdnode(a->n);
	else
	{
		tmp = newdnode(a->n);
		link_dnode_head(*stack_b, tmp);
		*stack_b = tmp; // do this in link_dnode_head()?
	}
	*stack_a = a->next;
	free(a);
}

// shift up all elements of stack a by 1. The first element becomes the last one.
void	ra(t_stack **stack_a, t_stack **stack_b __attribute__((unused)))
{
	t_stack	*new_head;
	t_stack	*tmp;

	new_head = (*stack_a)->next;
	tmp = *stack_a;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = *stack_a;
	(*stack_a)->prev = tmp;
	(*stack_a)->next = NULL;
	*stack_a = new_head;
}

// shift up all elements of stack b by 1. The first element becomes the last one.
void	rb(t_stack **stack_a __attribute__((unused)), t_stack **stack_b)
{
	t_stack	*new_head;
	t_stack	*tmp;

	new_head = (*stack_b)->next;
	tmp = *stack_b;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = *stack_b;
	(*stack_b)->prev = tmp;
	(*stack_b)->next = NULL;
	*stack_b = new_head;
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a, stack_b);
	rb(stack_a, stack_b);
}

// void	rra(t_stack **stack_a, t_stack **stack_b)
// {
// 	printf("rra called\n");
// 	setbuf(stdout, NULL);
// /**
//  * re-link so that tail becomes head
// **/
// }

// void	rrb(t_stack **stack_a, t_stack **stack_b)
// {
// 	printf("rrb called\n");
// 	setbuf(stdout, NULL);
// /**
//  * re-link so that tail becomes head
// **/
// }

// void	rrr(t_stack **stack_a, t_stack **stack_b)
// {
// 	printf("rrr called\n");
// 	setbuf(stdout, NULL);
// /**
//  * call rra()
//  * call rrb()
// **/
// }
