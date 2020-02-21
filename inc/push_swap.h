/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <eesaki@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 15:54:44 by eesaki            #+#    #+#             */
/*   Updated: 2020/02/20 20:23:13 by eesaki           ###   ########.fr       */
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
// # define ERROR(message) error(message)

/*
**-----------------------------------------------------------------------------
**                                  structs
**-----------------------------------------------------------------------------
*/
typedef struct		s_elm
{
	int				n;
	struct s_elm	*prev;
	struct s_elm	*next;
}					t_elm;

typedef struct		s_stack
{
	t_elm			*head;
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
	NOPS /* 11 */
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

/* validation.c */
void				vali_dup(t_stack *stack, int n);
t_bool				is_sorted_circularly(t_elm *elm, int stack_size);

/* load.c */
t_ps				*get_ps(char **av);

/* sort.c */
t_bool				rotate_only_sort(t_ps *ps);
void				sort_3(t_ps *ps, t_stack *stack);
void				median_3_sort(void);

/* list_manipulation.c */
t_elm				*create_node(int n);
void				append_node(t_stack *stack, t_elm *node);

/* operations.c */
void				perform_op_ntimes(t_ps *ps, int op, int n);

#endif
