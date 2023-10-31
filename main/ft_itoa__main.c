//						- MAIN FOR TESTS -
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }

    char *input = argv[1];

    // Test ft_itoa
    int number = ft_atoi(input);  // Convertir la chaîne en entier
    char *ft_itoa_result = ft_itoa(number);  // Utiliser ft_itoa
    printf("ft_itoa Result: %s\n", ft_itoa_result);
    free(ft_itoa_result);

    // Test atoi
    int atoi_result = atoi(input);  // Utiliser la fonction système atoi
    printf("atoi Result: %d\n", atoi_result);

    return 0;
}
