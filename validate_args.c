/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 19:46:32 by eesaki            #+#    #+#             */
/*   Updated: 2019/11/13 19:25:33 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< error func(s)
// void	error(void)
// {
// 	write(1, "Error", 8);
// 	exit(1);
// }
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< debug purpos
void	dup_err(void)
{
	write(1, "dup err", 8);
	exit(1);
}

void	notint_err(void)
{
	write(1, "not int err", 12);
	exit(1);
}

void	sort_err(void)
{
	write(1, "sort err", 9);
	exit(1);
}
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> debug purpos
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> error func(s)

// void	vali_ins(char *ins)
// {
// 	char	*ins_list[] =// TODO: move to dedicated header
// 	{
// 		{"sa\n"},
// 		{"sb\n"},
// 		{"ss\n"},
// 		{"pa\n"},
// 		{"pb\n"},
// 		{"ra\n"},
// 		{"rb\n"},
// 		{"rr\n"},
// 		{"rra\n"},
// 		{"rrb\n"},
// 		{"rrr\n"},
// 	};

// 	// iterate over ins/ins_list and strequ() each ins
// 	while (ins)
// 	{

// 	}
// }

void	vali_sort(t_stack *head)
{
	t_stack	*start;
	t_stack	*comp;

	start = head;
	comp = head->next;
	while (comp != NULL)
	{
		// if (!(start->n > comp->n))
		if (!(start->n < comp->n))
			sort_err(); // replace with error()
		start = start->next;
		comp = comp->next;
	}
}

void		vali_dup(t_stack *head)
{
	t_stack	*start;
	t_stack	*comp;

	start = head;
	while (start != NULL)
	{
		comp = start->next;
		while (comp != NULL)
		{
			if (start->n == comp->n)
				dup_err(); // replace with error()
			comp = comp->next;
		}
		start = start->next;
	}
}

intmax_t	vali_int(intmax_t n)
{
	if (!(INT_MIN <= n && n <= INT_MAX))
		notint_err(); // replace with error()
	return (n);
}
