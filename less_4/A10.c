#include <stdio.h>
#include <math.h>


int main(void)
{
	int a=0,b=0,c=0,d=0,e=0,m=0;
	scanf("%d%d%d%d%d", &a,&b,&c,&d,&e);
	m=a<b?a:b;
	m=c<m?c:m;
	m=d<m?d:m;
	m=e<m?e:m;
	printf("%d\n", m);
	return 0;
}

