#include <stdio.h>


int main(void)
{
	
	int a=0,b=0,s=0;
	scanf("%d%d", &a,&b);
	
	for (int i = a; i <= b; i++)
	{
		s=s+i*i;
		
	}
	printf("%d ", s);
	return 0;
}

