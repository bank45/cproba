#include <stdio.h>


int main(void)
{
	int a=0,b=0,c=1,num=1,coun=0;

		scanf("%d", &a);
		while(coun<a){
			coun++;
			printf("%d ", num);					
			num=b+c;
			b=c;
			c=num;			
		}
	return 0;
}


