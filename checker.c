/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 20:48:25 by eesaki            #+#    #+#             */
/*   Updated: 2019/11/23 00:02:17 by eesaki           ###   ########.fr       */
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
			tmp = newdnode(vali_int(my_atoi(split[k])));
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
	// size_t	i;
	// int		fd = 0; // test stdout
	// int		fd = 1; // test stdin

	head_a = NULL;
	head_b = NULL;
	if (ac > 1)
	{
		// head_a = build_a(ac - 1, av);
		head_a = build_a(ac, av);
	}
	else
		exit(0);
	vali_dup(head_a);

	print_stacks(head_a, head_b); // test

	ins = NULL;
	// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< reading ins from file instead of stdin to allow debugging
	// if ((fd = open("unused/instructions.txt", O_RDONLY)) == 1)
	// {
	// 	puts("file open error");
	// 	exit(1);
	// }
	// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> reading ins from file instead of stdin to allow debugging
	// while (get_next_line(0, &ins))
	ins_set = read_ins();
	// while (ins_set != NULL)
	// {
	// 	ft_putendl(ins_set->ins);
	// 	ins_set = ins_set->next;
	// }
	exe_ins(ins_set, &head_a, &head_b);

	// while (get_next_line(fd, &ins))
	// {
	// 	printf("read a instruction\n"); // test
	// 	ft_putendl(ins); //test
	// 	// TODO: store each ins in array of array, then validate them
	// 	read_ins(ins_set);
	// 	ft_strdel(&ins); // test
	// }
	// vali_sort(head_a);

	// i = 0;
	// while (ins[i])
	// {
	// 	ft_putendl(&ins[i]);
	// 	ft_strdel(&ins);
	// 	i++;
	// }
	// i = 0;
	// t_ins				ins_table[2] =
	// {
	// 	{"sa", sa},
	// 	{"sb", sb},
	// };
	// while (ins[i])
	// {
	// 	if (ft_strequ(&ins[i], ins_table[i].name))
	// 		ins_table[i].ins(head_a);
	// 	i++;
	// }
	print_stacks(head_a, head_b);
	print_stacks_bw(head_a, head_b);
	free(ins);
	return (0);
}

// TODO:	[] implement instruction funcs
// TODO:	[] alloc stack_b
// TODO:	[] validate emptiness of stack b

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
