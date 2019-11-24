/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 20:48:25 by eesaki            #+#    #+#             */
/*   Updated: 2019/11/23 17:48:16 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stddef.h>
#include <stdint.h>
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< debug
#include <stdio.h>
#include <limits.h>
#include <fcntl.h>
#include <stdlib.h>
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> debug

t_stack	*build_a(int ac, char **av)
{
	size_t	i;
	size_t	k;
	char	**split;
	t_stack	*head; // head == top of stack
	t_stack	*tmp;

	i = 1;
	k = 0;
	head = NULL;
	while (i < (size_t)ac)
	{
		split = ft_strsplit(av[i], ' ');
		while (split[k])
		{
			tmp = newdnode(vali_int(my_atoi(vali_num(split[k]))));
			if (head == NULL)
				head = tmp;
			else
				link_dnode_tail(head, tmp);
			k++;
		}
		k = 0;
		i++;
	}
	return (head);
}

int		main(int ac, char **av)
{
	t_stack		*head_a;
	t_stack		*head_b;
	char		*ins;
	t_ins_set	*ins_set;

	head_a = NULL;
	head_b = NULL;
	if (ac > 1)
		head_a = build_a(ac, av);
	else
		exit(0);
	vali_dup(head_a);
	print_stacks(head_a, head_b); // test
	ins = NULL;
	ins_set = read_ins();
	exe_ins(ins_set, &head_a, &head_b);
	vali_sort(head_a);
	print_stacks(head_a, head_b);
	// print_stacks_bw(head_a, head_b);
	free(ins);
	return (0);
}

// tests:	<error management>
//	- throw error when non numeric args are given
//	-  Run checker with valid parameters, and write an action that doesn't exist
//		during the instruction phase. The program must display "Error"
//	- Run checker with valid parameters, and write an action with
//		one or several spaces before and/or after the action during the instruction phase.
//		The program must display "Error".
//	- throw error when instructions that doesn't sort the stack are given.
//		- Run checker with the following command
//			"$>./checker 0 9 1 8 2 7 3 6 4 5" then write the following valid action list
//			"[sa, pb, rrr]". Checker should display "KO".
//		- Run checker with a valid list as parameter of your choice then
//			write a valid instruction list that doesn't order the integers.
//			Checker should display "KO". 

// tests:	<sorting>
//	- Run checker with the following command "$>./checker 0 9 1 8 2" then
//		write the following valid action list "[pb, ra, pb, ra, sa, ra, pa, pa]".
//		The program should display "OK"

// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< backup code
	// while (ins_set != NULL)
	// {
	// 	ft_putendl(ins_set->ins);
	// 	ins_set = ins_set->next;
	// }
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> backup code