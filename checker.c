/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 20:48:25 by eesaki            #+#    #+#             */
/*   Updated: 2019/11/07 01:17:36 by eesaki           ###   ########.fr       */
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

// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< dev purpose

// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< testing
void	print_stack(t_stack *head);
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> testing

// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< error funcs
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
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> error funcs


// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> dev purpose

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

// t_stack	*build_a(int index, char **av)
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
	// while (0 < i)
	while (i < (size_t)ac)
	{
		split = ft_strsplit(av[i], ' ');
		while (split[k])
		{
			tmp = newnode(vali_int(my_atoi(split[k])));
			if (head == NULL)
				head = tmp;
			else
				ins_node_aft(head, tmp);
			k++;
		}
		k = 0;
		// i--;
		i++;
	}
	return (head);
}

int		main(int ac, char **av)
{
	t_stack	*head_a;
	char	*ins;
	// size_t	i;
	int		fd = 0; // test

	head_a = NULL;
	if (ac > 1)
	{
		// head_a = build_a(ac - 1, av);
		head_a = build_a(ac, av);
	}
	else
		exit(0);
	print_stack(head_a); // test

	vali_dup(head_a);
	vali_sort(head_a);

	ins = NULL;
	// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< reading ins from file instead of stdin to allow debugging
	if ((fd = open("unused/instructions.txt", O_RDONLY)) == 1)
	{
		puts("file open error");
		exit(1);
	}
	// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> reading ins from file instead of stdin to allow debugging
	// while (get_next_line(0, &ins))
	while (get_next_line(fd, &ins))
	{
		printf("read a instruction\n"); // test
		ft_putendl(ins); //test
		ft_strdel(&ins); // test
	}

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

	return (0);
}
// TODO:	- modify gnl so that it allocates buffer dynamically

// TODO:	- read instructions on stdin
// TODO:	- validate instructions
// TODO:	- create array of pointers to instruction funs
// TODO:	- dispatch all funcs in array of instructions. pass stack_a stack_b as args
// TODO:	- implement instruction funcs
// TODO:	- alloc stack_b
// TODO:	- validate emptiness of stack b

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
