#include <stdio.h>


 void convers( )
 {
	int arr[10];

	int a=0;

	for(int i=0;i<10;i++)
	{
		scanf("%d",&arr[i]);

		
	}
			a = arr[9];

	for (int i=9;i>=0;i--)
	{


			arr[i]=arr[i-1];

			if(i==0)
			{
				arr[0]=a;
			}
		
	}
	
		for (int i=0;i<10;i++)
		{
			printf("%d ",arr[i]);
		}

 }
	
	
int main()
{
	
	convers();
	
	return 0;
}


