/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 12:04:50 by eesaki            #+#    #+#             */
/*   Updated: 2019/11/16 00:33:47 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> // test purpose

// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< testing
void	print_stack(t_stack *head);
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> testing

// void	sa(t_stack *head __attribute((unused)))
void	sa(t_stack *stack_a, t_stack *stack_b)
{
	printf("sa called\n");
	setbuf(stdout, NULL);

/**
 * check if a has 2 or more nodes
 	* do nothing if only 1 node
 * re-link the first two nodes to reverse order
**/
}

// void	sb(t_stack *head __attribute((unused)))
void	sb(t_stack *stack_a, t_stack *stack_b)
{
	printf("sb called\n");
	setbuf(stdout, NULL);
/**
 * check if b has 2 or more nodes
 	* do nothing if only 1 node
 * re-link the first two nodes to reverse order
**/
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	printf("ss called\n");
	setbuf(stdout, NULL);
/**
 * call sa()
 * call sb()
**/
}

// this function grows stack a
void	pa(t_stack **stack_a, t_stack **stack_b)
{
	printf("pa called\n");
	setbuf(stdout, NULL);
/**
 * if (nnodes == NULL) do nothing
 * insert b-0 before a-0
 * head_b = b-1
 * free old b-0
**/
}

// this function grows stack b
void	pb(t_stack **stack_a, t_stack **stack_b)
{
	printf("pb called\n");
	setbuf(stdout, NULL);

	// t_stack	**a;
	// t_stack	**b;

	// a = stack_a;
	// b = stack_b;
	// if (a == NULL)
	if (stack_a == NULL)
		return ;
	*stack_a.
/**
 * if (nnodes == NULL) do nothing
 * if (head_b == NULL) newnode(a-0)
 * else linkdnode_head(head_b, a-0)
 * head_a = a-1
 * free old a-0
**/
}

void	ra(t_stack *stack_a, t_stack *stack_b)
{
	printf("ra called\n");
	setbuf(stdout, NULL);
/**
 * re-link so that head becomes tail
**/
}

void	rb(t_stack *stack_a, t_stack *stack_b)
{
	printf("rb called\n");
	setbuf(stdout, NULL);
/**
 * re-link so that head becomes tail
**/
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	printf("rr called\n");
	setbuf(stdout, NULL);
/**
 * call ra()
 * call rb()
**/
}

void	rra(t_stack *stack_a, t_stack *stack_b)
{
	printf("rra called\n");
	setbuf(stdout, NULL);
/**
 * re-link so that tail becomes head
**/
}

void	rrb(t_stack *stack_a, t_stack *stack_b)
{
	printf("rrb called\n");
	setbuf(stdout, NULL);
/**
 * re-link so that tail becomes head
**/
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	printf("rrr called\n");
	setbuf(stdout, NULL);
/**
 * call rra()
 * call rrb()
**/
}
