#include <stdio.h>


int main(void)
{
	int a=0,b=0,arch=0;
	scanf("%d", &a);
	if (a==0) {
		printf("%d \n", 0);
		return 0;
	}
	while (a>0){
		b=a%10;
		a=(a-b)/10;	
		arch=arch+b;
		if(a<1){
			printf("%d \n", arch);
			return 0;
		}
		arch=arch*10;	
	}
}


