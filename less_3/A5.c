#include <stdio.h>

int main(void)
{
	float a=0,b=0,c=0,r=0;
	scanf("%f%f%f", &a,&b,&c);
	r = (a + b + c) / 3;
	printf("%.2f\n", r);
	return 0;
}

