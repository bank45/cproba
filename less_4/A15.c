#include <stdio.h>


int main(void)
{
	float x1=0,y1=0,x2=0,y2=0,k=0,b=0;
	scanf("%f%f%f%f", &x1,&y1,&x2,&y2);
	
	k=(y2-y1)/(x2-x1);
	b=y2-k*x2;
	
	printf("%.2f %.2f\n", k,b);

	return 0;
}

