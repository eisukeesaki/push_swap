#include "push_swap.h"
#include <stdio.h>

t_bool	print_stack(t_stack *stack, char *comment)
{
	t_elm		*elm = stack->head;
	int			i = 0;

	printf("<stack_%s>\n", comment); setbuf(stdout, NULL);
	if (stack)
	{
		while (i++ < stack->size)
		{
			printf("%d(seg:%d)(sorted:%d)\n", elm->n, elm->seg, elm->sorted); setbuf(stdout, NULL);
			elm = elm->next;
		}
	}
	else
		printf("empty\n"); setbuf(stdout, NULL);
	printf("\n"); setbuf(stdout, NULL);
	// if (strcmp(comment, " (initial)"))
		// printf("-------------------------------------------------------\n"); setbuf(stdout, NULL);
	return (TRUE);
}

// void	print_stacks(t_ps *ps, char *comment)
t_bool	print_stacks(t_ps *ps, char *comment)
{
	t_elm		*a = ps->a->head;
	int			i = 0;
	printf("<stack_a(%s)>\n", comment); setbuf(stdout, NULL);
	if (a)
	{
		while (i++ < ps->a->size)
		{
			printf("%d(seg:%d)(sorted:%d)\n", a->n, a->seg, a->sorted); setbuf(stdout, NULL);
			a = a->next;
		}
	}
	else
		printf("empty\n"); setbuf(stdout, NULL);
	printf("\n"); setbuf(stdout, NULL);

	t_elm		*b = ps->b->head;
	i = 0;
	printf("<stack_b(%s)>\n", comment); setbuf(stdout, NULL);
	if (b)
	{
		while (i++ < ps->b->size)
		{
			printf("%d(seg:%d)\n", b->n, b->seg); setbuf(stdout, NULL);
			b = b->next;
		}
	}
	else
		printf("empty\n"); setbuf(stdout, NULL);
	// if (strcmp(comment, " (initial)"))
		// printf("-------------------------------------------------------\n"); setbuf(stdout, NULL);
	return (TRUE);
}

// print_stacks_bw()?