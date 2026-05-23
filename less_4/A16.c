#include <stdio.h>


int main(void)
{
	int a=0,b=0,c=0;
	char *r;
	scanf("%d%d%d", &a,&b,&c);
	
	r=a<b&&b<c ? "YES":"NO";
	
	printf("%s\n", r);

	return 0;
}

