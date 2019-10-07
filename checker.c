/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 20:48:25 by eesaki            #+#    #+#             */
/*   Updated: 2019/10/06 21:50:45 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	verify_sort(t_stack *head_a, t_stack *head_b)
{
	// check stack_a: ascending?
	// check stack_b: empty?
}

TODO		extract_a(int ac, char **av)
{
	// strsplit_2() all elms in av

	// alloc required nodes for each av elm and a head ptr

	// atoi(split[i])->validate->assign ret val to each node

}

// TODO:	- alloc stack_b
// TODO:	- read instructions on stdout
//			- create array of pointers to instruction funs
// TODO:	- dispatch all funcs in array of instructions. pass stack_a stack_b as args
// TODO:	- implement instruction funcs
// TODO:	- verify sorted result

int		main(int ac, char **av)
{
	if (ac > 1)
	{
		extract_a(ac, av);
	}

	verify_sort(head_a, head b);

	return (0);
}