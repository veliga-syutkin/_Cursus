#include <stdlib.h>
#include <stdio.h>

int ft_str_is_sym(char c, char *charset)
{
	int i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int ft_strlen_mod(char *str, char *charset)
{
	int i;

	i = 0;
	while (str[i] && !ft_str_is_sym(str[i], charset))
		i++;
	printf("STRLEN_mod: %d\n", i);
	return (i);
}

int ft_wordcount(char *str, char *charset)
{
	int words;
	int i;
	int len;

	words = 0;
	i = 0;
	len = 0;
	while (str[i])
	{
		while (str[i] && ft_str_is_sym(str[i], charset))
			i++;
		len = ft_strlen_mod(str + i, charset);
		if (len > 0)
		{
			words++;
			i += len;
		}
		else
			i++;
	}
	// printf("nb words: %d\n", words);
	return (words);
}

char **ft_merror(char **split, int i)
{
	while (i > 0)
	{
		free(split[i]);
		i--;
	}
	free(split);
	return (NULL);
}

char *ft_strndup(char *str, int n)
{
	int i = 0;
	char *result;
	result = (char *) malloc (n + 1);
	if (!result)
		return (NULL);
	while (str[i] && i < n)
	{
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';
	printf("strndup: %s\n", result);
	return (result);
}

char *ft_charset(void)
{
	static char charset[3];
	charset[0] = ' ';
	charset[1] = '\t';
	charset[2] = '\0';
	return (charset);
}

char **ft_split(char *str)
{
	if (!str)
		return (NULL);

	char **words;
	int i = 0;
	int len;
	int height;
	int height_current;
	char *charset = ft_charset();

	// printf("charset: %s\n", charset);
	height = (ft_wordcount(str, charset) + 1);
	// printf("Height: %d\n", height);
	words = (char **) malloc (height);
	if (!words)
		return (NULL);
	words[height] = NULL;
	height_current = 0;
	while (str[i])
	{
		while (str[i] && ft_str_is_sym(str[i], charset))
			i++;
		len = ft_strlen_mod(str + i, charset);
		if (len > 0)
		{
			words[height_current] = ft_strndup(&str[i], len);
			if (!words[height_current])
				return (ft_merror(words, height_current));
			i += len;
			height_current++;
		}
		else
			i++;
	}
	return (words);
}