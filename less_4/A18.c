#include <stdio.h>


int main(void)
{
	
	int a=0,b=0;
	scanf("%d%d", &a,&b);
	
	if (a>b) {printf("%s\n", "Above"); return 0;}
	if (a<b) {printf("%s\n", "Less"); return 0;}
	if (a==b) {printf("%s\n", "Equal"); return 0;}
}

