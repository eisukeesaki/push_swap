/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_ins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 14:57:45 by eesaki            #+#    #+#             */
/*   Updated: 2019/11/13 21:35:35 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stddef.h>



void	vali_ins(char *ins)
{
	size_t	i;
	char	*ins_list[] =// TODO: move to dedicated header
	{
		{"sa\n"},
		{"sb\n"},
		{"ss\n"},
		{"pa\n"},
		{"pb\n"},
		{"ra\n"},
		{"rb\n"},
		{"rr\n"},
		{"rra\n"},
		{"rrb\n"},
		{"rrr\n"},
	};
	i = 0;
	while (ins_list[i])
	{
		if (!(ft_strequ(ins_list[i], ins)))
		{
			write(1, "invalid ins", 12);
			exit(1);
		}
		else
		{
			add_ins(ins_list[i]);
			i = 0;
			continue;
		}
		i++;
	}
}

void	link_node_tail(t_ins_set *head, t_ins_set *new)
{
	while (head->next != NULL)
		head = head->next;
	head->next = new;
}

t_ins_set	*newnode(char *s)
{
	t_ins_set	*node;

	node = (t_ins_set *)ft_memalloc(sizeof(t_ins_set));
	node->ins = s;
	node->next = NULL;
	return (node);
}

void	read_ins(t_ins_set *ins_set, char *ins)
{
	t_ins_set	*head;
	t_ins_set	*tmp;

	// validate ins
	head = NULL;
	tmp = newnode(ins);
	if (head = NULL)
		head = tmp;
	else
		link_node_tail(head, tmp);

}

