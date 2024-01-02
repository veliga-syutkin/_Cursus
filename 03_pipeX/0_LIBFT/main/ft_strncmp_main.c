
int	main(void)
{
	char s1[] = "Hello, world";
	char s2[] = "Hello";
	unsigned int n;
	int result;

	n = 6;
	result = ft_strncmp(s1, s2, n);
	printf("%d", result);
	printf("%d", strncmp(s1, s2, n));
}
