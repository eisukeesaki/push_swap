/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 20:48:25 by eesaki            #+#    #+#             */
/*   Updated: 2019/10/13 21:16:39 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stddef.h>
#include <stdint.h>
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< debug
#include <stdio.h>
#include <limits.h>
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> debug

// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< dev purpose
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< prototypes
t_stack	*newnode(int data);
void	ins_node_aft(t_stack *head, t_stack *new);
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> prototypes

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

void	print_stack(t_stack *head)
{
	while (head != NULL)
	{
		printf("%d,", (int)head->n);
		head = head->next;
	}
	printf("\n");
}
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> dev purpose

void	validate_sort(t_stack *head)
{
	t_stack	*start;
	t_stack	*comp;

	start = head;
	comp = head->next;
	while (comp != NULL)
	{
		if (!(start->n > comp->n))
			sort_err(); // replace with error()
		comp = comp->next;
		start = start->next;
	}
}

void		validate_dup(t_stack *head)
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

intmax_t	validate_int(intmax_t n)
{
	if (!(INT_MIN <= n && n <= INT_MAX))
		notint_err(); // replace with error()
	return (n);
}

t_stack	*build_a(int index, char **av)
{
	size_t	i;
	size_t	k;
	char	**split;
	t_stack	*head; // head == top of stack
	t_stack	*tmp;

	i = index;
	k = 0;
	head = NULL;
	while (0 < i)
	{
		split = ft_strsplit(av[i], ' ');
		while (split[k])
		{
			tmp = newnode(validate_int(my_atoi(split[k])));
			if (head == NULL)
				head = tmp;
			else
				ins_node_aft(head, tmp);
			k++;
		}
		k = 0;
		i--;
	}
	return (head);
}

int		main(int ac, char **av)
{
	t_stack	*head_a;

	head_a = NULL;
	if (ac > 1)
	{
		head_a = build_a(ac - 1, av);
	}
	else
		exit(0);
	print_stack(head_a);

	validate_dup(head_a);

	validate_sort(head_a);

	return (0);
}


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
