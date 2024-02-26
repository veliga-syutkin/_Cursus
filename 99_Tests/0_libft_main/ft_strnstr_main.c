
int	main(void)
{
	char	str[] = "Salut Morgane, Cest Moi. C'est vous, le Monteur?";
	char	*little;

	little = "Moi";
	printf("%s\n", ft_strstr(str, little));
	printf("%s\n", strstr(str, little));
	return (0);
}
