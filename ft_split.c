/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 04:18:48 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/10/28 18:20:55 by vsyutkin         ###   ########.fr       */
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

// If new substring is not correctly malloced, we free everything
static	char	**ft_malloc_error(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

/*Calculates the length of a substring in str 
until a delimiter character from charset is encountered. 
It returns the length of the substring.
*/
static	int	ft_strlen_mod(const char *str, char charset)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != charset)
		i++;
	return (i);
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
		while (str[i] && (str[i] == charset))
			i++;
		len = ft_strlen_mod(str + i, charset);
		if (len > 0)
			words++;
		i = i + len;
	}
	return (words);
}

// Ends the array of pointers with NULL
char	**ft_sub_split(char **tab, unsigned int k)
{
	tab[k] = NULL;
	return (tab);
}

/*Splits the string s using the c delimiter 
and returns an array of pointers to the resulting substrings. 
*/
char	**ft_split(char const *s, char c)
{
	unsigned int	index;
	unsigned int	k;
	unsigned int	len;
	char			**words;

	k = 0;
	index = 0;
	words = (char **)malloc((ft_wordcount(s, c) + 1) * sizeof(char *));
	if (words == NULL || s == NULL)
		return (NULL);
	while (s[index])
	{
		while (s[index] && !(s[index] != c))
			index++;
		len = ft_strlen_mod(s + index, c);
		if (len > 0)
		{
			words[k] = ft_substr(s, index, len);
			if (!words[k])
				return (ft_malloc_error(words));
			k++;
		}
		index = index + len;
	}
	return (ft_sub_split(words, k));
}

