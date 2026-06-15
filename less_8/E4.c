#include <stdio.h>


 int min( )
 {
	int arr[10];
	int max2=0;	
	int max1=0;
	int sum=0;
	for(int i=0;i<10;i++)
	{
		scanf("%d",&arr[i]);

		
	}
	max2 = arr[0];	

	for (int i=0;i<10;i++)
	{
		if(arr[i] >= max2 && i > 0)
		{
			max1 = max2;
			max2 = arr[i];

		}
		if(arr[i]<max2 && arr[i]>max1)
		{
			
			max1 = arr[i];
		}

		
	}
	sum= max1 + max2;

	return sum;
 }
	
	
int main()
{
	
	printf("%d",min());
	
	return 0;
}


