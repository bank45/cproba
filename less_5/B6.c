#include <stdio.h>


int main(void)
{
	
	int a=1,b=0,arch=0;
	scanf("%d", &a);
	if (a==0){
		printf("%s ", "NO");
	}else{
		while (a>0)	{
			b=a%10;
			if (b==arch) {
				printf("%s ", "YES");
				return 0;
			}
				
			a=(a-b)/10;
			arch=b;
	}
	printf("%s ", "NO");

	return 0;
}
}

