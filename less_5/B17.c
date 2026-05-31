#include <stdio.h>


int main(void)
{
	int a=0,b=10,d=0,c=0,sum=0,prod=1;

		scanf("%d", &a);
		while(b<=a){
			sum=0;
			prod=1;
			d=b;
				while(d>0){
					c=d%10;
					d=(d-c)/10;
					sum=sum+c;
					prod=prod*c;
				}
			if(sum==prod){
				printf("%d ", b);
			}
			b=b+1;
		}
	return 0;
}


