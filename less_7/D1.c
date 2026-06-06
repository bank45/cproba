#include <stdio.h>


 void recurs(int n)
 {
		 
	 if(n>0)
	 {
		recurs(n-1);
		printf("%d ",n);					
	}
	 
 }
	
	
int main()
{
	int n=0;
	scanf("%d",&n);
	recurs(n);

	return 0;
}


