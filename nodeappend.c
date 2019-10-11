/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodeappend.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 17:13:04 by eesaki            #+#    #+#             */
/*   Updated: 2019/10/10 17:43:22 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stddef.h>

void	nodeappend(t_stack *head, t_stack *new)
{
	while (head->next != NULL)
		head = head->next;
	head->next = new;
}
