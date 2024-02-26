// ------------------- MAIN -----------------------------------------*/

void ft_print_array(char **array)
{
	int i;

	if (array == NULL)
		printf("Array is NULL\n");
	else
	{
		for(i = 0; array[i] != NULL; i++)
			printf("%d - %s\n", i, array[i]);
		printf("%d - NULL\n", i);
	}
}

int main(int argc, char **argv)
{
	(void)argc;
	
	ft_print_array(ft_split(argv[1], argv[2]));
}  
