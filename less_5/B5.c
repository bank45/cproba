#include <stdio.h>


int main(void)
{
	
	int a=1,b=0,sum=0;
	scanf("%d", &a);
	if (a==0){
		printf("%d ", sum);
	}else{
		while (a>0)	{
			b=a%10;
			a=(a-b)/10;
			sum=sum+b;
	}
	printf("%d ", sum);

	return 0;
}
}

