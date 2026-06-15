#include <stdio.h>


 void min( )
 {
	int arr[5];
	int min=0;
	//~ int b=0;
	for(int i=0;i<5;i++)
	{
		scanf("%d",&arr[i]);

		
	}
	min = arr[0];
	//~ int l =len(arr);
	for (int i=0;i<5;i++)
	{
		//~ b=arr[i];
		if (arr[i] < min)
		min =arr[i];
		
	}

	printf("%d",min);

 }
	
	
int main()
{
	
	min();
	
	return 0;
}


