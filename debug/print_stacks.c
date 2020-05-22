#include "push_swap.h"
#include <stdio.h>

void	print_stacks(t_ps *ps, char *comment)
{
	t_elm		*a = ps->a->head;
	int			i = 0;
	printf("stack_a(%s):", comment); setbuf(stdout, NULL);
	if (a)
	{
		while (i++ < ps->a->size)
		{
			printf("%d,", a->n); setbuf(stdout, NULL);
			a = a->next;
		}
	}
	else
		printf("empty\n"); setbuf(stdout, NULL);
	printf("\n"); setbuf(stdout, NULL);

	t_elm		*b = ps->b->head;
	i = 0;
	printf("stack_b(%s):", comment); setbuf(stdout, NULL);
	if (b)
	{
		while (i++ < ps->b->size)
		{
			printf("%d,", b->n); setbuf(stdout, NULL);
			b = b->next;
		}
	}
	else
		printf("empty\n"); setbuf(stdout, NULL);
	// if (strcmp(comment, " (initial)"))
		// printf("-------------------------------------------------------\n"); setbuf(stdout, NULL);
}

// print_stacks_bw()?