/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 15:54:44 by eesaki            #+#    #+#             */
/*   Updated: 2020/05/23 04:50:44 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdint.h>
# include <stdlib.h>
# include "libft.h"
# include <stdio.h> // debug purpose

/*
**-----------------------------------------------------------------------------
**                                  macros
**-----------------------------------------------------------------------------
*/
# define ERROR(message) error(message)
# define DBG 1
# define OPS "ra", "rb", "rra", "rrb", "pa", "pb",\
				"sa", "sb", "rr", "rrr", "ss"

/*
**-----------------------------------------------------------------------------
**                                  structs
**-----------------------------------------------------------------------------
*/
typedef struct		s_elm
{
	int				n;
	int				segment;
	struct s_elm	*prev;
	struct s_elm	*next;
}					t_elm;

typedef struct		s_stack
{
	t_elm			*head;
	t_elm			*tail;
	int				size;
}					t_stack;

typedef struct		s_ps
{
	t_stack			*a;
	t_stack			*b;
	t_stack			*ops;
	t_bool			verbose;
}					t_ps;

/*
**-----------------------------------------------------------------------------
**                                  enums
**-----------------------------------------------------------------------------
*/
typedef enum		e_ops
{
	RA,  /* 0 */
	RB,  /* 1 */
	RRA, /* 2 */
	RRB, /* 3 */
	PA,  /* 4 */
	PB,  /* 5 */
	SA,  /* 6 */
	SB,  /* 7 */
	RR,  /* 8 */
	RRR, /* 9 */
	SS,  /* 10 */
	NOPS /* 11 (total amount of ops) */
}					t_ops;

/*
**-----------------------------------------------------------------------------
**                                  protptypes
**-----------------------------------------------------------------------------
*/
/* debug.c */
void				print_stacks(t_ps *ps, char *comment);

/* error.c */
void				error(char *message);

/* ps_atoi.c */
intmax_t			ps_atoi(const char *str);

/* utils.c */
t_elm				*find_min(t_stack *stack);
int					*create_array(t_stack *stack);

/* validation.c */
void				vali_dup(t_stack *stack, int n);
t_bool				is_sorted_circularly(t_elm *elm, int stack_size);

/* load.c */
t_ps				*get_ps(char **av);

/* sort.c */
t_bool				rotate_only_sort(t_ps *ps);
void				sort_3(t_ps *ps, t_stack *stack);
void				median_3_sort(t_ps *ps);

/* list_manipulation.c */
t_elm				*create_node(int n);
void				append_node(t_stack *stack, t_elm *node);
void				unlink_node(t_stack *stack, t_elm *node);

/* print_op_list.c */
void				print_op_list(t_stack *op_list);

/* get_median.c */
int					get_median(int *array, int size);

/* operations.c */
void				perform_op_ntimes(t_ps *ps, int op, int n);
void				rotate_up(t_stack *stack);
void				rotate_down(t_stack *stack);
void				swap(t_stack *stack);
void				push(t_stack *from, t_stack *to);

/* call_ops.c */
// void				call_op(char *op, t_ps *ps);

/* push.c */
// void				push(t_stack *from, t_stack *to, t_ps *ps);

#endif
