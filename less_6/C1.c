#include <stdio.h>
#include <math.h>

int mod(int a)
{
	int b=0;
	b=abs(a);
	return b;
}

int main(void)
{
	
	int a=0,b=0;

	scanf("%d", &a);
	
	b=mod(a);

	printf("%d ", b);			
		
	return 0;
}


