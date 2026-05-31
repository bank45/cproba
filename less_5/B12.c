#include <stdio.h>


int main(void)
{
	int a=0,b=0,min=0,max=0;
	scanf("%d", &a);
	min=a;
	if (a==0) {
		printf("%d \n", 0);
		return 0;
	}
	while (a>0){
		b=a%10;
		a=(a-b)/10;
		if(b<=min)min=b;
		if(b>=max)max=b;
		//~ if(b<min)min=b;
		//~ if(max<min)max=b;	
	}
	printf("%d %d\n", min,max);
	return 0;
}


