#include "push_swap.h"
#include <stdio.h>

void	print_stack(t_stack *stack, char *comment)
{
	t_elm		*elm = stack->head;
	int			i = 0;
	printf("<stack_%s>\n", comment); setbuf(stdout, NULL);
	if (stack)
	{
		while (i++ < stack->size)
		{
			printf("%d(seg:%d)\n", elm->n, elm->seg); setbuf(stdout, NULL);
			elm = elm->next;
		}
	}
	else
		printf("empty\n"); setbuf(stdout, NULL);
	printf("\n"); setbuf(stdout, NULL);
	// if (strcmp(comment, " (initial)"))
		// printf("-------------------------------------------------------\n"); setbuf(stdout, NULL);
}

void	print_stacks(t_ps *ps, char *comment)
{
	t_elm		*a = ps->a->head;
	int			i = 0;
	printf("<stack_a(%s)>\n", comment); setbuf(stdout, NULL);
	if (a)
	{
		while (i++ < ps->a->size)
		{
			printf("%d(seg:%d)\n", a->n, a->seg); setbuf(stdout, NULL);
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
}

// print_stacks_bw()?