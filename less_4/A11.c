#include <stdio.h>
#include <math.h>


int main(void)
{
	int a=0,b=0,c=0,d=0,e=0,min=0,max=0;
	scanf("%d%d%d%d%d", &a,&b,&c,&d,&e);
	min=a<b?a:b;
	min=c<min?c:min;
	min=d<min?d:min;
	min=e<min?e:min;
	
	max=a>b?a:b;
	max=c>max?c:max;
	max=d>max?d:max;
	max=e>max?e:max;
	
	printf("%d\n", min+max);
	return 0;
}

