#include <stdio.h>


 void recurs(int n, int sum)
 {

	 if(n>0)
	 {
		sum=sum+n;			 
		recurs(n-1,sum);

	}else{
		printf("%d ",sum);	
	}
		 
 }
	
	
int main()
{
	int n=0,sum=0;
	scanf("%d",&n);
	recurs(n,sum);

	return 0;
}


