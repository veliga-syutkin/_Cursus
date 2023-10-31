#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <string_to_convert>\n", argv[0]);
        return 1;
    }

    const char *input = argv[1];
    int result_ft_atoi = ft_atoi(input);
    int result_atoi = atoi(input);

    printf("Input string: %s\n", input);
    printf("Converted integer using ft_atoi: %d\n", result_ft_atoi);
    printf("Converted integer using atoi: %d\n", result_atoi);

    if (result_ft_atoi == result_atoi)
    {
        printf("Results match!\n");
    }
    else
    {
        printf("Results differ!\n");
    }

    return 0;
}