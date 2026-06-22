

#include <stdio.h>


 
  void print_arr(int size, int a[])
 {
	 for(size_t i=0; i<size;i++)
	 {
		 printf("%d ",a[i]);
	 }

 }
 

 void sort_array(int size, int a[])
 {
	 int b=0;
	 int i=0;
	 int coun=0;
	 while(i<(size-1)&& coun <size)
	 {

		 if(a[i]>a[i+1])
		 {
			 b=a[i];
			 a[i]=a[i+1];	
			 a[i+1]=b;

		 } 

		 i++;
		 if(i==(size-1))
		 {
			 coun++;
			 i=0;
		 }
	 }
	 print_arr(size, a);
	 
 }



int main(int argc, char **argv)
{
	int arr[] = {20, 19, 4, 3, 2, 1, 18, 17, 13, 12, 11, 16, 15, 14, 10, 9, 8, 7, 6, 5};
	//~ print_arr(20, arr);
	sort_array(20, arr);
	
		//~ sort_array(20, arr);
	return 0;
}

