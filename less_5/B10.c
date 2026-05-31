#include <stdio.h>


int main(void)
{
	int a=0,b=0,arch=10;
	scanf("%d", &a);
	do{
		b=a%10;
		a=(a-b)/10;	
		if(arch<=b) {
			
		printf("%s ", "NO");
		return 0;
		}
		arch=b;	
	}while (a>0);
	printf("%s ", "YES");
	return 0;
}


