#include <stdio.h>


int main(void)
{
	
	int a=0,b=0;
	scanf("%d%d", &a,&b);
	
	for (int i = a; i <= b; i++)
	{
		printf("%d ", i*i);
	}

	return 0;
}

