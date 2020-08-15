void		print_int_array(int *array, int size)
{
	int		i;

	i = 0;
	printf("int array (size:%d):", size);
	while (i < size)
	{
		printf("%d\n", array[i]);
		i++;
	}
}
