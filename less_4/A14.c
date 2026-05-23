#include <stdio.h>


int main(void)
{
	int n=0,a=0,b=0,c=0,max=0;
	scanf("%d", &n);
	a=n%10; n=(n-a)/10; 

	b=n%10; n=(n-b)/10;

	c=n;

	
	max=a>b?a:b;
	max=c>max?c:max;;
	
	printf("%d\n", max);

	return 0;
}

