/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 07:29:16 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/10/28 06:39:49 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Returns a pointer to a new string which is a duplicate of the string s,
 and terminated with \0. Memory for the new string is obtained with malloc(3).
*/
char	*ft_strdup(const char *s);

char	*ft_strdup(const char *s)
{
	int		len;
	char	*copy;

	len = ft_strlen(s) + 1;
	copy = (char *)malloc(len * (sizeof(char)));
	if (!copy)
		return (NULL);
	ft_strlcpy(copy, s, len);
	return (copy);
}

//protected
/*char	*ft_strdup(const char *s)
{
	int		len;
	char	*copy;

	if (!s)
		return (NULL);
	len = ft_strlen(s) + 1;
	copy = (char *)malloc(len * (sizeof(char)));
	if (!copy)
		return (NULL);
	ft_strlcpy(copy, s, len);
	return (copy);
}*/

//						- MAIN FOR TESTS -
/*
#include <stdlib.h>  // Pour malloc et free
#include <string.h>  // Pour strdup
#include <stdio.h> 

int main(void)
{
    char original[] = "Bonjour, ceci est un exemple.";
    
    // Utilisation de votre fonction ft_strdup
    char *copie_ft = ft_strdup(original);
    if (copie_ft == NULL)
    {
        printf("Erreur d'allocation mémoire pour ft_strdup.\n");
        return 1;
    }

    // Utilisation de la fonction strdup originale
    char *copie_originale = strdup(original);
    if (copie_originale == NULL)
    {
        printf("Erreur d'allocation mémoire pour strdup.\n");
        free(copie_ft); // Libérer la mémoire allouée par ft_strdup
        return 1;
    }

    // Comparaison des résultats
    printf("Chaîne originale : %s\n", original);
    printf("Copie avec ft_strdup : %s\n", copie_ft);
    printf("Copie avec strdup : %s\n", copie_originale);

    // Libération de la mémoire
    free(copie_ft);
    free(copie_originale);

    return 0;
}
*/