#include <stdio.h>


 void min( )
 {
	int arr[10];

	int max=0;	
	int pos1=0;
	int min=0;
	int pos2=0;
	//~ int b=0;
	for(int i=0;i<10;i++)
	{
		scanf("%d",&arr[i]);

		
	}
	max = arr[0];	
	pos1=1;
	min = arr[0];
	pos2=1;
	//~ int l =len(arr);
	for (int i=0;i<10;i++)
	{
		if(arr[i]>max)
		{
			max = arr[i];
			pos1=i+1;
		}
		if (arr[i] <min)
		{
			min =arr[i];
			pos2=i+1;
		}
		
	}

	printf("%d %d %d %d",pos1,max,pos2,min);

 }
	
	
int main()
{
	
	min();
	
	return 0;
}


