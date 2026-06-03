#include <stdio.h>


 int middle(int a, int b)
{
	int c=0;
	c=(a+b)/2;
	return c;
}

int main(void)
{
	
	int a=0,b=0,c=0;

	scanf("%d%d", &a,&b);
	
	c=middle(a,b);

	printf("%d ", c);			
		
	return 0;
}


