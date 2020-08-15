/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 15:54:44 by eesaki            #+#    #+#             */
/*   Updated: 2020/07/28 03: by eesaki           ###   ########.fr       */
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
# define DBG 0 // debug purpose
# define RDFILE 0 // debug purpose
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
	int				seg;
	t_bool			sorted;
	struct s_elm	*prev;
	struct s_elm	*next;
}					t_elm;

typedef struct		s_stack
{
	t_elm			*head;
	t_elm			*tail;
	int				size;
	/*int				top_seg;*/
}					t_stack;

typedef struct		s_ps
{
	t_stack			*a;
	t_stack			*b;
	t_stack			*ops;
	/*t_bool			verbose;*/
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
// void				print_stacks(t_ps *ps, char *comment);
t_bool				print_stacks(t_ps *ps, char *comment);
t_bool				print_stack(t_stack *stack, char *comment);
void				print_all_ptrs_to_char(char **p);

/* error.c */
void				error(char *message);

/* ps_atoi.c */
intmax_t			ps_atoi(const char *str);

/* print_op_list.c */
void				print_op_list(t_stack *op_list);

/* confirm_sort_partial.c */
t_bool				confirm_sort_partial(t_stack *a);

/* sort_partial.c */
void				mark_as_sorted(t_stack *stack);
void				sort_partial(t_stack *a, t_ps *ps);

/* stack_manipulation_helpers.c */
void				select_3_largest(int *b_arr, size_t *b_arr_size);
void				delete_seg_id(t_stack *a, int pushed_size);
int					*create_array_of_seg(t_stack *stack, int seg, size_t *arr_size);

/* get_median_in_array.c */
int					get_median_in_array(int *array, size_t size);

/* quicksort.c */
void				rev_quicksort(int *array, int size);
void				quicksort(int *array, int size);

/* get_median_in_a.c */
int					get_median_in_a(t_stack *stack);

/* sort_top_3_helpers */
void				update_top_mid_btm(t_stack *a, int *top, int *mid, int *btm);

/* sort.c */
void				sort(t_ps *ps);
void				sort_top_3(t_ps *ps);

/* sort_5.c */
void				sort_5(t_ps *ps);

/* sort_3.c */
void				sort_3(t_ps *ps, t_stack *stack);

/* list_manipulation.c */
void				free_elms(t_stack *stack);
void				free_ps(t_ps *ps);
void				free_stack(t_ps *ps, t_stack *stack);
void				unlink_node(t_stack *stack, t_elm *node);
void				append_node(t_stack *stack, t_elm *node);
t_elm				*create_node(int n);

/* operations.c */
/* checker */
void				rotate_up(t_stack *stack); /* ra, rb */
void				rotate_down(t_stack *stack); /* rra, rrb */
void				push(t_stack *from, t_stack *to);
void				swap(t_stack *stack);
/* /checker */
void				perform_op_ntimes(t_ps *ps, int op, int n);

/* stack_manipulation.c */
void				pa_all_in_list(t_ps *ps, int *pa_list, int b_arr_size);
void				rotate_til_at_top(t_ps *ps, t_stack *stack, t_elm *dest);
void				process_b(t_ps *ps);
void				pb_smaller(t_ps *ps, t_stack *pb_list);

/* validation.c */
t_bool				is_sorted_circularly(t_stack *stack, t_elm *min_elm);
void				vali_dup(t_stack *stack, int n);

/* sort_helpers.c */
int					get_top_seg(t_stack *b);
int					count_unsorted(t_stack *stack); // returns num of unsorted elms in stack_a
t_bool				is_sorted(t_stack *a);
int					get_rotation_count(t_stack *stack, t_elm *dest, t_bool reverse);
t_elm				*find_min(t_stack *stack);

/* rotate_only_sort.c */
t_bool				rotate_only_sort(t_ps *ps);

/* ps_strsplit.c */
// char				**ps_strsplit(char *s, char c);

/* load.c */
t_ps				*get_ps(char **av);

#endif
