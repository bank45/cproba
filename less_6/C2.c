#include <stdio.h>
#include <math.h>


int pov(int a,int b)
{
	int c=0;
	c=pow(a,b);
	return c;
}

int main(void)
{
	
	int a=0,b=0,c=0;

	scanf("%d%d", &a,&b);
	
	c=pov(a,b);

	printf("%d ", c);			
		
	return 0;
}


