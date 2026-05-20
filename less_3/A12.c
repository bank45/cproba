#include <stdio.h>

int main(void)
{
	int a=0,r=0,s=0;
	scanf("%d", &a);
	r=a%10;
	s=s+r;
	a=a-r;
	a=a/10;	
	r=a%10;	
	s=s+r;
	a=a-r;
	a=a/10;	
	r=a%10;
	s=s+r;		
	printf("%d\n", s);
	return 0;
}

