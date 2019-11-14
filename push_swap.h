/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 12:21:01 by eesaki            #+#    #+#             */
/*   Updated: 2019/11/13 15:02:06 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdint.h>
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< testing
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> testing
// # include "libft/libft.h"

/*
**-----------------------------------------------------------------------------
**									structs
**-----------------------------------------------------------------------------
*/
typedef struct		s_stack
{
	int				n;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

typedef struct			s_ins_set
{
	char				*ins;
	struct s_ins_set	*next;
}						t_ins_set;

typedef struct		s_ins
{
	char			*name;
	void			(*ins)(t_stack *);
}					t_ins;

/*
**-----------------------------------------------------------------------------
**									prototypes
**-----------------------------------------------------------------------------
*/
void				error(void);
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< debug purpose
void				dup_err(void);
void				notint_err(void);
void				sort_err(void);
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> debug purpose
intmax_t			my_atoi(const char *str);
int					get_next_line(const int fd, char **line);
intmax_t			vali_int(intmax_t n);
void				vali_dup(t_stack *head);
void				vali_sort(t_stack *head);


t_stack				*newdnode(int data);
void				link_dnode_head(t_stack *head, t_stack *new);
void				link_dnode_tail(t_stack *head, t_stack *new);

void				sa(t_stack *head);
void				sb(t_stack *head);

// t_ins				ins_table[2] =
// {
// 	{"sa", sa},
// 	{"sb", sb},
// };

// typedef struct		s_list
// {
// 	int				*n;
// 	struct s_list	*next;
// }					t_list;


#endif