#include <stdio.h>


int main(void)
{
	int a=0,b=0,coun=0;
	for(;;)
	{
		scanf("%d", &a);
		b=a%2;
		if(a==0)break;
		if(b==0)coun++;
		
		}


		printf("%d \n", coun);

	

	return 0;
}


