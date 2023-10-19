/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 04:18:48 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/10/18 01:28:11 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Here's how it works:

It allocates memory for an array of pointers called words 
with the size of the number of words in str (plus one null element at the end).
It iterates through str, finding each substring between the delimiters.
For each found substring, 
it allocates memory to store the substring using ft_strndup 
and puts it into the words array.
It returns the words array of pointers.*/

#include "libft.h"

// Checks if char c is in charset
static	int	ft_str_is_sym(char c, char charset)
{
	if (charset == c)
		return (1);
	return (0);
}

/*Calculates the length of a substring in str 
until a delimiter character from charset is encountered. 
It returns the length of the substring.
*/
static	int	ft_strlen_mod(const char *str, char charset)
/* returns lenghts of str 'til something from charset is encountered.*/
{
	int	i;

	i = 0;
	while (str[i] && !ft_str_is_sym(str[i], charset))
		i++;
	return (i);
}

/* Creates a new string by copying the first n characters of str 
and adds a null character at the end. 
It returns a pointer to the new string. */
static	char	*ft_strndup(const char *str, int n)
{
	int		i;
	char	*dup;

	i = 0;
	dup = (char *)malloc(sizeof(char) * (n + 1));
	if (dup == NULL)
		return (NULL);
	while (str[i] && i < n)
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

/*Counts how many words (substrings) 
are there in str using charset as delimiters. 
It returns the number of words.
*/
static	int	ft_wordcount(const char *str, char charset)
{
	int	i;
	int	len;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		while (str[i] && ft_str_is_sym(str[i], charset))
			i++;
		len = ft_strlen_mod(str + i, charset);
		if (len > 0)
			words++;
		i = i + len;
	}
	return (words);
}

/*Splits the string s using the c delimiter 
and returns an array of pointers to the resulting substrings. 
*/
char	**ft_split(char const *s, char c)
//char	**ft_split_by_str(char *s, char *charset)
{
	int		index;
	int		k;
	int		len;
	char	**words;

	k = 0;
	index = 0;
	words = (char **)malloc((ft_wordcount(s, c) + 1) * sizeof(char *));
	if (words == NULL || s == NULL)
		return (NULL);
	while (s[index])
	{
		while (s[index] && ft_str_is_sym(s[index], c))
			index++;
		len = ft_strlen_mod(s + index, c);
		if (len > 0)
			words[k++] = ft_strndup(s + index, len);
		index = index + len;
	}
	words[k] = NULL;
	return (words);
}

// ------------------- MAIN -----------------------------------------*/
/*
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
*/
