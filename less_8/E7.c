#include <stdio.h>


 void convers( )
 {
	int arr[10];

	int a=0;
	int coun_a=4;
	int b=0;
	int coun_b=9;
	for(int i=0;i<10;i++)
	{
		scanf("%d",&arr[i]);

		
	}


	for (int i=0;i<2;i++)
	{


			
			a = arr[i];
			//~ printf("arr[i]: %d \n",arr[i]);			
			arr[i]=arr[coun_a];
			//~ printf("arr[i]: %d \n",arr[i]);		
			//~ printf("arr[coun_a]: %d \n",arr[coun_a]);	
			arr[coun_a]=a;
						//~ printf("arr[coun_a]: %d \n",arr[coun_a]);	
			coun_a--;
			
			b = arr[i+5];
			arr[i+5]=arr[coun_b];
			arr[coun_b]=b;
			coun_b--;
		
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


