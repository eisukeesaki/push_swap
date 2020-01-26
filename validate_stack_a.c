/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_stack_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 19:46:32 by eesaki            #+#    #+#             */
/*   Updated: 2020/01/21 14:10:01 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
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

void	b_not_empty_err(void)
{
	write(1, "b not empty err", 16);
	exit(1);
}

void	not_num_err()
{
	write(1, "not num err", 12);
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

int		is_sorted(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*start;
	t_stack	*comp;

	vali_empty_b(stack_b);
	start = stack_a;
	comp = stack_a->next;
	while (comp != NULL)
	{
		// if (!(start->n > comp->n))
		if (!(start->n < comp->n))
			return (0);
			// sort_err(); // replace with error()
		start = start->next;
		comp = comp->next;
	}
	return (1);
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

void		vali_empty_b(t_stack *stack_b)
{
	if (stack_b != NULL)
		b_not_empty_err(); // replace with error()
}

char	*vali_num(char *s)
{
	size_t	i;

	if (!ft_isdigit(s[0]) && s[0] != '-')
		not_num_err();
	i = 1;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			not_num_err(); // replace with error()
		i++;
	}
	return (s);
}

// char	*vali_num(char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	while (s[i])
// 	{
// 		if (!ft_isdigit(s[i]))
// 			not_num_err(); // replace with error()
// 		i++;
// 	}
// 	return (s);
// }
