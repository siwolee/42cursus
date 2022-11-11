#include <string.h>
#include <stdio.h>

void *ft_memset(void *b, int c, unsigned long len);
void *ft_memmove(void *dst, const void *src, unsigned long len);

int	main()
{
	printf("\n\n-----------.-------------\n");

	printf("original : \n");

	printf("ft_ : \n");





	printf("\n\n-----------memset-------------\n");
	char	str[10];

	printf("original : \n");
	printf("%s\n", (char *)memset(str, 'c', 7));

	printf("ft_ : \n");
	printf("%s\n", (char *)ft_memset(str, 'b', 6));



	printf("\n\n-----------memmove-------------\n");
	char	str2[10] = "01234....";
	char	*ptr;
	ptr = str2 + 2;

	printf("original_try in char : \n");
	printf("ans : %s , %s\n", str2, (char *)memmove(ptr, str2, 5));
	char	str3[10] = "01234....";
	ptr = str3 + 2;
	printf("ft_ : %s , %s\n", str3,(char *)ft_memmove(ptr, str3, 5));



}
