/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 16:56:31 by eesaki            #+#    #+#             */
/*   Updated: 2020/01/20 20:11:32 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 
- when scanning from top and bottom, increment a counter.
  compare the counters and choose the member with the smaller counter
- check if the member's index is below or above the middle point of stack
- ra/rra
- prepare b, and pb
 */

void		init_chunk(t_chunk *chunk)
{
	chunk->size = 0;
	chunk->range = 0;
	chunk->i = 0;
	chunk->j = 0;
	chunk->crnt_mbr = 0;
	chunk->top_half = 0;
}

void		choose_member(t_chunk *chunk)
{
	if (chunk->i <= chunk->j)
		chunk->top_half = 1;
	else
		chunk->top_half = 0;
}

void		move_member_top(t_stack **stack_a, t_chunk *chunk)
{
	if (chunk->top_half == 1)
	{
		while (chunk->i > 0)
		{
			ra(stack_a, NULL);
			chunk->i--;
		}
	}
	else
	{
		while (chunk->j > 0)
		{
			rra(stack_a, NULL);
			chunk->j--;
		}
	}
}

int		find_member_from_bottom(t_stack **stack_a, t_chunk *chunk)
{
	t_stack	*a;
	int		j;

	a = *stack_a;
	while (a->next != NULL)
		a = a->next;
	j = 1;
	while (a)
	{
		if (a->n <= chunk->range)
		{
			chunk->j = j;
			return (1);
		}
		j++;
		a = a->prev;
	}
	return (0);
}

int		find_member(t_stack **stack_a, t_chunk *chunk)
{
	t_stack	*a;
	int		i;

	a = *stack_a;
	i = 0;
	while (a)
	{
		if (a->n <= chunk->range)
		{
			chunk->i = i;
			return (1);
		}
		i++;
		a = a->next;
	}
	return (0);
}

void	rb_or_rrb(t_stack **stack_b, int pos)
{
	int		n_elms = count_n_elms(*stack_b);
	int		n_rotation;

	if (pos < (n_elms / 2))
	{
		n_rotation = count_rotation(*stack_b, pos, 1);
		while (0 < n_rotation--)
			rb(NULL, stack_b);
	}
	else
	{
		n_rotation = count_rotation(*stack_b, pos, 0);
		while (0 < n_rotation--)
			rrb(NULL, stack_b);
	}
}

int		find_pos_pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*b;
	int		pos;
	// int		min;
	// int		max;

	b = *stack_b;
	pos = 0;
	// min = find_min_n(*stack_a);
	// max = find_max_n(*stack_b);
	// if (max < (*stack_a)->n)
	// 	rb_or_rrb(stack_b, get_idx_of_n(*stack_b, min));
	// else if (max > (*stack_a)->n)
	// 	return (0);
	while (b->next != NULL)
	{
		pos++;
		if ((*stack_a)->n > b->n && (*stack_a)->n < b->next->n)
			return (pos);
		b = b->next;
	}
	// if (b->next == NULL)
		return (0);
	// return (pos + 1);
}

void		prep_for_pb(t_stack **stack_a, t_stack **stack_b)
{
	int		pos;

	pos = 0;
	if ((*stack_a)->n > find_max_n(*stack_b))
		rb_or_rrb(stack_b, find_min_pos(*stack_b));
		// pos = find_min_pos(*stack_b);
	else
		pos = find_pos_pb(stack_a, stack_b);
	if (pos > 0)
		rb_or_rrb(stack_b, pos);
		// while ((*stack_a)->n > (*stack_b)->n)
		// 	rb(NULL, stack_b);
}

int			empty_or_one_elm(t_stack *stack_b)
{
	int		elm;

	elm = 0;
	while (stack_b)
	{
		elm++;
		stack_b = stack_b->next;
	}
	return (elm < 2);
}

void		pb_chunk_member(t_stack **stack_a, t_stack **stack_b, t_chunk *chunk)
{	
	choose_member(chunk);
	move_member_top(stack_a, chunk);
	if (empty_or_one_elm(*stack_b) == 0)
	{
		prep_for_pb(stack_a, stack_b);
	}
	pb(stack_a, stack_b);
	// store b-min and b-max to struct?
	// print_stacks(*stack_a, *stack_b, "");
	// exit(0);
}

void		sort_medium(t_stack **stack_a, t_stack **stack_b, int n_elms)
{
	t_chunk	*chunk;
	int		i;
	int		member_exists;

	chunk = malloc(sizeof(t_chunk));
	init_chunk(chunk);

	chunk->size = n_elms / 5;
	i = 1;
	member_exists = 0;
	while (*stack_a)
	{
		chunk->range = chunk->size * i;
		member_exists = find_member(stack_a, chunk);
		member_exists = find_member_from_bottom(stack_a, chunk);
		if (member_exists == 0)
		{
			rb_or_rrb(stack_b, find_min_pos(*stack_b));
			i++;
			continue;
		}
		
		pb_chunk_member(stack_a, stack_b, chunk);
	}
	while (*stack_b != NULL)
	{
		rb_or_rrb(stack_b, find_max_pos(*stack_b));
		pa(stack_a, stack_b);
	}
}

/** to do before pb-ing
 * if current member is smaller than b-max, pb without doing anything to b
 * if current member is larger than b-max, rotate b until min is at the top
 * when there're no more members of current chunk to pb, rotate b until min is at the top 
**/