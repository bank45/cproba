#include <stdio.h>


int main(void)
{
	int a=0,b=0,c=0,m=0;
	scanf("%d%d%d", &a,&b,&c);
	m=a>b?a:b;
	m=c>m?c:m;
	printf("%d\n", m);
	return 0;
}

