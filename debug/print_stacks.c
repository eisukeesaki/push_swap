#include "../push_swap.h"
#include <stdio.h>
#include <stddef.h>
#include <string.h>

void	print_stacks(t_stack *stack_a, t_stack *stack_b, char *comment)
{
	printf("stack_a%s:", comment); setbuf(stdout, NULL);
	if (stack_a != NULL)
	{
		while (stack_a != NULL)
		{
			printf("%d,", (int)stack_a->n); setbuf(stdout, NULL);
			stack_a = stack_a->next;
		}
	}
	else
		printf("empty\n"); setbuf(stdout, NULL);
	printf("\n"); setbuf(stdout, NULL);

	printf("stack_b%s:", comment); setbuf(stdout, NULL);
	if (stack_b != NULL)
	{
		while (stack_b != NULL)
		{
			printf("%d,", (int)stack_b->n); setbuf(stdout, NULL);
			stack_b = stack_b->next;
		}
	}
	else
		printf("empty\n"); setbuf(stdout, NULL);
	if (strcmp(comment, " (initial)"))
		printf("-------------------------------------------------------\n"); setbuf(stdout, NULL);
}

void	print_stacks_bw(t_stack *stack_a, t_stack *stack_b, char *comment)
{
	printf("\n"); setbuf(stdout, NULL);
	printf("stack_a%s backwards:", comment); setbuf(stdout, NULL);
	if (stack_a != NULL)
	{
		while (stack_a->next != NULL)
			stack_a = stack_a->next;
		while (stack_a != NULL)
		{
			printf("%d,", (int)stack_a->n); setbuf(stdout, NULL);
			stack_a = stack_a->prev;
		}
	}
	else
		printf("empty\n"); setbuf(stdout, NULL);
	printf("\n"); setbuf(stdout, NULL);

	printf("stack_b%s backwards:", comment); setbuf(stdout, NULL);
	if (stack_b != NULL)
	{
		while (stack_b->next != NULL)
			stack_b = stack_b->next;
		while (stack_b != NULL)
		{
			printf("%d,", (int)stack_b->n); setbuf(stdout, NULL);
			stack_b = stack_b->prev;
		}
	}
	else
		printf("empty\n"); setbuf(stdout, NULL);
	printf("\n"); setbuf(stdout, NULL);
}
