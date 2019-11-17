/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 12:04:50 by eesaki            #+#    #+#             */
/*   Updated: 2019/11/16 23:40:53 by eesaki           ###   ########.fr       */
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

	print_stacks(*stack_a, *stack_b); // debug purpose
}

// // void	sb(t_stack *head __attribute((unused)))
// void	sb(t_stack **stack_a, t_stack **stack_b)
// {
// 	printf("sb called\n");
// 	setbuf(stdout, NULL);
// /**
//  * check if b has 2 or more nodes
//  	* do nothing if only 1 node
//  * re-link the first two nodes to reverse order
// **/
// }

// void	ss(t_stack **stack_a, t_stack **stack_b)
// {
// 	printf("ss called\n");
// 	setbuf(stdout, NULL);
// /**
//  * call sa()
//  * call sb()
// **/
// }

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

// void	ra(t_stack **stack_a, t_stack **stack_b)
// {
// 	printf("ra called\n");
// 	setbuf(stdout, NULL);
// /**
//  * re-link so that head becomes tail
// **/
// }

// void	rb(t_stack **stack_a, t_stack **stack_b)
// {
// 	printf("rb called\n");
// 	setbuf(stdout, NULL);
// /**
//  * re-link so that head becomes tail
// **/
// }

// void	rr(t_stack **stack_a, t_stack **stack_b)
// {
// 	printf("rr called\n");
// 	setbuf(stdout, NULL);
// /**
//  * call ra()
//  * call rb()
// **/
// }

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
