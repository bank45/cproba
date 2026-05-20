#include <stdio.h>

int main(void)
{
	int a=0,b=0,c=0,r=0,s=0;
	scanf("%d%d%d", &a,&b,&c);
	r = a + b + c;
	s = a * b * c;
	printf("%d+%d+%d=%d\n", a,b,c,r);
	printf("%d*%d*%d=%d\n", a,b,c,s);
	return 0;
}

