#include <stdio.h>


int main(void)
{
	
	int a=0,b=0,c=0;
	scanf("%d", &a);
	if (a==0){
		printf("%s ", "NO");
	}else{
		while (a>0)	{
			b=a%10;
			a=(a-b)/10;
			c=b%2;
			if(c>0) {
				printf("%s ", "NO");
				return 0;
			}
	}
	printf("%s ", "YES");

	return 0;
}
}

