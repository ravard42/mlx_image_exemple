#include <stdio.h>

int	main()
{
	unsigned int	i;

	
	i = 0;
	*((unsigned char *)&i + 3) = 128;
	printf("%d\n" , *((unsigned char *)&i + 3));
	printf("%d\n" , *((unsigned char *)&i + 2));
	printf("%d\n" , *((unsigned char *)&i + 1));
	printf("%d\n" , *(unsigned char *)&i);
	printf("\n%d\n", i);
	return (0);
}


// on est en little endian ici puisque l octet de poid fort est en dernier, i-e a l adresse de la variable + 3 deplacement de type char, donc troix octet plus loin
