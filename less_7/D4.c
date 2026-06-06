#include <stdio.h>


 void recurs(int n, int sum)
 {

	 if(n>0)
	 {
		
		sum=n%10;
		

		n=(n-sum)/10;			 
		recurs(n,sum);
		printf("%d ",sum);		

	}
		 
 }
	
	
int main()
{
	int n=0,sum=0;
	scanf("%d",&n);
	n==0?printf("%d ",sum):recurs(n,sum);

	return 0;
}


