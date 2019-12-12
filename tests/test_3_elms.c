#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int		main(void)
{
	printf("------1,2,3\n"); setbuf(stdout, NULL);
	system("ARG=\"1 2 3\" ; ../push_swap $ARG | ../checker $ARG");
	printf("------1,2,3\n\n"); setbuf(stdout, NULL);

	printf("------1,3,2\n"); setbuf(stdout, NULL);
	system("ARG=\"1 3 2\" ; ../push_swap $ARG | ../checker $ARG");
	printf("------1,3,2\n\n"); setbuf(stdout, NULL);

	printf("------2,1,3\n"); setbuf(stdout, NULL);
	system("ARG=\"2 1 3\" ; ../push_swap $ARG | ../checker $ARG");
	printf("------2,1,3\n\n"); setbuf(stdout, NULL);

	printf("------2,3,1\n"); setbuf(stdout, NULL);
	system("ARG=\"2 3 1\" ; ../push_swap $ARG | ../checker $ARG");
	printf("------2,3,1\n\n"); setbuf(stdout, NULL);

	printf("------3,1,2\n"); setbuf(stdout, NULL);
	system("ARG=\"3 1 2\" ; ../push_swap $ARG | ../checker $ARG");
	printf("------3,1,2\n\n"); setbuf(stdout, NULL);

	printf("------3,2,1\n"); setbuf(stdout, NULL);
	system("ARG=\"3 2 1\" ; ../push_swap $ARG | ../checker $ARG");
	printf("------3,2,1\n\n"); setbuf(stdout, NULL);

	return (0);
}