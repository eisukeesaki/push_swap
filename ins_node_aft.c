/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ins_node_aft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 17:13:04 by eesaki            #+#    #+#             */
/*   Updated: 2019/10/13 20:12:26 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stddef.h>

void	ins_node_aft(t_stack *head, t_stack *new)
{
	while (head->next != NULL)
		head = head->next;
	head->next = new;
}
