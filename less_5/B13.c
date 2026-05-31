#include <stdio.h>


int main(void)
{
	int a=0,b=0,chet=0,nechet=0;
	scanf("%d", &a);

	if (a==0) {
		printf("%d \n", 0);
		return 0;
	}
	while (a>0){
		b=a%10;
		a=(a-b)/10;
		b%2==0?chet++:nechet++;
	
	}
	printf("%d %d\n", chet,nechet);
	return 0;
}


