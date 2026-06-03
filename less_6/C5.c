#include <stdio.h>



 int foo(int n)
{
	int coun=0,sum=0;
	
	while(coun<=n)
	{

		sum=sum+coun;
		coun++;
	}
	

	return sum;
}

int main()
{
	
	int a=0,sum=0;

		scanf("%d", &a);

		sum=foo(a);

	printf("%d ", sum);			
		
	return 0;
}


