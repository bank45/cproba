#include <stdio.h>


int main(void)
{
	int a=0,b=0;

		scanf("%d%d", &a,&b);
		while(a!=b){
			if(a>b){
				a=a-b;
			}
			if(b>a){
			b=b-a;
			}
		}
		printf("%d \n", a);

	return 0;
}


