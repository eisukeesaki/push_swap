/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 12:04:50 by eesaki            #+#    #+#             */
/*   Updated: 2019/11/15 19:35:10 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> // test purpose

// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< testing
void	print_stack(t_stack *head);
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> testing

void	sa(t_stack *head __attribute((unused)))
// void	sa(t_stack *head)
{
	// print_stack(head);
	printf("sa called\n");
	setbuf(stdout, NULL);
}

void	sb(t_stack *head __attribute((unused)))
// void	sb(t_stack *head)
{
	printf("sb called\n");
	setbuf(stdout, NULL);
}

void	ss(t_stack *head __attribute((unused)))
{
	printf("ss called\n");
	setbuf(stdout, NULL);
}

void	pa(t_stack *head __attribute((unused)))
{
	printf("pa called\n");
	setbuf(stdout, NULL);
}

void	pb(t_stack *head __attribute((unused)))
{
	printf("pb called\n");
	setbuf(stdout, NULL);
}

void	ra(t_stack *head __attribute((unused)))
{
	printf("ra called\n");
	setbuf(stdout, NULL);
}

void	rb(t_stack *head __attribute((unused)))
{
	printf("rb called\n");
	setbuf(stdout, NULL);
}

void	rr(t_stack *head __attribute((unused)))
{
	printf("rr called\n");
	setbuf(stdout, NULL);
}

void	rra(t_stack *head __attribute((unused)))
{
	printf("rra called\n");
	setbuf(stdout, NULL);
}

void	rrb(t_stack *head __attribute((unused)))
{
	printf("rrb called\n");
	setbuf(stdout, NULL);
}

void	rrr(t_stack *head __attribute((unused)))
{
	printf("rrr called\n");
	setbuf(stdout, NULL);
}
