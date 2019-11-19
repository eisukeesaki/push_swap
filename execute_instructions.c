/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 18:06:44 by eesaki            #+#    #+#             */
/*   Updated: 2019/11/18 19:33:28 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stddef.h>
#include <stdio.h> // debug purpose
#define NTABELM 11

// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< debug purpose
void	print_ins_set(t_ins_set *ins_set)
{
	printf("<<< ins_set passed to search()\n");
	while (ins_set != NULL)
	{
		printf("%s\n", ins_set->ins);
		ins_set = ins_set->next;
	}
	printf(">>> ins_set passed to search()\n");
}
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> debug purpose

void	search(t_ins_set *ins_set, t_functab *functab, t_stack **stack_a, t_stack **stack_b)
{
	// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< debug purpose
	print_ins_set(ins_set);
	// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> debug purpose
	size_t	i;
	t_ins_set *ins;

	ins = ins_set;
	while (ins != NULL)
	{
		i = 0;
		// while (i < NTABELM)
		while (i < 6)
		{
			if (ft_strequ(ins->ins, functab[i].ins_str))
			{
				functab[i].ins_func(stack_a, stack_b);
				break;
			}
			i++;
		}
		ins = ins->next;
	}
}

void	exe_ins(t_ins_set *ins_set, t_stack **stack_a, t_stack **stack_b)
{
	// t_functab	functab[NTABELM] =
	t_functab	functab[] =
	{
		{"sa", sa},
		{"sb", sb},
		{"ss", ss},
		{"pa", pa},
		{"pb", pb},
		{"ra", ra},
		// {"rb", rb},
		// {"rr", rr},
		// {"rra", rra},
		// {"rrb", rrb},
		// {"rrr", rrr},
	};
	search(ins_set, functab, stack_a, stack_b);
}
