#include <stdio.h>


int main(void)
{
	int a=0,b=0,sum=0;

		scanf("%d", &a);
		while(a>0){
			b=a%10;
			a=(a-b)/10;
			sum=sum+b;
				
		
		}
			sum==10?printf("%s ", "YES"):printf("%s ", "NO");			
		
	return 0;
}


