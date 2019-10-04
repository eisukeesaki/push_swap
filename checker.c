/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 16:47:16 by eesaki            #+#    #+#             */
/*   Updated: 2019/10/03 18:05:05 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>
#include <limits.h>

void	print(int *list)
{
	int		i = 0;

	while (list[i])
	{
		printf("%d\n", list[i]);
		i++;
	}
}

// inst	*read_inst(void)
// {
// 	int		inst_ct = 3;
// 	/* parse stdout */
// 		/* count instructions */
// 	inst	*inst_lst[inst_ct];
// }

// int		*generate_a(int ac, char **av)
// {
// 	int		*list;
// 	int		i;
// 	int		k;

// 	if (!(list = (int *)ft_memalloc((ac) * sizeof(int))))
// 		return (NULL);

// 	i = 0;
// 	k = 1;
// 	while (k < ac)
// 	{
// 		list[i] = ft_atoi(av[k]);
// 		i++;
// 		k++;
// 	}
// 	return (list);
// }

char	*cat_arg(int ac, char **av)
{
	char	*s;

	s = ;
}

int		main(int ac, char **av)
{
	char	*catted_arg;

	if (ac > 1)
	{
		catted_arg = cat_arg(ac, av);
		printf("%s\n", catted_arg);
	}
	else
		printf("invalid ac\n");
	return (0);
}

// int		main(int ac, char **av)
// {
// 	int 	*list;

// 	if (ac > 1)
// 	{
// 		list = generate_a(ac, av);
// 	}
// 	else
// 		printf("invalid ac\n");
// 	return (0);
// }

/**
 * take list of ints from stdin
 * validate list
	 * correctly formatted? 
		* delimited with space/tabs?
	 * no duplicates?
	 * in the range of int?
 * 
 * validate instructions
	 * correctly formatted?
	 * valid instruction?
	 * delmited with '\n'?
 * 
 * call instructions
	 * parse instructions on stdout
	 * pas list and call
 * 
 * validate sorted stack
	 * <stack b> is empty?
	 * <stack a> is in ascending order?
		* print KO/OK
**/

/* ----------------------------------------------------- */

/** parsing stdout
 * read stdout
	 * <use gnl> to store instruction list in 2d char array
	 * 
**/

/** dispatch table (array of structs)
 * struct member
	 * pointer to instruction function
	 * label (string)
	 * 
**/

/** dispatching method
 * <compare> element in instruction list array <-> label in element of dispatch table
 * when matched, call function in element of dispatch table
**/
