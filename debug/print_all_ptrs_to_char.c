#include <stdio.h>
#include <stdlib.h>

void		print_all_ptrs_to_char(char **p, char *comment)
{
	int		i = 0;

	printf("<printing %s ...>\n", comment); setbuf(stdout, NULL);
	if (p[i] == NULL)
	{
		printf("*p points to NULL. Nothing to print. exit(1)ing.\n"); setbuf(stdout, NULL);
		exit(1);
	}
	while (p[i])
	{
		printf("%s\n", p[i]); setbuf(stdout, NULL);
		i++;
	}
	printf("<done.>\n");
}
