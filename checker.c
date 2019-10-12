/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 20:48:25 by eesaki            #+#    #+#             */
/*   Updated: 2019/10/12 14:56:52 by eesaki           ###   ########.fr       */
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
void	nodeappend(t_stack *head, t_stack *new);
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> prototypes

// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< error funcs
void	dup_err(void)
{
	write(1, "dup err", 8);
	exit(1);
}

void	range_err(void)
{
	write(1, "range err", 10);
	exit(1);
}
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> error funcs

void	print_stack(t_stack *head)
{
	while (head != NULL)
	{
		printf("n:%d\n", (int)head->n);
		head = head->next;
	}
}
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> dev purpose

// void	validate_sort(t_stack *head_a, t_stack *head_b)
// {
// 	// check stack_a: ascending?
// 	// check stack_b: empty?
// }

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
				dup_err();
			comp = comp->next;
		}
		start = start->next;
	}
}

intmax_t	validate_int(intmax_t n)
{
	if (!(INT_MIN <= n && n <= INT_MAX))
		range_err();
	return (n);
}

t_stack	*build_a(char **av)
{
	size_t	i;
	size_t	k;
	char	**split;
	t_stack	*head;
	t_stack	*tmp;

	i = 1;
	k = 0;
	head = NULL;
	while (av[i])
	{
		split = ft_strsplit(av[i], ' ');
		while (split[k])
		{
			tmp = newnode(validate_int(my_atoi(split[k])));
			if (head == NULL)
				head = tmp;
			else
				nodeappend(head, tmp);
			k++;
		}
		k = 0;
		i++;
	}
	return (head);
}

int		main(int ac, char **av)
{
	t_stack	*head_a;

	head_a = NULL;
	if (ac > 1)
	{
		head_a = build_a(av);
	}
	validate_dup(head_a);

	// validate_sort(head_a, head_b);

	print_stack(head_a);

	return (0);
}

// TODO:	- alloc stack_b
// TODO:	- read instructions on stdout
//			- create array of pointers to instruction funs
// TODO:	- dispatch all funcs in array of instructions. pass stack_a stack_b as args
// TODO:	- implement instruction funcs
// TODO:	- validate sorted result