#include <stdio.h>


 float avg( )
 {
	float arr[12];

	float sum=0;
	for(int i=0;i<12;i++)
	{
		scanf("%f",&arr[i]);

		
	}


	for (int i=0;i<12;i++)
	{
		if(arr[i]!=0)
			sum = sum + arr[i];

		
	}


	return sum/12;
 }
	
	
int main()
{
	
	printf("%.2f",avg());
	
	return 0;
}


