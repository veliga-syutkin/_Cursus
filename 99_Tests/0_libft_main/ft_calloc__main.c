//						- MAIN FOR TESTS -

#include <stdio.h>
int main ()
{
	size_t memb = INT_MAX;
	size_t size = 100;

//	printf("\nFT_Calloc: %p\n", ft_calloc(memb, size));
	printf("\n_calloc_long_max %p", calloc(memb, size));
	printf("\n calloc INT MAX x 20: %p", calloc(INT_MAX, 20));
}
