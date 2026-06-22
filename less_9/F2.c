

#include <stdio.h>


 
  void print_arr(int size, int a[])
 {
	 for(size_t i=0; i<size;i++)
	 {
		 printf("%3d ",a[i]);

	 }
		 printf("\n");
 }


 
void sort_even_odd(int n, int a[])
{
	int a1=0;
	int a2=0;
	
	int b=0;
	 int chet_1=0;
	 int chet_2=0;
	 int i=0;
	 int coun=0;
	 while(i<(n-1)&& coun <n)
	 {
		a1 = a[i];
		a2 = a[i+1];
		 
		 if(a1<a2)
		 {
			 b=a[i];
			 a[i]=a[i+1];	
			 a[i+1]=b;

		 } 
		 		 i++;
		 if(i==(n-1))
		 {
			 coun++;
			 i=0;
		 }
	 }
	 
	 	 coun=0;
	 	 while(i<(n-1)&& coun <n)
	 {
		chet_1 = a[i]>0?a[i]%2:(a[i]*-1)%2;
		chet_2 = a[i+1]>0?a[i+1]%2:(a[i+1]*-1)%2;
		if(chet_1>chet_2)
		{
			b=a[i];
			 a[i]=a[i+1];	
			 a[i+1]=b;
		}
		i++;
		 if(i==(n-1))
		 {
			 coun++;
			 i=0;
		 }
	 }
	print_arr(21, a);
	 			 printf("2.\n");
}


 //~ void chet(int n, int a[])
 //~ {
	 //~ int b=0;
	 //~ int chet_1=0;
	 //~ int chet_2=0;
	 //~ int i=0;
	 //~ int coun=0;
	 //~ while(i<(n-1)&& coun <n)
	 //~ {
		 
		//~ chet_1 = a[i]>0?a[i]%2:(a[i]*-1)%2;
		//~ chet_2 = a[i+1]>0?a[i+1]%2:(a[i+1]*-1)%2;
		//~ if(chet_1>chet_2)
		//~ {
			//~ b=a[i];
			 //~ a[i]=a[i+1];	
			 //~ a[i+1]=b;
		//~ }
		//~ i++;
		 //~ if(i==(n-1))
		 //~ {
			 //~ coun++;
			 //~ i=0;
		 //~ }
	 //~ }
	 //~ print_arr(n, a);

 //~ }



int main(int argc, char **argv)
{
	//~ int arr[] = {20, 19, 4, 3, 2, 1, 18, 17, 13, 12, 11, 16, 15, 14, 10, 9, 8, 7, 6, 5};
	int arr[] = {20, 11, 25, 5, -48, -15, -16, 27, 43, -22, -1, -39, -16, -28, 28, -31, -36, 17, 17, -39, -50};
	//~ int arr[] = {1,0,1,0,1};
	print_arr(21, arr);
			 printf("1.\n");

	sort_even_odd(21, arr);
	//~ chet(20,arr);
		//~ sort_array(20, arr);
	return 0;
}

