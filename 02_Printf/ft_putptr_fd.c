/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:24:44 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/11/01 18:39:50 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// pass a number, get it's hex value at digit place
static char	ft_get_digit(void *ptr, int digit)
{
	unsigned long long	number;

	number = (unsigned long long)ptr;
	while (digit)
	{
		number = number / 16;
		digit--;
	}
	number = number % 16;
	if (number <= 9)
		return (number + '0');
	else
		return (number - 10 + 'a');
}

// Init vars in 1 line
static void	ft_init(int *digit, int *result, int *start_print)
{
	*digit = 15;
	*result = 2;
	*start_print = 0;
}

// Print the pointer in hex
int	ft_putptr_fd(void *ptr, int fd)
{
	int	digit;
	int	result;
	int	start_print;

	if (!ptr)
		return (write(fd, "0x0", 3));
	ft_init(&digit, &result, &start_print);
	if (ft_putstr_fd("0x", fd) == -1)
		return (-1);
	while (digit >= 0)
	{
		if (ft_get_digit(ptr, digit) != '0' || start_print)
		{
			if (ft_putchar_fd(ft_get_digit(ptr, digit), fd) == -1)
				return (-1);
			start_print = 1;
			result++;
		}
		digit--;
	}
	return (result);
}

/*
// Cette fonction convertit un chiffre hexadécimal en caractère correspondant
static char ft_get_digit(void *ptr, int digit)
{
    unsigned long long number;
    
    // On caste le pointeur en unsigned long long
    number = (unsigned long long)ptr;

    // On itère jusqu'au chiffre désiré
    while (digit)
    {
        number = number / 16; // On divise par 16 pour obtenir le chiffre suivant
        digit--;
    }
    
    number = number % 16; // On prend le reste pour obtenir le chiffre hexadécimal

    if (number <= 9)
        return (number + '0'); // Les chiffres de 0 à 9
    else
        return (number - 10 + 'a'); // Les chiffres de a à f
}

// Cette fonction initialise les variables utilisées pour l'impression de l'adresse mémoire
static void ft_init(int *digit, int *result, int *start_print)
{
    *digit = 15;       // On commence par le chiffre le plus significatif (0xF)
    *result = 2;       // On commence avec le préfixe "0x"
    *start_print = 0;  // On n'a pas encore imprimé de chiffre significatif
}

// Fonction principale pour imprimer un pointeur mémoire en hexadécimal
int ft_putptr_fd(void *ptr, int fd)
{
    int digit;
    int result;
    int start_print;

    // Si le pointeur est nul, on imprime "0x0" et on retourne 3 (longueur de la chaîne)
    if (!ptr)
        return (write(fd, "0x0", 3));

    // Initialisation des variables
    ft_init(&digit, &result, &start_print);

    // On imprime le préfixe "0x"
    if (ft_putstr_fd("0x", fd) == -1)
        return (-1); // En cas d'erreur, on retourne -1

    while (digit >= 0)
    {
        // Si le chiffre actuel n'est pas 0 ou si on a déjà imprimé un chiffre significatif
        if (ft_get_digit(ptr, digit) != '0' || start_print)
        {
            // On imprime le chiffre hexadécimal
            if (ft_putchar_fd(ft_get_digit(ptr, digit), fd) == -1)
                return (-1); // En cas d'erreur, on retourne -1
            
            start_print = 1; // On indique que l'impression a commencé
            result++;        // On incrémente le nombre de caractères imprimés
        }
        
        digit--; // On passe au chiffre suivant
    }

    return (result); // On retourne le nombre total de caractères imprimés
}

*/