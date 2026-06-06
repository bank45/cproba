#include <stdio.h>


 void recurs( int i)
 {

	 if(i>0)
	 {
					
		printf("%d ",i);			
			
		recurs(i-1);


	}
		 
 }
	
	
int main()
{
	int i=0;

	scanf("%d",&i);
	if(i!=0) recurs(i);

	return 0;
}


