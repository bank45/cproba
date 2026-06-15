#include <stdio.h>


 int min( )
 {
	int arr[10];

	int sum=0;
	for(int i=0;i<10;i++)
	{
		scanf("%d",&arr[i]);

		
	}


	for (int i=0;i<10;i++)
	{
		if(arr[i] >0)
		{
			sum = sum + arr[i];


		}

		
	}


	return sum;
 }
	
	
int main()
{
	
	printf("%d",min());
	
	return 0;
}


